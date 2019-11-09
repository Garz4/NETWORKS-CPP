#include "PaqueteDatagrama.h"
#include <iostream>
#include <string.h>

using namespace std;

PaqueteDatagrama::PaqueteDatagrama(char* data_, unsigned int longitude_, char* address_, int port_){
	strcpy(ip,address_);
	datos = new char[longitude_];
	memcpy(datos, data_, longitude_);
	longitud = longitude_;
	puerto = port_;
}

PaqueteDatagrama::PaqueteDatagrama(unsigned int longitude_){
	longitud = longitude_;
	datos = new char[longitude_];
}

PaqueteDatagrama::~PaqueteDatagrama(){
	delete []datos;
}

char* PaqueteDatagrama::obtieneDireccion(){return ip;}
unsigned int PaqueteDatagrama::obtieneLongitud(){return longitud;}
char* PaqueteDatagrama::obtieneDatos(){return datos;}
int PaqueteDatagrama::obtienePuerto(){return puerto;}

void PaqueteDatagrama::inicializaPuerto(int port_){puerto = port_; return;}
void PaqueteDatagrama::inicializaIp(char* address_){strcpy(ip,address_); return;}
void PaqueteDatagrama::inicializaDatos(char* data_){memcpy(datos, data_, longitud); return;}