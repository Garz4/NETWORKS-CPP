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

char* Solicitud::envia_y_recibe(
      std::string ip, int puerto, const char* solicitud) {
  std::memcpy((char*)&enviar_, solicitud, sizeof(Mensaje));
  enviar_.tipo = '0';
  enviar_.id = peticion_;

  PaqueteDatagrama paquete_envio(
      (char*)&enviar_, sizeof(Mensaje), ip, puerto);

  PaqueteDatagrama paquete_recibo(sizeof(Mensaje));
  int n;

  for (int it = 0; it < 20; it++) {
    socket_local_->envia(paquete_envio);
    n = socket_local_->recibe(paquete_recibo, 2, 500000);

    if (n == -1) {
      if (it != 19) {
        std::printf("No se recibió ningún Mensaje. Intentando de nuevo...\n");
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
      if (((Mensaje*)(paquete_recibo.datos()))->tipo != '1') {
        std::printf("No se recibió el tipo de Mensaje adecuado.\n");
        std::exit(0);
      } else if (
          ((Mensaje*)(paquete_recibo.datos()))->id !=
          ((Mensaje*)(paquete_envio.datos()))->id) {
        std::printf("No se recibió el ID adecuado.\n");
        std::exit(0);
      } else {
        std::memcpy((char*)&recibido_, paquete_recibo.datos(), sizeof(Mensaje));
        ip_ = socket_local_->ip_foranea();
        peticion_++;
      }

      break;
    }
  }

  return (char*)&recibido_;
}
