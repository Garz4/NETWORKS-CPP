/*
 * MIT License
 *
 * Copyright (c) 2022 Uriel Rivas
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

#pragma once

/* Limite en bytes de los paquetes. */
#define LIMITE_ARCHIVO 65000

struct Mensaje {
  /* 0 = Solicitud, 1 = Respuesta. */
  char tipo;

  char id;

  /* Tamaño en bytes del archivo a enviar. */
  char tam[5];

  char nombre_archivo[30];

  /* 1 extra para... Abarcar "\0" ? */
  char contenido_archivo[LIMITE_ARCHIVO + 1];

  /* 0 = Ok, 1 = Error. */
  char estatus;
};
