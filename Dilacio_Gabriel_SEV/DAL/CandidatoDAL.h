#ifndef CANDIDATODAL_H
#define CANDIDATODAL_H
#include "../DTO/CandidatoDTO.h"
#include "../common/Auxiliar.h"

const char Ruta_Candidato[] = "Candidato.dat";

// METODOS DEFINIDOS:
//============================================================================================|
//     NOMBRE                           |  TIPO         |                    ACCION           |
//======================================+===============+=====================================|
// Guardar_EnDisco(CandidatoDTO)        |  bool         |  Guarda un registro en un archivo   |
//--------------------------------------+---------------+-------------------------------------|
// Busco_ID (char* Cand)                |  int          | Busca un ID por medio de una cadena |
//--------------------------------------+---------------+-------------------------------------|
// Mayor_ID ();                         |  int          | Bussca un nombre por medio de un ID |
//--------------------------------------+---------------+-------------------------------------|
// Leer_DeDisco(int Pos, CandidatoDTO ) |  bool         | lee un registro del archivo         |
//--------------------------------------+---------------+-------------------------------------|
// Busco_Nombre(int ID)                 |  char*        | Busca un nombre por medio de unID   |
//--------------------------------------+---------------+-------------------------------------|
// Busco_Apellido(int ID)               |  char*        | Busca un apellido por medio de un ID|
//--------------------------------------+---------------+-------------------------------------|
// Busco_Posicion(int ID_Candidato)     |  int          | Busca la posicion de un registro    |
//--------------------------------------+---------------+-------------------------------------|
// Modificar(int Pos,CandidatoDTO)      |  bool          | Modifica un registro               |
//======================================+========+============================================|

class CandidatoDAL
{
public:

    bool Guardar_EnDisco(CandidatoDTO);
    int Busco_ID (char* Cand);
    int Mayor_ID ();
    bool Leer_DeDisco(int Pos, CandidatoDTO &Obj);
    char* Busco_Nombre(int ID);
    char* Busco_Apellido(int ID);
    int Busco_Posicion(int ID_Candidato);
    bool Modificar(int Pos,CandidatoDTO);
};

#endif // CANDIDATODAL_H
