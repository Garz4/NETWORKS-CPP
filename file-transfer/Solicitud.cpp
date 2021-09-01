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

/* TODO(Garz4): Consider making Solicitud constexpr, moving this to header. */
const Mensaje& Solicitud::envia_y_recibe(
      const std::string& ip, unsigned short puerto, const Mensaje& solicitud) {
  enviar_ = solicitud;
  enviar_.tipo = '0';
  enviar_.id = peticion_;

  PaqueteDatagrama paquete_envio(enviar_, sizeof(Mensaje), ip, puerto);
  PaqueteDatagrama paquete_recibo(sizeof(Mensaje));
  int n;

  for (int it = 0; it < 20; it++) {
    socket_local_.envia(paquete_envio);
    n = socket_local_.recibe(paquete_recibo, 2, 500000);

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
      if (paquete_recibo.mensaje().tipo != '1') {
        std::printf("No se recibió el tipo de Mensaje adecuado.\n");
        std::exit(0);
      } else if (paquete_recibo.mensaje().id != paquete_envio.mensaje().id) {
        std::printf("No se recibió el ID adecuado.\n");
        std::exit(0);
      } else {
        recibido_ = paquete_recibo.mensaje();
        peticion_++;
      }

      break;
    }
  }

  return recibido_;
}
