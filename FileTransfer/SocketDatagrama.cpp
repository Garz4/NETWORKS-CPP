/*
 * MIT License
 *
 * Copyright (c) 2024 Uriel Rivas
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * https://github.com/zoningorg/zoning/blob/main/LICENSE
 */

#include "PaqueteDatagrama.h"
#include "SocketDatagrama.h"

SocketDatagrama::SocketDatagrama(unsigned short puerto) {
  socket_ = socket(AF_INET, SOCK_DGRAM, 0);

  bzero(reinterpret_cast<char*>(&direccion_local_), sizeof(direccion_local_));

  direccion_local_.sin_family = AF_INET;
  direccion_local_.sin_addr.s_addr = INADDR_ANY;
  direccion_local_.sin_port = htons(puerto);

  bind(
      socket_,
      reinterpret_cast<sockaddr*>(&direccion_local_),
      sizeof(direccion_local_));

  bzero(
      reinterpret_cast<char*>(&direccion_foranea_), sizeof(direccion_foranea_));
  direccion_foranea_.sin_family = AF_INET;
}

int SocketDatagrama::recibe(PaqueteDatagrama& paquete) {
  char dat[paquete.longitud()];
  unsigned int clileng = sizeof(direccion_foranea_);

  recvfrom(
      socket_,
      dat,
      paquete.longitud() * sizeof(char),
      0,
      reinterpret_cast<sockaddr*>(&direccion_foranea_),
      &clileng);

  paquete.set_mensaje(dat);
  char str[16];
  inet_ntop(AF_INET, &direccion_foranea_.sin_addr.s_addr, str, 16);
  paquete.set_ip(str);
  ip_foranea_ = paquete.ip();
  paquete.set_puerto(direccion_foranea_.sin_port);

  return 0;
}

int SocketDatagrama::recibe(
    PaqueteDatagrama& paquete, time_t segundos, suseconds_t microsegundos) {
  timeout_.tv_sec = segundos;
  timeout_.tv_usec = microsegundos;

  setsockopt(
      socket_,
      SOL_SOCKET,
      SO_RCVTIMEO,
      reinterpret_cast<char*>(&timeout_),
      sizeof(timeout_));

  char dat[paquete.longitud()];
  unsigned int clileng = sizeof(direccion_foranea_);

  if (recvfrom(
          socket_,
          dat,
          paquete.longitud() * sizeof(char),
          0,
          reinterpret_cast<sockaddr*>(&direccion_foranea_),
          &clileng)) {
    if (errno == EWOULDBLOCK) {
      fprintf(stderr, "Tiempo para recepción transcurrido.\n");
      return 1;
    } else {
      fprintf(stderr, "Error en recvfrom.\n");
      return 2;
    }
  }

  paquete.set_mensaje(dat);
  char str[16];
  inet_ntop(AF_INET, &direccion_foranea_.sin_addr.s_addr, str, 16);
  paquete.set_ip(str);
  ip_foranea_ = paquete.ip();
  paquete.set_puerto(direccion_foranea_.sin_port);

  return 0;
}

int SocketDatagrama::envia(const PaqueteDatagrama& paquete) {
  inet_pton(AF_INET, paquete.ip().c_str(), &direccion_foranea_.sin_addr);
  direccion_foranea_.sin_port = htons(paquete.puerto());

  sendto(
      socket_,
      paquete.datos(),
      paquete.longitud() * sizeof(char),
      0,
      reinterpret_cast<sockaddr*>(&direccion_foranea_),
      sizeof(direccion_foranea_));

  return 0;
}
