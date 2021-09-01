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

#pragma once

#include "Mensaje.h"
#include "SocketDatagrama.h"

class Solicitud final {
 public:
  explicit Solicitud() noexcept = default;

  /* Retorna el mensaje recibido. */
  const Mensaje& envia_y_recibe(
      const std::string& ip, unsigned short puerto, const Mensaje& solicitud);

 private:
  SocketDatagrama socket_local_{0};
  Mensaje recibido_;
  Mensaje enviar_;
  int peticion_ = 0;
};
