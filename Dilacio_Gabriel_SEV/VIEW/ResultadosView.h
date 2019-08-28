#ifndef RESULTADOSVIEW_H
#define RESULTADOSVIEW_H
#include <iostream>
#include <cstdio>
#include "AuxiliaresView.h"
#include "VotoDAL.h"
#include "VotoDTO.h"
#include "PartidoDAL.h"
#include "PartidoDTO.h"

using namespace std;

// METODOS DEFINIDOS:
//==========================================================================================================================|
//     NOMBRE                                                   |  TIPO         |                    ACCION                 |
//==============================================================+===============+===========================================|
// Resultados_Tipo(int Tipo)                                    |  void         |  menu de resultado por tipo               |
//--------------------------------------------------------------+---------------+-------------------------------------------|
// Inicializo_Vector (int *Vec, int Tam)                        |  void         |  pone en 0 un vector                      |
//--------------------------------------------------------------+---------------+-------------------------------------------|
// Menu()                                                       |  void         |  menu principal de resultados             |
//--------------------------------------------------------------+---------------+-------------------------------------------|
// Ordenar_Vector(CandidatoDTO *Vec,int Tam)                    |  void         |  ordena un vector de mayor a menor        |
//--------------------------------------------------------------+---------------+-------------------------------------------|
// Cargo_vector(int *Vec,int Tam,CandidatoDTO *Vec_cand)        |  char         |  carga un vector de candidatos            |
//--------------------------------------------------------------+---------------+-------------------------------------------|
// Mostrar_Ranking(CandidatoDTO *Vec_cand,int Tam)              |  void         |  muestra un ranking de votos              |
//--------------------------------------------------------------+---------------+-------------------------------------------|
// Resultados_Partido()                                         |  void         |  muestra los resultados por tipo          |
//--------------------------------------------------------------+---------------+-------------------------------------------|
// Busco_En_vector(int ID_Partido,PartidoDTO *Vec,int Tam )     |  bool         |  busca en un vector un partido            |
//--------------------------------------------------------------+---------------+-------------------------------------------|
// Cuento_cantidad(int ID_Partido);                             |  int          |  Cuenta la cantidad de votos por partido  |
//--------------------------------------------------------------+---------------+-------------------------------------------|
// Ordenar_Vectores(PartidoDTO *Vec,int *Votos_Totales,int Tam) |  void         |  ordena un vector de partidos                     |
//==============================================================+===============+===========================================|
class ResultadosView
{
public:
    void Menu();
    void Resultados_Tipo(int Tipo);
    void Inicializo_Vector (int *Vec, int Tam);
    void Ordenar_Vector(CandidatoDTO *Vec,int Tam);
    void Cargo_vector(int *Vec,int Tam,CandidatoDTO *Vec_cand);
    void Mostrar_Ranking(CandidatoDTO *Vec_cand,int Tam);
    void Resultados_Partido();
    bool Busco_En_vector(int ID_Partido,PartidoDTO *Vec,int Tam );
    int Cuento_cantidad(int ID_Partido);
    void Ordenar_Vectores(PartidoDTO *Vec,int *Votos_Totales,int Tam);

};

#endif // RESULTADOSVIEW_H
