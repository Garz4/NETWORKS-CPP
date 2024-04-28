# MIT License
#
# Copyright (c) 2024 Uriel García Rivas
#
# Permission is hereby granted, free of charge, to any person obtaining a copy
# of this software and associated documentation files (the "Software"), to deal
# in the Software without restriction, including without limitation the rights
# to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
# copies of the Software, and to permit persons to whom the Software is
# furnished to do so, subject to the following conditions:
#
# The above copyright notice and this permission notice shall be included in
# all copies or substantial portions of the Software.
#
# https://github.com/zoningorg/zoning/blob/main/LICENSE

all: ENVIAR_ARCHIVOS RECIBIR_ARCHIVOS

ENVIAR_ARCHIVOS: Cliente.cpp Solicitud.o SocketDatagrama.o
	g++ Cliente.cpp Solicitud.o SocketDatagrama.o -o ENVIAR_ARCHIVOS

RECIBIR_ARCHIVOS: Servidor.cpp Respuesta.o SocketDatagrama.o
	g++ Servidor.cpp Respuesta.o SocketDatagrama.o -o RECIBIR_ARCHIVOS

Respuesta.o: Respuesta.cpp Mensaje.h
	g++ Respuesta.cpp -c

Solicitud.o: Solicitud.cpp Mensaje.h
	g++ Solicitud.cpp -c

SocketDatagrama.o: SocketDatagrama.cpp
	g++ SocketDatagrama.cpp -c

test: PaqueteDatagrama_test
	./PaqueteDatagrama_test ; rm PaqueteDatagrama_test

PaqueteDatagrama_test: test/PaqueteDatagrama_test.cpp
	g++ test/PaqueteDatagrama_test.cpp -o PaqueteDatagrama_test

clean:
	rm -f $(wildcard *.o) ENVIAR_ARCHIVOS RECIBIR_ARCHIVOS
