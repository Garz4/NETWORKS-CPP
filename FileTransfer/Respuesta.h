/*
 * MIT License
 *
 * Copyright (c) 2024 Uriel García Rivas
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

#include <string>

#include "Mensaje.h"
#include "SocketDatagrama.h"

class Respuesta final {
 public:
  explicit Respuesta() noexcept = default;
  explicit Respuesta(const Respuesta&) noexcept = default;

  Respuesta(unsigned short puerto_local) noexcept
      : socket_local_(puerto_local), anterior_peticion_('n') {}

  /* Espera hasta que recibe mensaje, lo copia a recibido_ y lo retorna. */
  const Mensaje& pide();

  /* Responde a la IP que recibe en pide(). */
  void responde(Mensaje respuesta);

 private:
  SocketDatagrama socket_local_;
  Mensaje recibido_;
  Mensaje enviar_;
  std::string ip_;
  unsigned short puerto_;
  int anterior_peticion_;
};
