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
#include <iostream>
#include <string.h>

#include "PaqueteDatagrama.h"

PaqueteDatagrama::PaqueteDatagrama(
    const char* datos, unsigned int longitud, const char* ip, int puerto) {
  std::strcpy(ip_, ip);
  datos_ = new char[longitud];
  std::memcpy(datos_, datos, longitud);
  longitud_ = longitud;
  puerto_ = puerto;
}

PaqueteDatagrama::PaqueteDatagrama(unsigned int longitud) {
  longitud_ = longitud;
  datos_ = new char[longitud];
}

PaqueteDatagrama::~PaqueteDatagrama() {
  delete[] datos_;
}

const char* PaqueteDatagrama::ip() const { return ip_; }
void PaqueteDatagrama::set_ip(const char* ip) { std::strcpy(ip_, ip); }

const unsigned int PaqueteDatagrama::longitud() const { return longitud_; }

int PaqueteDatagrama::puerto() const { return puerto_; }
void PaqueteDatagrama::set_puerto(int puerto) { puerto_ = puerto; }

const char* PaqueteDatagrama::datos() const { return datos_; }
void PaqueteDatagrama::set_datos(const char* datos) {
  std::memcpy(datos_, datos, longitud_);
}
