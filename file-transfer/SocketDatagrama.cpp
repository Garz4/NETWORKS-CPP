#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <strings.h>
#include <stdio.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include "SocketDatagrama.h"
#include "PaqueteDatagrama.h"

using namespace std;

SocketDatagrama::SocketDatagrama(int a) {
  s = socket(AF_INET, SOCK_DGRAM, 0);

  bzero((char *)&direccionLocal, sizeof(direccionLocal));
  direccionLocal.sin_family = AF_INET;
  direccionLocal.sin_addr.s_addr = INADDR_ANY;
  direccionLocal.sin_port = htons(a);
  bind(s, (struct sockaddr *)&direccionLocal, sizeof(direccionLocal));

  bzero((char *)&direccionForanea, sizeof(direccionForanea));
  direccionForanea.sin_family = AF_INET;
}

SocketDatagrama::~SocketDatagrama() {
  close(s);
}

int SocketDatagrama::recibe(PaqueteDatagrama &p) {
  char dat[p.longitud()];
  unsigned int clileng = sizeof(direccionForanea);

  recvfrom(
      s,
      dat,
      p.longitud()*sizeof(char),
      0,
      (struct sockaddr *) &direccionForanea,
      &clileng);

  p.set_datos(dat);
  char str[16];
  inet_ntop(AF_INET, &direccionForanea.sin_addr.s_addr, str, 16);
  p.set_ip(str);
  p.set_puerto(direccionForanea.sin_port);

  return 0;
}

int SocketDatagrama::envia(PaqueteDatagrama &p) {
  inet_pton(AF_INET, p.ip(), &direccionForanea.sin_addr);
  direccionForanea.sin_port = htons(p.puerto());

  sendto(
      s,
      p.datos(),
      p.longitud() * sizeof(char),
      0,
      (struct sockaddr *) &direccionForanea,
      sizeof(direccionForanea));

  return 0;
}

int SocketDatagrama::recibeTimeout(
    PaqueteDatagrama &p, time_t segundos, suseconds_t microsegundos) {
  timeout.tv_sec = segundos;
  timeout.tv_usec = microsegundos;
  setsockopt(s, SOL_SOCKET, SO_RCVTIMEO, (char *)&timeout, sizeof(timeout));

  char dat[p.longitud()];
  unsigned int clileng = sizeof(direccionForanea);

  if (
      recvfrom(
          s,
          dat,
          p.longitud()*sizeof(char),
          0,
          (struct sockaddr *) &direccionForanea,
          &clileng) <
      0) {
    if (errno == EWOULDBLOCK) {
      fprintf(stderr, "Tiempo para recepción transcurrido.\n");
      return -1;
    } else {
      fprintf(stderr, "Error en recvfrom.\n");
      return -2;
    }
  }
  p.set_datos(dat);
  char str[16];
  inet_ntop(AF_INET, &direccionForanea.sin_addr.s_addr, str, 16);
  p.set_ip(str);
  p.set_puerto(direccionForanea.sin_port);

  return 0;
}

char* SocketDatagrama::getClientIP() {
  return inet_ntoa(direccionForanea.sin_addr);
}

unsigned short SocketDatagrama::getClientPort() {
  return direccionForanea.sin_port;
}
