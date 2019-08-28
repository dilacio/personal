#ifndef PROVINCIADAL_H
#define PROVINCIADAL_H
#include "../DTO/ProvinciaDTO.h"
#include <cstdio>
#include <iostream>
#include <cstring>
#include "../common/Auxiliar.h"

using namespace std;

const char Ruta_Provincia[] = "Provincias.dat";

// METODOS DEFINIDOS:
//==========================================================================================================|
//     NOMBRE                           |  TIPO         |                    ACCION                         |
//======================================+===============+===================================================|
// Guardar_EnDisco(PartidoDTO)          |  bool         |  Guarda un registro en un archivo                 |
//--------------------------------------+---------------+---------------------------------------------------|
// Busco_ID (char* Part)                |  int          | Busca un ID por medio de una cadena               |
//--------------------------------------+---------------+---------------------------------------------------|
// Mayor_ID ();                         |  int          | Busca el siguiente ID de registro                 |
//--------------------------------------+---------------+---------------------------------------------------|
// Leer_DeDisco(int Pos, PartidoDTO)    |  bool         | lee un registro del archivo                       |
//--------------------------------------+---------------+---------------------------------------------------|
// Existe(char* Prov)                   |  int          | vifica si existe el registro en el archivo        |
//======================================+========+==========================================================|

class ProvinciaDAL
{
    public:

        int Mayor_ID ();
        bool Guardar_EnDisco(ProvinciaDTO);
        bool Existe(char* Prov);
        int Busco_ID (char* Prov);
        bool Leer_DeDisco(int Pos, ProvinciaDTO &Obj);

};

#endif // PROVINCIADAL_H
