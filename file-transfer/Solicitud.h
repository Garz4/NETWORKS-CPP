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

#ifndef SOLICITUD_H_
#define SOLICITUD_H_

#include "Mensaje.h"
#include "SocketDatagrama.h"

class Solicitud {
 public:
  Solicitud() : socket_local_(new SocketDatagrama(0)), peticion_(0) {}

  ~Solicitud() { delete socket_local_; }

  char* envia_y_recibe(
      const std::string& ip, int puerto, const char* solicitud);

  const std::string& ip() const noexcept { return ip_; }

 private:
  SocketDatagrama* socket_local_;
  Mensaje recibido_;
  Mensaje enviar_;
  std::string ip_;
  char peticion_;
};

#endif
