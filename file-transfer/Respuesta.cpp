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

#include "PaqueteDatagrama.h"
#include "Respuesta.h"

Respuesta::Respuesta(int pl) {
  socket_local_ = new SocketDatagrama(pl);
  anterior_peticion_ = 'n';
}

Respuesta::~Respuesta() { delete socket_local_; }

mensaje* Respuesta::pide() {
  PaqueteDatagrama paquete_recibo(sizeof(mensaje));
  socket_local_->recibe(paquete_recibo);
  if (anterior_peticion_ ==
      ((mensaje*)(paquete_recibo.datos()))->requestId) {
    recibido_.messageType = 'n';
    return &recibido_;
  } else {
    std::memcpy((char*)&recibido_, paquete_recibo.datos(),
        sizeof(mensaje));
    ip_ = socket_local_->ip_foranea();
    puerto_ = (int)(socket_local_->puerto_foranea());
    anterior_peticion_ = recibido_.requestId;
    return &recibido_;
  }
}

void Respuesta::responde(const char* respuesta) {
  std::memcpy((char*)&enviar_, respuesta, sizeof(mensaje));
  enviar_.messageType = '1';
  enviar_.requestId = recibido_.requestId;

  PaqueteDatagrama paquete_envio(
      (char*)&enviar_, sizeof(mensaje), ip_, htons(puerto_));

  socket_local_->envia(paquete_envio);
}

char* Respuesta::ip() const { return ip_; }
int Respuesta::puerto() const { return puerto_; }
