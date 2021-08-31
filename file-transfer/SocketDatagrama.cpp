/*
 * MIT License
 * 
 * Copyright (c) 2021 Uriel Rivas
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * https://github.com/Garz4/zoning/blob/master/LICENSE
 */

#include <arpa/inet.h>
#include <errno.h>
#include <netdb.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <strings.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

#include "PaqueteDatagrama.h"
#include "SocketDatagrama.h"

SocketDatagrama::SocketDatagrama(int a) {
  socket_ = socket(AF_INET, SOCK_DGRAM, 0);

  bzero((char *)&direccion_local_, sizeof(direccion_local_));
  direccion_local_.sin_family = AF_INET;
  direccion_local_.sin_addr.s_addr = INADDR_ANY;
  direccion_local_.sin_port = htons(a);
  bind(socket_, (struct sockaddr *)&direccion_local_, sizeof(direccion_local_));

  bzero((char *)&direccion_foranea_, sizeof(direccion_foranea_));
  direccion_foranea_.sin_family = AF_INET;
}

SocketDatagrama::~SocketDatagrama() { close(socket_); }

int SocketDatagrama::recibe(PaqueteDatagrama& paquete) {
  char dat[paquete.longitud()];
  unsigned int clileng = sizeof(direccion_foranea_);

  recvfrom(
      socket_,
      dat,
      paquete.longitud()*sizeof(char),
      0,
      (struct sockaddr *) &direccion_foranea_,
      &clileng);

  paquete.set_datos(dat);
  char str[16];
  inet_ntop(AF_INET, &direccion_foranea_.sin_addr.s_addr, str, 16);
  paquete.set_ip(str);
  paquete.set_puerto(direccion_foranea_.sin_port);

  return 0;
}

int SocketDatagrama::envia(const PaqueteDatagrama& paquete) {
  inet_pton(AF_INET, paquete.ip(), &direccion_foranea_.sin_addr);
  direccion_foranea_.sin_port = htons(paquete.puerto());

  sendto(
      socket_,
      paquete.datos(),
      paquete.longitud() * sizeof(char),
      0,
      (struct sockaddr *) &direccion_foranea_,
      sizeof(direccion_foranea_));

  return 0;
}

int SocketDatagrama::recibeTimeout(
    PaqueteDatagrama &paquete, time_t segundos, suseconds_t microsegundos) {
  timeout_.tv_sec = segundos;
  timeout_.tv_usec = microsegundos;
  setsockopt(
      socket_, SOL_SOCKET, SO_RCVTIMEO, (char *)&timeout_, sizeof(timeout_));

  char dat[paquete.longitud()];
  unsigned int clileng = sizeof(direccion_foranea_);

  if (
      recvfrom(
          socket_,
          dat,
          paquete.longitud()*sizeof(char),
          0,
          (struct sockaddr *) &direccion_foranea_,
          &clileng) <
      0) {
    if (errno == EWOULDBLOCK) {
      fprintf(stderr, "Tiempo para recepción transcurrido.\n");
      return -1;
    } else {
      fprintf(stderr, "Error en recvfrom.\n");
      return -2;
    }
  }

  paquete.set_datos(dat);
  char str[16];
  inet_ntop(AF_INET, &direccion_foranea_.sin_addr.s_addr, str, 16);
  paquete.set_ip(str);
  paquete.set_puerto(direccion_foranea_.sin_port);

  return 0;
}

char* SocketDatagrama::ip_foranea() const {
  return inet_ntoa(direccion_foranea_.sin_addr);
}

unsigned short SocketDatagrama::puerto_foranea() const {
  return direccion_foranea_.sin_port;
}
