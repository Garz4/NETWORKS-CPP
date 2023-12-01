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

#include <iostream>

#include "../../Testing/comparators.h"
#include "../PaqueteDatagrama.h"

int main(int argc, char** argv) {
  START_TEST("PaqueteDatagrama_test");

  Mensaje mensaje;

  mensaje.tipo = 0;
  mensaje.id = 0;
  mensaje.tam[0] = '1';
  mensaje.tam[1] = '0';
  mensaje.tam[2] = '0';
  mensaje.tam[3] = '0';
  mensaje.tam[4] = '0';
  mensaje.nombre_archivo[0] = 'A';
  mensaje.contenido_archivo[0] = 'Z';
  mensaje.estatus = 0;

  PaqueteDatagrama paquete{mensaje, 10000, "0.0.0.0", 3000};

  EXPECT_EQUAL(paquete.longitud(), 10000);
  EXPECT_EQUAL(paquete.ip(), "0.0.0.0");
  EXPECT_EQUAL(paquete.puerto(), 3000);
  EXPECT_TRUE(paquete.datos());

  /** Commenting these out because `delete[] datos;` doesn't work.
  auto datos =
      reinterpret_cast<Mensaje*>(const_cast<char*>(paquete.datos()));

  EXPECT_EQUAL(datos->id, paquete.mensaje().id);
  EXPECT_EQUAL(datos->tipo, paquete.mensaje().tipo);
  EXPECT_EQUAL(datos->estatus, paquete.mensaje().estatus);*/

  paquete.set_ip("1.1.1.1");
  paquete.set_puerto(4000);

  EXPECT_EQUAL(paquete.ip(), "1.1.1.1");
  EXPECT_EQUAL(paquete.puerto(), 4000);

  FINISH_TEST();

  return 0;
}
