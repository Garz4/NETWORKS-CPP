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

#include "PaqueteDatagrama.h"
#include "Respuesta.h"

const Mensaje& Respuesta::pide() {
  PaqueteDatagrama paquete_recibo(sizeof(Mensaje));
  socket_local_.recibe(paquete_recibo);

  if (anterior_peticion_ == paquete_recibo.mensaje().id) {
    recibido_.tipo = 'n';
  } else {
    recibido_ = paquete_recibo.mensaje();
    ip_ = socket_local_.ip_foranea();
    puerto_ = socket_local_.puerto_foranea();
    anterior_peticion_ = recibido_.id;
  }

  return recibido_;
}

void Respuesta::responde(Mensaje respuesta) {
  enviar_ = std::move(respuesta);
  enviar_.tipo = '1';
  enviar_.id = recibido_.id;

  PaqueteDatagrama paquete_envio(enviar_, sizeof(Mensaje), ip_, htons(puerto_));

  socket_local_.envia(paquete_envio);
}
