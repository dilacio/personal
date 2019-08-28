#ifndef PARTIDODAL_H
#define PARTIDODAL_H
#include "../DTO/PartidoDTO.h"
#include "PartidoDAL.h"
#include "PartidoDTO.h"
#include <cstdio>
#include "../common/Auxiliar.h"

const char Ruta_Partido[] = "Partido.dat";

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
// Cuento_Partidos(int Tipo)            |  int          | cuenta la cantidad de partidos                    |
//--------------------------------------+---------------+---------------------------------------------------|
// Busco_Nombre_x_Cand(int ID)          |  char*        | Busca el nombre de partido por un candidato       |
//--------------------------------------+---------------+---------------------------------------------------|
// Busco_x_Cand(int ID_Cand)            |  int          | Busca un ID de partido por medio de un candidato  |
//======================================+========+==========================================================|
class PartidoDAL
{
public:
    bool Guardar_EnDisco(PartidoDTO);
    int Busco_ID (char* Part);
    int Mayor_ID ();
    bool Leer_DeDisco(int Pos, PartidoDTO &Obj);
    int Cuento_Partidos(int Tipo);
    char* Busco_Nombre_x_Cand(int ID);
    int Busco_x_Cand(int ID_Cand);
};

#endif // PARTIDODAL_H
