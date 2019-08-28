#ifndef VOTODAL_H
#define VOTODAL_H
#include "../DTO/VotoDTO.h"
#include <cstdio>

const char Ruta_Voto[] = "Voto.dat";

// METODOS DEFINIDOS:
//================================================================================================================|
//     NOMBRE                                 |  TIPO         |                    ACCION                         |
//============================================+===============+===================================================|
// Guardar_EnDisco(PartidoDTO)                |  bool         |  Guarda un registro en un archivo                 |
//--------------------------------------------+---------------+---------------------------------------------------|
// Mayor_ID ();                               |  int          | Busca el siguiente ID de registro                 |
//--------------------------------------------+---------------+---------------------------------------------------|
// bool Ya_Voto (int DNI);                    |  bool         | verifica si existe un registro en el archivo      |
//--------------------------------------------+---------------+---------------------------------------------------|
// Leer_DeDisco(int Pos, PartidoDTO)          |  bool         | lee un registro del archivo                       |
//--------------------------------------------+---------------+---------------------------------------------------|
// Cantidad_votos(int Candidato, int Puesto)  |  bool         | verifica si existe un registro en el archivo      |
//============================================+===============+===================================================|
class VotoDAL
{
public:
    bool Guardar_EnDisco(VotoDTO);
    int Mayor_ID ();
    bool Leer_DeDisco(int Pos, VotoDTO &Obj);
    bool Ya_Voto (int DNI);
    int Cantidad_votos(int Candidato, int Puesto);
};

#endif // VOTODAL_H
