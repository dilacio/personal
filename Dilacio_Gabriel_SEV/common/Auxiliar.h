#ifndef AUXILIAR_H
#define AUXILIAR_H
#include <stdio.h>
#include <string.h>
// METODOS DEFINIDOS:
//============================================================================================|
//     NOMBRE                           |  TIPO         |                    ACCION           |
//======================================+===============+=====================================|
// toUpper(const char* str)             |  const char*  |  Convierte una cadena a mayusculas  |
//--------------------------------------+---------------+-------------------------------------|
// convertir_char_to_int(char caracter) |  int          | Converite un char a entero          |
//======================================+========+============================================|
class Auxiliar
{
public:

    const char* toUpper(const char* str);
    int convertir_char_to_int(char caracter);

};

#endif // AUXILIAR_H
