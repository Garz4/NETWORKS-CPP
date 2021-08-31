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

#ifndef SOCKETDATAGRAMA_H_
#define SOCKETDATAGRAMA_H_
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <strings.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include "PaqueteDatagrama.h"

class SocketDatagrama {
  private:
    struct sockaddr_in direccionLocal;
    struct sockaddr_in direccionForanea;
    struct timeval timeout;
    int s; //ID socket

  public:
    SocketDatagrama(int a);
    ~SocketDatagrama();

    //Recibe un paquete tipo datagrama proveniente de este socket
    int recibe(PaqueteDatagrama &p);

    //Envía un paquete tipo datagrama desde este socket
    int envia(PaqueteDatagrama &p);

    char* getClientIP();
    unsigned short getClientPort();
    int recibeTimeout(
        PaqueteDatagrama &p, time_t segundos, suseconds_t microsegundos);
};

#endif
