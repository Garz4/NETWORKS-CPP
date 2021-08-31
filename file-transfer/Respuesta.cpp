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

#include "PaqueteDatagrama.h"
#include "Respuesta.h"

using namespace std;

int flipBit(int bit);

Respuesta::Respuesta(int pl) {
  socketLocal = new SocketDatagrama(pl);
  requestIdPrev = 'n';
}

struct mensaje* Respuesta::getRequest(void) {
  PaqueteDatagrama paqueteRecibo(sizeof(struct mensaje));
  socketLocal->recibe(paqueteRecibo);
  if (requestIdPrev ==
      ((struct mensaje*)(paqueteRecibo.datos()))->requestId) {
    Recibido.messageType = 'n';
    return &Recibido;
  } else {
    memcpy((char*)&Recibido, paqueteRecibo.datos(),
        sizeof(struct mensaje));
    dirIP = socketLocal->ip_foranea();
    port = (int)(socketLocal->puerto_foranea());
    requestIdPrev = Recibido.requestId;
    return &Recibido;
  }
}

void Respuesta::sendReply(char *respuesta) {
  memcpy((char*)&Enviar, respuesta, sizeof(struct mensaje));
  Enviar.messageType = '1';
  Enviar.requestId = Recibido.requestId;

  PaqueteDatagrama paqueteEnvio(
      (char*)&Enviar, sizeof(struct mensaje), dirIP, htons(port));

  socketLocal->envia(paqueteEnvio);
  return;
}

Respuesta::~Respuesta() { delete socketLocal; }

char* Respuesta::getIP() { return dirIP; }
int Respuesta::getPort() { return port; }

int flipBit(int bit) {
  if (bit == 0) {
    return 1;
  }

  return 0;
}
