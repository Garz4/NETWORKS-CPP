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

#ifndef RESPUESTA_H_
#define RESPUESTA_H_
#include "SocketDatagrama.h"
#include <string.h>
#include "Mensaje.h"

class Respuesta {
  public:
    ~Respuesta();
    Respuesta(int pl);
    struct mensaje* getRequest(void);
    void sendReply(char *respuesta);
    char* getIP();
    int getPort();
  private:
    SocketDatagrama *socketLocal;
    struct mensaje Recibido;
    struct mensaje Enviar;
    char* dirIP;
    int port;
    int requestIdPrev;
};

#endif
