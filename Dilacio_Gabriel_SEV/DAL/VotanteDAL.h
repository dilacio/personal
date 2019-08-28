#ifndef VOTANTEDAL_H
#define VOTANTEDAL_H
#include <cstdio>
#include "../DTO/VotanteDTO.h"

const char Ruta_Votante[] = "Votante.dat";

// METODOS DEFINIDOS:
//==========================================================================================================|
//     NOMBRE                           |  TIPO         |                    ACCION                         |
//======================================+===============+===================================================|
// Guardar_EnDisco(PartidoDTO)          |  bool         |  Guarda un registro en un archivo                 |
//--------------------------------------+---------------+---------------------------------------------------|
// Busco_Posicion(int DNI);             |  int          | Busca la posicion de un registro                  |
//--------------------------------------+---------------+---------------------------------------------------|
// Existe_Votante (int DNI)             |  bool         | verifica si existe un registro dentro del archivo |
//--------------------------------------+---------------+---------------------------------------------------|
// Leer_DeDisco(int Pos, PartidoDTO)    |  bool         | lee un registro del archivo                       |
//======================================+===============+===================================================|
class VotanteDAL
{
public:
    bool Existe_Votante (int DNI);
    bool Guardar_EnDisco (VotanteDTO Votante);
    bool Leer_DeDisco(int Pos, VotanteDTO &Obj);
    int Busco_Posicion(int DNI);

};

#endif // VOTANTEDAL_H
