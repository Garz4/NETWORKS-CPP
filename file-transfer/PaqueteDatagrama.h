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

#ifndef PAQUETEDATAGRAMA_H_
#define PAQUETEDATAGRAMA_H_

#include <cstring>
#include <string>
#include <utility>

#include "Mensaje.h"

class PaqueteDatagrama final {
 public:
  explicit PaqueteDatagrama() noexcept = default;
  explicit PaqueteDatagrama(const PaqueteDatagrama&) noexcept = default;

  explicit PaqueteDatagrama(
      Mensaje mensaje,
      size_t longitud,
      std::string ip,
      int puerto) noexcept
      : mensaje_(std::move(mensaje)),
       longitud_(longitud),
       ip_(std::move(ip)),
       puerto_(puerto) {}

  explicit PaqueteDatagrama(size_t longitud) noexcept : longitud_(longitud) {}

  const std::string& ip() const noexcept { return ip_; }
  void set_ip(std::string ip) { ip_ = std::move(ip); }

  int puerto() const noexcept { return puerto_; }
  void set_puerto(int puerto) { puerto_ = puerto; }

  const char* datos() const {
    return reinterpret_cast<char*>(const_cast<Mensaje*>(&mensaje_));
  }
  const Mensaje& mensaje() const noexcept { return mensaje_; }
  void set_mensaje(char* datos) {
    std::memcpy(
        &mensaje_,
        reinterpret_cast<Mensaje*>(datos),
        longitud_);
  }

  size_t longitud() const noexcept { return longitud_; }

 private:
  std::string ip_;
  int puerto_;
  Mensaje mensaje_;
  size_t longitud_;
};

#endif
