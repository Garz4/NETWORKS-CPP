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

#include <iostream>
#include "Solicitud.h"
#include "PaqueteDatagrama.h"

using namespace std;

Solicitud::Solicitud() {
  socketLocal = new SocketDatagrama(0);
  request = 0;
}

char* Solicitud::doOperation(char *IP, int puerto, char* solicitud) {
  memcpy((char*)&Enviar, solicitud, sizeof(struct mensaje));
  Enviar.messageType = '0';
  Enviar.requestId = request;

  PaqueteDatagrama paqueteEnvio(
      (char*)&Enviar, sizeof(struct mensaje), IP, puerto);

  PaqueteDatagrama paqueteRecibo(sizeof(struct mensaje));
  int n;

  for (int it = 0; it < 20; it++) {
    socketLocal->envia(paqueteEnvio);
    n = socketLocal->recibeTimeout(paqueteRecibo, 2, 500000);

    if (n == -1) {
      if (it != 19) {
        cout << "No se recibió ningún mensaje. Intentando de nuevo..." << endl;
      } else {
        cout << "--!! ADVERTENCIA: Servidor no disponible." << endl;
        cout << "Imposible contactar con el servidor."
             << "Inténtelo de nuevo más tarde." << endl;
        exit(0);
      }
    } else if (n == -2) {
      cout << "--!! ERROR: Error en recvfrom." << endl;
      exit(0);
    } else {
      if (
          ((struct mensaje*)(paqueteRecibo.datos()))->messageType !=
          '1') {
        cout << "No se recibió el tipo de mensaje adecuado." << endl;
        exit(0);
      } else if (
          ((struct mensaje*)(paqueteRecibo.datos()))->requestId !=
          ((struct mensaje*)(paqueteEnvio.datos()))->requestId) {
        cout << "No se recibió el ID adecuado." << endl;
        exit(0);
      } else {
        memcpy(
            (char*)&Recibido,
            paqueteRecibo.datos(),
            sizeof(struct mensaje));
        dirIP = socketLocal->getClientIP();
        request++;
      }

      break;
    }
  }

  return (char*)&Recibido;
}

Solicitud::~Solicitud() { delete socketLocal; }

char* Solicitud::getIP() { return dirIP; }
