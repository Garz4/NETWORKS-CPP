#pragma once

#ifndef PAQUETEDATAGRAMA_H_
#define PAQUETEDATAGRAMA_H_

class PaqueteDatagrama {
  private:
    char ip_[16];
    int puerto_;

    /* Cadena de datos a enviar en bytes. */
    char* datos_;

    /* Longitud de la cadena de datos a enviar. */
    unsigned int longitud_;

  public:
    PaqueteDatagrama(
        char* datos, unsigned int longitud, char* ip, int puerto);
    PaqueteDatagrama(unsigned int longitud);
    ~PaqueteDatagrama();

    char* ip();
    void set_ip(char*);

    unsigned int longitud();

    int puerto();
    void set_puerto(int);

    char* datos();
    void set_datos(char*);
};

#endif
