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

class PaqueteDatagrama {
 public:
  // PaqueteDatagrama() noexcept = default;
  // PaqueteDatagrama(const PaqueteDatagrama&) noexcept = default;

  PaqueteDatagrama(
      const char* datos,
      unsigned int longitud,
      std::string ip,
      int puerto) /* noexcept */
      : /* datos_(datos), */
       longitud_(longitud),
       ip_(std::move(ip)),
       puerto_(puerto) {
    datos_ = new char[longitud];
    std::memcpy(datos_, datos, longitud);
  }

  PaqueteDatagrama(unsigned int longitud) noexcept : longitud_(longitud) {
    datos_ = new char[longitud];
  }

  ~PaqueteDatagrama() { delete[] datos_; }

  const std::string& ip() const noexcept { return ip_; }
  void set_ip(std::string ip) { ip_ = std::move(ip); }

  int puerto() const noexcept { return puerto_; }
  void set_puerto(int puerto) { puerto_ = puerto; }

  const char* datos() const noexcept { return datos_; }
  void set_datos(const char* datos) { std::memcpy(datos_, datos, longitud_); }

  unsigned int longitud() const noexcept { return longitud_; }

 private:
  std::string ip_;
  int puerto_;

  /* Cadena de datos a enviar en bytes. */
  char* datos_;

  /* Longitud de la cadena de datos a enviar. */
  unsigned int longitud_;
};

#endif
