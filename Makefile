all: ENVIAR_ARCHIVOS RECIBIR_ARCHIVOS
ENVIAR_ARCHIVOS: Cliente.cpp Solicitud.o PaqueteDatagrama.o SocketDatagrama.o
	g++ Cliente.cpp Solicitud.o PaqueteDatagrama.o SocketDatagrama.o -o ENVIAR_ARCHIVOS
RECIBIR_ARCHIVOS: Servidor.cpp Respuesta.o PaqueteDatagrama.o SocketDatagrama.o
	g++ Servidor.cpp Respuesta.o PaqueteDatagrama.o SocketDatagrama.o -o RECIBIR_ARCHIVOS
Respuesta.o: Respuesta.cpp Mensaje.h
	g++ Respuesta.cpp -c
Solicitud.o: Solicitud.cpp Mensaje.h
	g++ Solicitud.cpp -c
SocketDatagrama.o: SocketDatagrama.cpp
	g++ SocketDatagrama.cpp -c
PaqueteDatagrama.o: PaqueteDatagrama.cpp
	g++ PaqueteDatagrama.cpp -c