#ifndef PUESTODAL_H
#define PUESTODAL_H
#include "../DTO/PuestoDTO.h"
#include <iostream>
#include <cstdio>
#include "../common/Auxiliar.h"

using namespace std;
const char Ruta_Puesto[] = "Puesto.dat";

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
// Busco_Nombre(int ID)                 |  char*        | busca un nombre por medio de un ID                |
//======================================+===============+===================================================|
class PuestoDAL
{
    public:
        int Busco_ID(char* Puesto);
        int Mayor_ID ();
        bool Guardar_EnDisco(PuestoDTO);
        bool Leer_DeDisco(int Pos, PuestoDTO &Obj);
        char* Busco_Nombre(int ID);

};

#endif // PUESTODAL_H
