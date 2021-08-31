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

#include <cstring>
#include <iostream>

#include "PaqueteDatagrama.h"
#include "Solicitud.h"

Solicitud::Solicitud() {
  socket_local_ = new SocketDatagrama(0);
  peticion_ = 0;
}

char* Solicitud::envia_y_recibe(
      const char* ip, int puerto, const char* solicitud) {
  std::memcpy((char*)&enviar_, solicitud, sizeof(mensaje));
  enviar_.messageType = '0';
  enviar_.requestId = peticion_;

  PaqueteDatagrama paquete_envio(
      (char*)&enviar_, sizeof(mensaje), ip, puerto);

  PaqueteDatagrama paquete_recibo(sizeof(mensaje));
  int n;

  for (int it = 0; it < 20; it++) {
    socket_local_->envia(paquete_envio);
    n = socket_local_->recibe(paquete_recibo, 2, 500000);

    if (n == -1) {
      if (it != 19) {
        std::printf("No se recibió ningún mensaje. Intentando de nuevo...\n");
      } else {
        std::printf("--!! ADVERTENCIA: Servidor no disponible.\n");
        std::printf("Imposible contactar con el servidor."
                    "Inténtelo de nuevo más tarde.\n");
        std::exit(0);
      }
    } else if (n == -2) {
      std::printf("--!! ERROR: Error en recvfrom.\n");
      std::exit(0);
    } else {
      if (((mensaje*)(paquete_recibo.datos()))->messageType != '1') {
        std::printf("No se recibió el tipo de mensaje adecuado.\n");
        std::exit(0);
      } else if (
          ((mensaje*)(paquete_recibo.datos()))->requestId !=
          ((mensaje*)(paquete_envio.datos()))->requestId) {
        std::printf("No se recibió el ID adecuado.\n");
        std::exit(0);
      } else {
        std::memcpy(
            (char*)&recibido_,
            paquete_recibo.datos(),
            sizeof(mensaje));
        ip_ = socket_local_->ip_foranea();
        peticion_++;
      }

      break;
    }
  }

  return (char*)&recibido_;
}

Solicitud::~Solicitud() { delete socket_local_; }

char* Solicitud::ip() const { return ip_; }
