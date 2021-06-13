#define LIMITE_ARCHIVO 65000

using namespace std;

struct mensaje{
	char messageType; //0= Solicitud, 1 = Respuesta
	char requestId; //Identificador del mensaje
	char tam[5];
	char nombreArchivo[30];
	char archivo[LIMITE_ARCHIVO+1];
	char estatus;
};