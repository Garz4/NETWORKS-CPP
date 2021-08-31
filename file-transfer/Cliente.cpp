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
#include <fstream>
#include <iostream>
#include <sstream>

#include "Solicitud.h"

int main(int argc, char** argv) {
  if (argc != 3) {
    std::printf("Modo de uso:\n");
    std::printf("%s direccion_ip_del_servidor nombre_del_archivo\n", argv[0]);
    return 1;
  } else if (std::strlen(argv[1]) > 16) {
    std::printf("--!! ERROR: IP inválida. Inténtelo de nuevo.\n");
    return 1;
  }

  Solicitud solicitud;
  Mensaje mensaje_envio;
  Mensaje mensaje_recibo;
  std::ifstream archivo_leer;
  std::ifstream archivo_enviar;
  std::string linea;
  int tam_archivo;
  std::string convertir;
  std::stringstream strs;

  archivo_leer.open(argv[2]);

  if (archivo_leer.is_open()) {
    while (std::getline(archivo_leer, linea)) {
      archivo_enviar.open(linea);

      if (archivo_enviar.is_open()) {
        archivo_enviar.seekg(0, std::ios::end);
        tam_archivo = archivo_enviar.tellg();
        strs << tam_archivo;
        convertir = strs.str();
        strs.str(std::string());

        for (int c = 0; c < convertir.length(); c++) {
          mensaje_envio.tam[c] = (convertir.c_str())[c];
        }

        mensaje_envio.tam[convertir.length()] = '\0';

        if (tam_archivo > LIMITE_ARCHIVO) {
          std::printf("==================================\n");
          std::printf("--!! ADVERTENCIA: %s pesa "
                      "%s bytes y sobrepasa el límite de %d bytes.\n",
                      linea.c_str(), mensaje_envio.tam, LIMITE_ARCHIVO);
          std::printf("El archivo será omitido.\n");
        } else {
          for (int k = 0; k < linea.length() + 1; k++) {
            mensaje_envio.nombre_archivo[k] = linea[k];
          }

          mensaje_envio.nombre_archivo[linea.length() + 1] = '\0';
          mensaje_envio.estatus = 0;
          archivo_enviar.seekg(0, std::ios::beg);
          archivo_enviar.read(mensaje_envio.contenido_archivo, tam_archivo);
          std::memcpy(
              reinterpret_cast<char*>(&mensaje_recibo),
              solicitud.envia_y_recibe(
                  argv[1], 7200, reinterpret_cast<char*>(&mensaje_envio)),
              sizeof(Mensaje));

          std::printf("==================================\n");
          std::printf("%s: ", mensaje_recibo.nombre_archivo);

          if (mensaje_recibo.estatus == 0) {
            std::printf("Recibido.\n");
          } else {
            std::printf("Error al recibir.\n");
          }
        }

        archivo_enviar.close();
      } else {
        std::printf("==================================\n");
        std::printf(
            "--!! ADVERTENCIA: Error al abrir %s.\n", linea.c_str());
        std::printf("El archivo será omitido.\n");
      }
    }

    archivo_leer.close();
  } else {
    std::printf("--!! ERROR: Error al abrir %s.\n", argv[2]);
  }

  return 0;
}
