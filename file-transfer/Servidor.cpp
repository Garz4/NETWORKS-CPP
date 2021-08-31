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
#include <fstream>
#include <string>
#include "Respuesta.h"

using namespace std;

int main(void) {
  Respuesta r(7200);
  struct mensaje mensajeEnvio;
  struct mensaje mensajeRecibo;

  ofstream archivoGuardar;
  char *archivoRecibo;

  while (1) {
    cout << "Esperando mensaje..." << endl;
    memcpy(&mensajeRecibo, r.getRequest(), sizeof(struct mensaje));

    if (mensajeRecibo.messageType != 'n') {
      cout << "==================================" << endl;
      cout << mensajeRecibo.nombreArchivo << ": ";

      archivoRecibo = new char[atoi(mensajeRecibo.tam)];
      memcpy(archivoRecibo, mensajeRecibo.archivo, atoi(mensajeRecibo.tam));
      archivoRecibo[atoi(mensajeRecibo.tam)] = '\0';
      archivoGuardar.open(mensajeRecibo.nombreArchivo);
      archivoGuardar.write(archivoRecibo, atoi(mensajeRecibo.tam));

      if (archivoGuardar.is_open()) {
        mensajeEnvio.estatus = '0';
        cout << "Guardado." << endl;
      } else {
        mensajeEnvio.estatus = '1';
        cout << "Fallo en escritura." << endl;
      }

      memcpy(
        mensajeEnvio.nombreArchivo,
        mensajeRecibo.nombreArchivo,
        sizeof(mensajeEnvio.nombreArchivo));

      archivoGuardar.close();
      delete[] archivoRecibo;
    }

    r.sendReply((char *)&mensajeEnvio);
  }

  return 0;
}
