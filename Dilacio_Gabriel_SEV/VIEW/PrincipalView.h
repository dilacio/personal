#ifndef PRINCIPALVIEW_H
#define PRINCIPALVIEW_H
#include <iostream>
#include <cstdio>
#include <stdlib.h>
#include "Consulta_PadronView.h"
#include "Alta_VotanteView.h"
#include "AuxiliaresView.h"
#include "VotanteDAL.h"
#include "VotarView.h"
#include "ResultadosView.h"

using namespace std;

// METODOS DEFINIDOS:
//======================================================================================|
//     NOMBRE              |  TIPO      |                    ACCION                     |
//=========================+============+===============================================|
// Presentacion()          |  void      | Pantalla de presentacion del programa         |
//-------------------------+------------+-----------------------------------------------|
// MenuPrincipal()         |  void      | Menu principal de todo el programa            |
//-------------------------+------------+-----------------------------------------------|
// Despedida()             |  void      | Pantalla de despedida del programa            |
//=========================+============+===============================================|
class PrincipalView
{
public:
    void Presentacion();
    void MenuPrincipal();
    void Despedida();

};

#endif // PRINCIPALVIEW_H
