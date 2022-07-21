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

#include "Mensaje.h"
#include "SocketDatagrama.h"

class Solicitud final {
 public:
  explicit Solicitud() noexcept = default;
  explicit Solicitud(const Solicitud&) noexcept = default;

  /*
   * Retorna el mensaje recibido.
   *
   * @exception
   *  - runtime_error: Servidor no está disponible.
   *  - runtime_error: recvfrom(...) retornó con errores.
   *  - invalid_argument: Tipo de Mensaje inadecuado.
   *  - invalid_argument: ID inadecuado.
   */
  const Mensaje& envia_y_recibe(
      const std::string& ip, unsigned short puerto, const Mensaje& solicitud);

 private:
  SocketDatagrama socket_local_;
  Mensaje recibido_;
  Mensaje enviar_;
  int peticion_ = 0;
};
