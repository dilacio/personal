#ifndef ALTA_VOTANTEVIEW_H
#define ALTA_VOTANTEVIEW_H
#include <iostream>
#include "../DAL/VotanteDAL.h"
#include "../DTO/VotanteDTO.h"
#include "../DAL/ProvinciaDAL.h"
#include <stdlib.h>
#include "AuxiliaresView.h"

using namespace std;

// METODOS DEFINIDOS:
//========================================================================|
//     NOMBRE             |  TIPO         |                    ACCION     |
//========================+===============+===============================|
// Menu()                 |  void         |  menu de alta de votante      |
//========================+===============+===============================|
class Alta_VotanteView
{
public:
    void Menu();

};

#endif // ALTA_VOTANTEVIEW_H
