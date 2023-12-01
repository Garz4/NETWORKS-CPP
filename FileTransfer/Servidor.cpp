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

#include <fstream>

#include "Respuesta.h"

int main(int, char**) {
  Respuesta respuesta(7200);
  Mensaje mensaje_envio;
  Mensaje mensaje_recibo;

  std::ofstream archivo_guardar;

  while (true) {
    std::printf("Esperando mensaje...\n");
    std::memcpy(&mensaje_recibo, &respuesta.pide(), sizeof(Mensaje));

    if (mensaje_recibo.tipo != 'n') {
      std::printf("==================================\n");
      std::printf("%s: ", mensaje_recibo.nombre_archivo);

      int tam = std::atoi(mensaje_recibo.tam);

      /* TODO(Garz4): Consider using std::ofstream(...) << ...; instead. */
      archivo_guardar.open(mensaje_recibo.nombre_archivo);
      archivo_guardar.write(mensaje_recibo.contenido_archivo, tam);

      if (archivo_guardar.is_open()) {
        mensaje_envio.estatus = 0;
        std::printf("Guardado.\n");
      } else {
        mensaje_envio.estatus = 1;
        std::printf("Fallo en escritura.\n");
      }

      std::memcpy(
        mensaje_envio.nombre_archivo,
        mensaje_recibo.nombre_archivo,
        sizeof(mensaje_envio.nombre_archivo));

      archivo_guardar.close();
    }

    respuesta.responde(mensaje_envio);
  }

  return 0;
}
