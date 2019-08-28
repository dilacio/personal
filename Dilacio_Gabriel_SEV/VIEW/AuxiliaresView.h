#ifndef AUXILIARESVIEW_H
#define AUXILIARESVIEW_H
#include "../DTO/ProvinciaDTO.h"
#include "../DAL/ProvinciaDAL.h"
#include "../common/Auxiliar.h"
#include <cstdio>
#include <iostream>
#include <cstring>
#include "AuxiliarDAL.h"
#include <stdlib.h>
#include <windows.h>
#include "CandidatoDAL.h"
#include "CandidatoDTO.h"
#include "PartidoDAL.h"
#include "PartidoDTO.h"
#include "PuestoDAL.h"
#include "PuestoDTO.h"
#include "VotoDAL.h"
#include "VotoDTO.h"
#include "VotanteDAL.h"
#include "VotanteDTO.h"

using namespace std;

// METODOS DEFINIDOS:
//===================================================================================================================|
//     NOMBRE                                            |  TIPO         |                    ACCION                 |
//=======================================================+===============+===========================================|
// Alta_Provincia()                                      |  void         |  menu para el alta de una provincia       |
//-------------------------------------------------------+---------------+-------------------------------------------|
// Mostrar_Provincias();                                 |  void         |  Muestra las provincias                   |
//-------------------------------------------------------+---------------+-------------------------------------------|
// Menu()                                                |  void         |  menu principale auxiliares               |
//-------------------------------------------------------+---------------+-------------------------------------------|
// void Menu_Datos_Sistema()                             |  void         |  menu de alta de votante                  |
//-------------------------------------------------------+---------------+-------------------------------------------|
// ValidarOpcion_char(char *Mensaje, char *MensajeError) |  char         |  valida una opcion ingresada              |
//-------------------------------------------------------+----------------+------------------------------------------|
// Alta_Partido();                                       |  void         |  menu para el alta de un partido          |
//-------------------------------------------------------+----------------+------------------------------------------|
// Mostrar_Partidos();                                   |  void         |  Muestra los partidos                     |
//-------------------------------------------------------+----------------+------------------------------------------|
// Alta_Candidato();                                     |  void         |  menu para el alta de un candidato        |
//-------------------------------------------------------+----------------+------------------------------------------|
// Alta_Puesto();                                        |  void         |  menu para el alta de un puesto           |
//-------------------------------------------------------+----------------+------------------------------------------|
// Mostrar_Puestos();                                    |  void         |  Muestra los puestos                      |
//-------------------------------------------------------+----------------+------------------------------------------|
// Validar_Int(char *Mensaje, char *MensajeError)        |  int         |  Valida una opcion int                     |
//-------------------------------------------------------+----------------+------------------------------------------|
// Mostrar_Votos();                                      |  void         |  Muestra los votos                        |
//-------------------------------------------------------+----------------+------------------------------------------|
// Mostrar_Votantes();                                   |  void         |  Muestra los votantes                     |
//=======================================================+===============+===========================================|

class AuxiliaresView
{
public:
    void Alta_Provincia();
    void Mostrar_Provincias();
    void Menu();
    void Menu_Datos_Sistema();
    char ValidarOpcion_char(char *Mensaje, char *MensajeError);
    void Alta_Partido();
    void Mostrar_Partidos();
    void Alta_Candidato();
    void Mostrar_Candidatos();
    void Alta_Puesto();
    void Mostrar_Puestos();
    int Validar_Int(char *Mensaje, char *MensajeError);
    void Mostrar_Votos();
    void Mostrar_Votantes();

    void Ayuda();

};


#endif // AUXILIARESVIEW_H
