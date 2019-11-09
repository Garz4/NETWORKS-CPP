#ifndef PAQUETEDATAGRAMA_H_
#define PAQUETEDATAGRAMA_H_

class PaqueteDatagrama{
	private:
		char *datos;			//Almacena los datos
		char ip[16];			//Almacena la IP
		unsigned int longitud;	//Almacena la longitude de la cadena de datos
		int puerto;				//Almacena el puerto
	public:
		PaqueteDatagrama(char *data_, unsigned int longitude_, char* address_, int port_);
		PaqueteDatagrama(unsigned int );
		~PaqueteDatagrama();
		char *obtieneDireccion();
		unsigned int obtieneLongitud();
		int obtienePuerto();
		char *obtieneDatos();
		void inicializaPuerto(int);
		void inicializaIp(char *);
		void inicializaDatos(char *);
};

#endif