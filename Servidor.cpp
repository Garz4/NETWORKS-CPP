#include <iostream>
#include <fstream>
#include <string>
#include "Respuesta.h"

using namespace std;

int main(void){
	Respuesta r(7200);
	struct mensaje mensajeEnvio;
	struct mensaje mensajeRecibo;

	ofstream archivoGuardar;
	char *archivoRecibo;

	while(1){
		cout << "Esperando mensaje..." << endl;
		memcpy(&mensajeRecibo, r.getRequest(), sizeof(struct mensaje));
		if(mensajeRecibo.messageType != 'n'){
			cout << "==================================" << endl;
			cout << mensajeRecibo.nombreArchivo << ": ";

			archivoRecibo = new char[atoi(mensajeRecibo.tam)];
			memcpy(archivoRecibo, mensajeRecibo.archivo, atoi(mensajeRecibo.tam));
			archivoRecibo[atoi(mensajeRecibo.tam)] = '\0';
			archivoGuardar.open(mensajeRecibo.nombreArchivo);
			archivoGuardar.write(archivoRecibo, atoi(mensajeRecibo.tam));

			if(archivoGuardar.is_open()){mensajeEnvio.estatus = '0'; cout << "Guardado." << endl;}
			else{mensajeEnvio.estatus = '1'; cout << "Fallo en escritura." << endl;}

			memcpy(mensajeEnvio.nombreArchivo, mensajeRecibo.nombreArchivo, sizeof(mensajeEnvio.nombreArchivo));
			archivoGuardar.close();
			delete[] archivoRecibo;
		}
		r.sendReply((char *)&mensajeEnvio);
	}
	return 0;
}