#include "PaqueteDatagrama.h"
#include <iostream>
#include <string.h>
#include <cstring>

PaqueteDatagrama::PaqueteDatagrama(
    char* datos, unsigned int longitud, char* ip, int puerto) {
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

char* PaqueteDatagrama::ip() { return ip_; }
void PaqueteDatagrama::set_ip(char* ip) { std::strcpy(ip_, ip); }

unsigned int PaqueteDatagrama::longitud() { return longitud_; }

int PaqueteDatagrama::puerto() { return puerto_; }
void PaqueteDatagrama::set_puerto(int puerto) { puerto_ = puerto; }

char* PaqueteDatagrama::datos() { return datos_; }
void PaqueteDatagrama::set_datos(char* datos) {
  std::memcpy(datos_, datos, longitud_);
}
