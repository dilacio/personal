#include "VotarView.h"
//---------------------------------------------------------------------------
// METODO    : void VotarView::Menu()
// ACCION    : Menu principal del modulo de votar
// PARAMETROS: NADA
// DEVUELVE  : NADA
//---------------------------------------------------------------------------
void VotarView::Menu()
{
    VotoDAL VotDAL;
    VotoDTO VotDTO;
    PartidoDAL PartDAL;
    PartidoDTO PartDTO;
    CandidatoDAL CandDAL;
    CandidatoDTO CandDTO;
    AuxiliaresView Aux;
    char Opcion;
    bool Salir = false, Ya_Voto = false;
    int Presidente=0, VicePresidente=0,Gobernador=0,DNI, Posicion=0;

    DNI = Valida_DNI();
    Ya_Voto = VotDAL.Ya_Voto(DNI);

    if (Ya_Voto)
    {
        cout << "El Votante ya realizo su voto"<< endl;
        system("pause");
        Salir = true;
    }

    if (DNI != 0 )
    {
        VotDTO.SetDNI(DNI);

        while (!Salir)
        {
            system("cls");

            Aux.Menu_Datos_Sistema();
            cout << "                       MENU VOTO" << endl;
            cout << "_______________________________________________________________________________________"<< endl;
            cout << "                       H - Detalle de partidos y candidatos" << endl;
            cout << "                       S - salir"<<endl;
            cout << "_______________________________________________________________________________________"<< endl;
            cout << ""<<endl;
            cout << "                       BIENVENIDO AL SISTEMA DE VOTACION ELECTRONICO" <<endl;
            cout << "                       "<<endl;
            cout << "                       POR FAVOR SELECCIONE EL PUESTO QUE DESEE VOTAR: "<<endl;
            cout << ""<<endl;
            cout << "                       A - PRESIDENTE" << endl;
            cout << "                       B - VICEPRESIDENTE" << endl;
            cout << "                       C - GOBERNADOR" << endl;
            cout << ""<<endl;
            cout << "                       D - REGISTRAR VOTO" << endl;
            cout << "_______________________________________________________________________________________"<< endl;

            Opcion =  Aux.ValidarOpcion_char("Ingrese una Opcion: ", "Opcion no valida");

            switch (Opcion)
            {
            case 'a':
            case 'A':
            {
                system("cls");
                Presidente = Opcion_Seleccion(1);
                VotDTO.SetID_Presidente(Presidente);

                Posicion = CandDAL.Busco_Posicion(Presidente);
                CandDAL.Leer_DeDisco(Posicion,CandDTO);
                CandDTO.SetVotos(CandDTO.GetVotos()+1);
                CandDAL.Modificar(Posicion,CandDTO);

                system("pause");

            }
            break;

            case 'b':
            case 'B':
            {
                system("cls");
                VicePresidente = Opcion_Seleccion(2);
                VotDTO.SetID_VicePresidente(VicePresidente);

                Posicion = CandDAL.Busco_Posicion(VicePresidente);
                CandDAL.Leer_DeDisco(Posicion,CandDTO);
                CandDTO.SetVotos(CandDTO.GetVotos()+1);
                CandDAL.Modificar(Posicion,CandDTO);

                system("pause");
            }
            break;
            case 'c':
            case 'C':
            {
                system("cls");
                Gobernador = Opcion_Seleccion(3);
                VotDTO.SetID_Gobernador(Gobernador);

                Posicion = CandDAL.Busco_Posicion(Gobernador);
                CandDAL.Leer_DeDisco(Posicion,CandDTO);
                CandDTO.SetVotos(CandDTO.GetVotos()+1);
                CandDAL.Modificar(Posicion,CandDTO);

                system("pause");
            }
            break;

            case 'd':
            case 'D':
            {

                if (Presidente == 0)
                    cout << "Falta el ingreso de un presidente"<<endl;
                if (VicePresidente == 0)
                    cout << "Falta el Ingreso de un Vicepresidente" << endl;
                if (Gobernador == 0)
                    cout << "Falta el ingreso de un Gobernador" << endl;
                if (Presidente!= 0 and VicePresidente != 0 and Gobernador != 0)
                {
                    VotDTO.SetID_Voto(VotDAL.Mayor_ID());
                    if (VotDAL.Guardar_EnDisco(VotDTO))
                    {
                        cout << "Se grabo con exito"<<endl;
                        Salir = true;
                    }
                    else
                    {
                        cout << "Error al grabar";
                    }
                }
                system("pause");
            }
            break;

            case 'h':
            case 'H':
            {
                Info_Partidos();
            }
            break;
            case 'S':
            case 's':
            {
                Salir = true;
            }
            default:
            {
                cout << "Opcion no valida!" << endl;
                system("pause");
            }
            break;
            }
        }
    }
}
//---------------------------------------------------------------------------
// METODO    : void VotarView::Info_Partidos()
// ACCION    : Muestra la informacion de los partidos
// PARAMETROS: NADA
// DEVUELVE  : NADA
//---------------------------------------------------------------------------
void VotarView::Info_Partidos()
{
    PartidoDAL      PartDAL;
    PartidoDTO      PartDTO;
    PuestoDAL       PuestDAL;
    PuestoDTO       PuestDTO;
    CandidatoDAL    CandDAL;
    CandidatoDTO    CandDTO;

    system("cls");
    char    Nombre_Puesto[25],Apellido_Candidato[25],Nombre_Candidato[25], Partido_Ant[40];
    int Pos=0, ContPart=0;

    while (PartDAL.Leer_DeDisco(Pos,PartDTO))
    {
        if (strcmp(Partido_Ant,PartDTO.GetNombre())!=0)
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
            cout <<"_______________________________________________________"<< endl;
            cout.width(40);
            cout << internal << PartDTO.GetNombre() << endl;
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
        }

        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
        strcpy(Nombre_Puesto,PuestDAL.Busco_Nombre(PartDTO.GetID_Puesto()));
        cout.width(18);
        cout << left << Nombre_Puesto;

        strcpy(Nombre_Candidato,CandDAL.Busco_Nombre(PartDTO.GetID_Candidato()));
        strcpy(Apellido_Candidato,CandDAL.Busco_Apellido(PartDTO.GetID_Candidato()));

        cout.width(15);
        cout << left << Nombre_Candidato;
        cout.width(2);
        cout << left << Apellido_Candidato;
        Pos++;
        cout << endl;

        strcpy(Partido_Ant,PartDTO.GetNombre());
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
    }
    cout << endl;
    system("pause");
}
//---------------------------------------------------------------------------
// METODO    : int VotarView::Opcion_Seleccion(int Tipo)
// ACCION    : Valida la opcion ingresada por el usuario
// PARAMETROS: Tipo
// DEVUELVE  : Opcion
//---------------------------------------------------------------------------
int VotarView::Opcion_Seleccion(int Tipo)
{
    PartidoDAL PartDAL;
    PartidoDTO PartDTO;
    CandidatoDAL CandDAL;
    PartidoDTO *Vec;
    char Nombre[25], Apellido[25];
    AuxiliaresView Aux;
    int Pos = 0,Tam=0;
    int ID_Ant=0;
    int Ingreso,Opcion = 1;

    cout <<"_______________________________________________________________________________________________"<< endl;
    cout << "                 PARA EL PUESTO DE PRESIDENTE SE ENCUENTRAN LOS SIGUIENTES CANDIDATOS:"<<endl;
    cout << endl;

    Tam = PartDAL.Cuento_Partidos(Tipo);

    Vec = new PartidoDTO[Tam];

    while (PartDAL.Leer_DeDisco(Pos,PartDTO))
    {
        if (  PartDTO.GetID_Puesto()==Tipo)
        {
            strcpy(Nombre, CandDAL.Busco_Nombre(PartDTO.GetID_Candidato()));
            strcpy(Apellido,CandDAL.Busco_Apellido(PartDTO.GetID_Candidato()));
            cout << "                       " << Opcion <<" - " << Nombre<< " " << Apellido<< endl;
            Vec[Opcion-1] = PartDTO;
            Opcion ++;

        }
        Pos++;
    }

    Ingreso = Aux.Validar_Int("Ingrese un candidato: ","Opcion incorrecta");



    return Vec[Ingreso-1].GetID_Candidato();
}
//---------------------------------------------------------------------------
// METODO    : int VotarView::Valida_DNI()
// ACCION    : valida el dni del usuario
// PARAMETROS: NADA
// DEVUELVE  : DNI
//---------------------------------------------------------------------------
int VotarView::Valida_DNI()
{
    bool Salir = false;
    int DNI;
    VotanteDAL VotDAL;
    VotanteDTO VotDTO;

    system("cls");
    cout << "                       MENU VOTO" << endl;
    cout << "_______________________________________________________________________________________"<< endl;
    cout << "" << endl;
    cout << "                       0 - Salir" << endl;
    cout << "_______________________________________________________________________________________"<< endl;

    while (!Salir)
    {
        cout << "Ingrese el DNI: ";
        cin >> DNI;

        if (DNI != 0)
        {
            if (VotDAL.Existe_Votante(DNI) )
            {
                Salir = true;
            }
            else
            {
                cout << "El dni es incorrecto o no se encuentra dado de alta" << endl;
            }
        }
        else
        {
            Salir = true;
        }
    }
    return DNI;
}
