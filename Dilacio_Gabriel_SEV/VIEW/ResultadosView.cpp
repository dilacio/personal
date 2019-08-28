#include "ResultadosView.h"

//---------------------------------------------------------------------------
// METODO    : void ResultadosView::Menu()
// ACCION    : Menu principal del modulo de resultados
// PARAMETROS: NADA
// DEVUELVE  : NADA
//---------------------------------------------------------------------------
void ResultadosView::Menu()
{
    char Opcion;
    bool Salir = false;
    AuxiliaresView Aux;

    while (!Salir)
    {
        system("cls");

        Aux.Menu_Datos_Sistema();
        cout << "                       MENU RESULTADOS" << endl;
        cout << "_______________________________________________________________________________________"<< endl;
        cout << endl;
        cout << endl;
        cout << "                       A - RESULTADOS PRESIDENCIALES" << endl;
        cout << "                       B - RESULTADOS VICEPRESIDENCIALES" << endl;
        cout << "                       C - RESULTADOS GOBERNACION" << endl;
        cout << "                       D - RESULTADOS POR PARTIDO" << endl;
        cout << "                       S - SALIR" << endl;
        cout <<endl;
        cout << "_______________________________________________________________________________________"<< endl;


        Opcion =  Aux.ValidarOpcion_char("Ingrese una Opcion: ", "Opcion no valida");
        switch (Opcion)
        {
        case 'a':
        case 'A':
        {
            Resultados_Tipo(1);
        }
        break;
        case 'b':
        case 'B':
        {
            Resultados_Tipo(2);
        }
        break;
        case 'c':
        case 'C':
        {
            Resultados_Tipo(3);
        }
        break;
        case 'd':
        case 'D':
        {
            Resultados_Partido();
        }
        break;
        case 's':
        case 'S':
        {
            Salir = true;
        }
        break;
        default:
        {

        } break;
        }
    }
}
//---------------------------------------------------------------------------
// METODO    : void ResultadosView::Resultados_Tipo(int Tipo)
// ACCION    : muestra la pantalla de resultados por tipo
// PARAMETROS: NADA
// DEVUELVE  : NADA
//---------------------------------------------------------------------------
void ResultadosView::Resultados_Tipo(int Tipo)
{
    CandidatoDTO CandDTO, *Vec_cand;
    CandidatoDAL CandDAL;
    PartidoDAL PartDAL;
    PartidoDTO PartDTO ;
    int Pos = 0, Pos_Vec = 0;
    int *Vec;
    int Tam;

    Tam = PartDAL.Cuento_Partidos(Tipo);
    Vec = new int[Tam];
    Vec_cand = new CandidatoDTO[Tam];

    while (PartDAL.Leer_DeDisco(Pos,PartDTO))
    {
        if (PartDTO.GetID_Puesto() == Tipo)
        {
            Vec[Pos_Vec] = PartDTO.GetID_Candidato();
            Pos_Vec ++;
        }
        Pos++;
    }

    Cargo_vector(Vec,Tam,Vec_cand);

    Ordenar_Vector(Vec_cand,Tam);

    Mostrar_Ranking(Vec_cand,Tam);

}
//---------------------------------------------------------------------------
// METODO    : void ResultadosView::Cargo_vector(int *Vec,int Tam,CandidatoDTO *Vec_cand)
// ACCION    : carga el vector con los candidatos para el resultado
// PARAMETROS: int *Vec,int Tam,CandidatoDTO *Vec_cand
// DEVUELVE  : NADA
//---------------------------------------------------------------------------
void ResultadosView::Cargo_vector(int *Vec,int Tam,CandidatoDTO *Vec_cand)
{
    CandidatoDAL CandDAL;
    CandidatoDTO CandDTO;
    int Pos;

    for (int i=0; i<Tam; i++)
    {
        Pos = CandDAL.Busco_Posicion(Vec[i]);
        CandDAL.Leer_DeDisco(Pos,CandDTO);

        Vec_cand[i]=CandDTO;
    }
}
//---------------------------------------------------------------------------
// METODO    : void ResultadosView::Ordenar_Vector(CandidatoDTO *Vec,int Tam)
// ACCION    : ordena el vector de mayor a menor por cantidad de votos
// PARAMETROS: CandidatoDTO *Vec,int Tam
// DEVUELVE  : NADA
//---------------------------------------------------------------------------
void ResultadosView::Ordenar_Vector(CandidatoDTO *Vec,int Tam)
{
    int i = 0, r=0;
    CandidatoDTO *Aux;

    Aux = new CandidatoDTO[Tam];

    for(i=0; i<Tam; i++)
    {
        for(r=0; r<(Tam-1); r++)
        {
            if(Vec[r].GetVotos() < Vec[r+1].GetVotos())
            {
                Aux[r] = Vec[r];
                Vec[r] = Vec[r+1];
                Vec[r+1] = Aux[r];
            }
        }
    }
}
//---------------------------------------------------------------------------
// METODO    : void ResultadosView::Mostrar_Ranking(CandidatoDTO *Vec_cand,int Tam)
// ACCION    : carga el vector con los candidatos para el resultado
// PARAMETROS: NADA
// DEVUELVE  : NADA
//---------------------------------------------------------------------------
void ResultadosView::Mostrar_Ranking(CandidatoDTO *Vec_cand,int Tam)
{
    AuxiliaresView Aux;
    system("cls");

    Aux.Menu_Datos_Sistema();

    int i=0,c=0;
    PartidoDAL PartDAL;
    PartidoDTO PartDTO;
    char Partido[30];

    cout.width(5);
    cout << left << "Puesto" ;
    cout.width(15);
    cout << left << "Nombre" ;
    cout.width(25);
    cout << left << "Apellido" ;
    cout.width(30);
    cout << left << "Partido" ;
    cout.width(5);
    cout << left << "Votos" << endl ;

    cout << endl;

    for(i=0; i<Tam; i++)
    {
        strcpy(Partido,PartDAL.Busco_Nombre_x_Cand(Vec_cand[i].GetID_Candidato()));

        cout.width(5);
        cout << left << i+1 ;
        cout.width(15);
        cout << left << Vec_cand[i].GetNombre() ;
        cout.width(25);
        cout << left << Vec_cand[i].GetApellido() ;
        cout.width(30);
        cout << left << Partido;
        cout.width(5);
        cout << left << Vec_cand[i].GetVotos()<< endl ;
    }

    cout << endl;

    system("pause");
}
//---------------------------------------------------------------------------
// METODO    : void ResultadosView::Resultados_Partido()
// ACCION    : pantalla de resultados por partido
// PARAMETROS: NADA
// DEVUELVE  : NADA
//---------------------------------------------------------------------------
void ResultadosView::Resultados_Partido()
{
    PartidoDAL PartDAL;
    PartidoDTO PartDTO,*Vec;
    CandidatoDAL CandDAL;
    CandidatoDTO CandDTO;
    int Pos=0, Pos_Nueva = 0, *Votos_Totales,  Tam;

    Tam = PartDAL.Cuento_Partidos(1);

    Votos_Totales = new int[Tam];
    Vec = new PartidoDTO[Tam];

    while (PartDAL.Leer_DeDisco(Pos,PartDTO))
    {
        if (!Busco_En_vector(PartDTO.GetID_Partido(),Vec,Tam))
        {
            Vec[Pos_Nueva] = PartDTO;
            Pos_Nueva++;
        }
        Pos++;
    }

    system("cls");
    cout.width(25);
    cout << left << "Partido" ;
    cout.width(5);
    cout << left << "Votos Totales" << endl ;
    cout << endl;

    for (int i=0 ; i<Tam; i++)
    {
        Votos_Totales[i] = Cuento_cantidad(Vec[i].GetID_Partido());
    }

    Ordenar_Vectores(Vec,Votos_Totales,Tam);

    for (int g=0;g<Tam;g++)
    {
        cout.width(25);
        cout << left <<Vec[g].GetNombre();
        cout.width(5);
        cout << left <<Votos_Totales[g]<< endl;
    }


    system("pause");
}
//---------------------------------------------------------------------------
// METODO    : int ResultadosView::Cuento_cantidad(int ID_Partido)
// ACCION    : Cuenta la cantidad de votos por partido
// PARAMETROS: ID_Partido
// DEVUELVE  : cantidad de votos
//---------------------------------------------------------------------------
int ResultadosView::Cuento_cantidad(int ID_Partido)
{
    int Pos=0, Cant = 0;
    PartidoDAL PartDAL;
    PartidoDTO PartDTO;
    CandidatoDAL CandDal;
    CandidatoDTO CandDTO;

    while (CandDal.Leer_DeDisco(Pos,CandDTO))
    {
        if(ID_Partido==PartDAL.Busco_x_Cand(CandDTO.GetID_Candidato()))
        {
            Cant += CandDTO.GetVotos();
        }
        Pos++;
    }
    return Cant;
}
//---------------------------------------------------------------------------
// METODO    : bool ResultadosView::Busco_En_vector(int ID_Partido,PartidoDTO *Vec,int Tam )
// ACCION    : busca en el vector si aparece un ID de partido
// PARAMETROS: int ID_Partido,PartidoDTO *Vec,int Tam
// DEVUELVE  : true si aparece, false si no aparece
//---------------------------------------------------------------------------
bool ResultadosView::Busco_En_vector(int ID_Partido,PartidoDTO *Vec,int Tam )
{
    bool Resultado = false;

    for (int i =0; i<Tam; i++)
    {
        if(Vec[i].GetID_Partido()==ID_Partido)
        {
            Resultado = true;
        }
    }
    return Resultado;
}
//---------------------------------------------------------------------------
// METODO    : void ResultadosView::Ordenar_Vectores(PartidoDTO *Vec,int *Votos_Totales,int Tam)
// ACCION    : Ordena los vectores por cantidad de votos por partido
// PARAMETROS: PartidoDTO *Vec,int *Votos_Totales,int Tam
// DEVUELVE  : NADA
//---------------------------------------------------------------------------
void ResultadosView::Ordenar_Vectores(PartidoDTO *Vec,int *Votos_Totales,int Tam)
{
    int i = 0, r=0,*Aux_int;
    PartidoDTO *Aux;

    Aux = new PartidoDTO[Tam];
    Aux_int = new int[Tam];

    for(i=0; i<Tam; i++)
    {
        for(r=0; r<(Tam-1); r++)
        {
            if(Votos_Totales[r] < Votos_Totales[r+1])
            {
                Aux_int[r] = Votos_Totales[r];
                Votos_Totales[r] = Votos_Totales[r+1];
                Votos_Totales[r+1] = Aux_int[r];

                Aux[r] = Vec[r];
                Vec[r] = Vec[r+1];
                Vec[r+1] = Aux[r];
            }
        }
    }
}
