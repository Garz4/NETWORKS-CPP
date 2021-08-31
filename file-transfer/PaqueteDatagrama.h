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

class PaqueteDatagrama {
 private:
  char ip_[16];
  int puerto_;

  /* Cadena de datos a enviar en bytes. */
  char* datos_;

  /* Longitud de la cadena de datos a enviar. */
  unsigned int longitud_;

 public:
  PaqueteDatagrama(
      const char* datos, unsigned int longitud, const char* ip, int puerto);
  PaqueteDatagrama(unsigned int longitud);
  ~PaqueteDatagrama();

  const char* ip() const;
  void set_ip(const char*);

  const unsigned int longitud() const;

  int puerto() const;
  void set_puerto(int);

  const char* datos() const;
  void set_datos(const char*);
};

#endif
