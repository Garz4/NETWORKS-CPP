#include <iostream>
#include "Respuesta.h"
#include "PaqueteDatagrama.h"

using namespace std;

int flipBit(int bit);

Respuesta::Respuesta(int pl){
	socketLocal = new SocketDatagrama(pl);
	requestIdPrev = 'n';
}

struct mensaje* Respuesta::getRequest(void){
	PaqueteDatagrama paqueteRecibo(sizeof(struct mensaje));
	socketLocal->recibe(paqueteRecibo);
	if(requestIdPrev == ((struct mensaje*)(paqueteRecibo.obtieneDatos()))->requestId){
		Recibido.messageType = 'n';
		return &Recibido;
	}
	else{
		memcpy((char*)&Recibido, paqueteRecibo.obtieneDatos(), sizeof(struct mensaje));
		dirIP = socketLocal->getClientIP();
		port = (int)(socketLocal->getClientPort());
		requestIdPrev = Recibido.requestId;
		return &Recibido;
	}
}

void Respuesta::sendReply(char *respuesta){
	memcpy((char*)&Enviar, respuesta, sizeof(struct mensaje));
	Enviar.messageType = '1';
	Enviar.requestId = Recibido.requestId;
	PaqueteDatagrama paqueteEnvio((char*)&Enviar, sizeof(struct mensaje), dirIP, htons(port));
	socketLocal->envia(paqueteEnvio);
	return;
}

Respuesta::~Respuesta(){delete socketLocal;}

char* Respuesta::getIP(){return dirIP;}
int Respuesta::getPort(){return port;}

int flipBit(int bit){
	if(bit == 0) return 1;
	else return 0;
}