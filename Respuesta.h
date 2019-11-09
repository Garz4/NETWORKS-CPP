#ifndef RESPUESTA_H_
#define RESPUESTA_H_
#include "SocketDatagrama.h"
#include <string.h>
#include "Mensaje.h"

class Respuesta{
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