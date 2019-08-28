#include "Auxiliar.h"

//---------------------------------------------------------------------------
// METODO    : const char* Auxiliar::toUpper(const char* str)
// ACCION    : Converite una cadena a mayusculas.
// PARAMETROS: const char* str --> cadena a convertir a mayusculas
// DEVUELVE  : const char*Auxiliar
//---------------------------------------------------------------------------
const char* Auxiliar::toUpper(const char* str)
{
    for (char* cp = const_cast<char*>(str); char c = *cp; cp++)
    {
        if (c >= 'a' && c <= 'z')
            *cp = c - 'a' + 'A';
    }
    return str;
}
//---------------------------------------------------------------------------
// METODO    : int Auxiliar::convertir_char_to_int(char caracter)
// ACCION    : convierte un char a entero.
// PARAMETROS: char caracter --> caracter a convertir
// DEVUELVE  : int
//---------------------------------------------------------------------------
int Auxiliar::convertir_char_to_int(char caracter)
{
 int auxiliar =0;
 auxiliar = caracter-48;
 return auxiliar;
}

