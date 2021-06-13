#ifndef SOLICITUD_H_
#define SOLICITUD_H_
#include "SocketDatagrama.h"
#include "Mensaje.h"
#include <string.h>

class Solicitud{
	public:
		~Solicitud();
		Solicitud();
		char* doOperation(char *IP, int puerto, char* solicitud);
		char* getIP();
	private:
		SocketDatagrama *socketLocal;
		struct mensaje Recibido;
		struct mensaje Enviar;
		char* dirIP;
		char request;
};

#endif