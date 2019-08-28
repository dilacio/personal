#ifndef VOTARVIEW_H
#define VOTARVIEW_H
#include "VotoDAL.h";
#include "VotoDTO.h"
#include <iostream>
#include <cstdio>
#include <stdlib.h>
#include "../common/Auxiliar.h"
#include "AuxiliaresView.h"
#include "VotanteDAL.h"
#include "VotanteDTO.h"

using namespace std;

// METODOS DEFINIDOS:
//==============================================================================|
//     NOMBRE                  |  TIPO         |                    ACCION      |
//=============================+===============+================================|
// Menu()                      |  void         |  menu de alta de votante       |
//-----------------------------+---------------+--------------------------------|
// Info_Partidos()             |  void         |  muestra los partidos          |
//-----------------------------+---------------+--------------------------------|
// Opcion_Seleccion(int Tipo)  |  int          |  valida una opcion seleccionada|
//-----------------------------+---------------+--------------------------------|
// Valida_DNI()                |  int          |  valida una opcion DNI         |
//=============================+===============+================================|
class VotarView
{
    public:
        void Menu();
        void Info_Partidos();
        int Opcion_Seleccion(int Tipo);
        int Valida_DNI();

};

#endif // VOTARVIEW_H
