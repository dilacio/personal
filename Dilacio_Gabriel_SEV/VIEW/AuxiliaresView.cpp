#include "AuxiliaresView.h"

//---------------------------------------------------------------------------
// METODO    : void AuxiliaresView::Alta_Puesto()
// ACCION    : Da de alta un puesto
// PARAMETROS: NADA
// DEVUELVE  : NADA
//---------------------------------------------------------------------------
void AuxiliaresView::Alta_Puesto()
{
    PuestoDTO PuestoDTO;
    PuestoDAL PuestoDAL;

    char Nombre[25];
    int ID;

    cout << "Ingrese el nombre del puesto: ";
    cin.getline (Nombre,25);

    ID = PuestoDAL.Busco_ID(Nombre);

    if(ID == 0)
    {
        PuestoDTO.SetDescripcion(Nombre);
        PuestoDTO.SetID_Puesto(PuestoDAL.Mayor_ID());



        if (PuestoDAL.Guardar_EnDisco(PuestoDTO))
        {
            cout << "Candidato dada de alta correctamente" << endl;
        }
        else
        {
            cout << "error al dar de alta la provincia" << endl;
        }
    }
    else
    {
        cout << "La provincia ya se encuentra dada de alta"<< endl;
    }
    system("pause");
}
//---------------------------------------------------------------------------
// METODO    : void AuxiliaresView::Alta_Provincia()
// ACCION    : Da de alta una Provincia
// PARAMETROS: NADA
// DEVUELVE  : NADA
//---------------------------------------------------------------------------
void AuxiliaresView::Alta_Provincia()
{
    ProvinciaDTO ProvDTO;
    ProvinciaDAL ProvDAL;
    char Nombre[40];
    int Mayor_ID;


    system("cls");

    cout << "Ingrese el nombre de la provincia: ";
    cin.getline(Nombre,40);

    if(!ProvDAL.Existe(Nombre))
    {
        Mayor_ID = ProvDAL.Mayor_ID();

        ProvDTO.SetID_Provincia(Mayor_ID);
        ProvDTO.SetNombre(Nombre);

        if (ProvDAL.Guardar_EnDisco(ProvDTO))
        {
            cout << "Provincia dada de alta correctamente" << endl;
        }
        else
        {
            cout << "error al dar de alta la provincia" << endl;
        }
    }
    else
    {
        cout << "La provincia ya se encuentra dada de alta"<< endl;
    }
    system("pause");
}
//---------------------------------------------------------------------------
// METODO    : void AuxiliaresView::Mostrar_Provincias()
// ACCION    : Lista todas las provincias
// PARAMETROS: NADA
// DEVUELVE  : NADA
//---------------------------------------------------------------------------
void AuxiliaresView::Mostrar_Provincias()
{
    ProvinciaDAL ProvDAL;
    ProvinciaDTO ProvDTO;

    int Pos = 0;

    cout.width(10);
    cout << left<<"ID";
    cout.width(40);
    cout << left<<"Nombre" << endl ;

    while (ProvDAL.Leer_DeDisco(Pos,ProvDTO))
    {
        cout.width(10);
        cout << left << ProvDTO.GetID_Provincia() ;
        cout.width(40);
        cout <<left << ProvDTO.GetNombre() << endl;
        Pos++;
    }
    system("pause");
}
//---------------------------------------------------------------------------
// METODO    : void AuxiliaresView::Menu ()
// ACCION    : Menu con opciones
// PARAMETROS: NADA
// DEVUELVE  : NADA
//---------------------------------------------------------------------------
void AuxiliaresView::Menu ()
{
    bool Salir = false;
    char Opcion;


    while (!Salir)
    {
        system("cls");

        Menu_Datos_Sistema();

        cout << "                       MENU AUXILIARES" << endl;
        cout << "_______________________________________________________________________________________"<< endl;
        cout << endl;
        cout << "                     A - ALTA DE PROVINCIA" << endl;
        cout << "                     B - LISTADO DE PROVINCIAS" << endl;
        cout << "                     C - ALTA DE CANDIDATO" << endl;
        cout << "                     D - LISTADO DE CANDIDATOS" << endl;
        cout << "                     E - ALTA DE PUESTO" << endl;
        cout << "                     F - LISTADO DE PUESTO" << endl;
        cout << "                     G - ALTA DE PARTIDO" << endl;
        cout << "                     H - LISTADO DE PARTIDOS" << endl;
        cout << "                     I - LISTADO DE VOTOS" << endl;
        cout << "                     J - LISTADO DE VOTANTES" << endl;
        cout << "                     S - SALIR" << endl;
        cout <<endl;
        cout << "_______________________________________________________________________________________"<< endl;
        cout <<endl;


        cout << "Ingrese una opcion: ";
        cin>>Opcion;
        cin.ignore();

        switch (Opcion)
        {

        case 'a':
        case 'A':
        {
            Alta_Provincia();
        }
        break;

        case 'B':
        case 'b':
        {
            Mostrar_Provincias();
        }
        break;

        case 'C':
        case 'c':
        {
            Alta_Candidato();
        }
        break;

        case 'D':
        case 'd':
        {
            Mostrar_Candidatos();
        }
        break;
        case 'E':
        case 'e':
        {
            Alta_Puesto();
        }
        break;

        case 'F':
        case 'f':
        {
            Mostrar_Puestos();
        }
        break;

        case 'G':
        case 'g':
        {
            Alta_Partido();
        }
        break;

        case 'H':
        case 'h':
        {
            Mostrar_Partidos();
        }
        break;
        case 'I':
        case 'i':
        {
            Mostrar_Votos();
        }
        break;
        case 'J':
        case 'j':
        {
            Mostrar_Votantes();
        }
        break;

        case 'S':
        case 's':
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
// METODO    : void AuxiliaresView::Menu_Datos_Sistema()
// ACCION    : Muestra la cabecera de todas las pantallas
// PARAMETROS: NADA
// DEVUELVE  : NADA
//---------------------------------------------------------------------------
void AuxiliaresView::Menu_Datos_Sistema()
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);

    cout << "======================================================================================="<< endl;
    cout << "                    SEV - SISTEMA ELECTRONICO DE VOTACION" << endl;
    cout << "                    GOBIERNO NACIONAL DE LA REPUBLICA ARGENTINA" << endl;
    cout << "                    ELECCIONES 2019 - PRESIDENTE/VICEPRESIDENTE/GOBERNADOR" << endl;
    cout << endl;
    cout << "======================================================================================="<< endl;
    cout << endl;

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);


}
//---------------------------------------------------------------------------
// METODO    : char AuxiliaresView::ValidarOpcion_char(char *Mensaje, char *MensajeError)
// ACCION    : Valida un ingreso char
// PARAMETROS: char *Mensaje, char *MensajeError
// DEVUELVE  : opcion seleccionada
//---------------------------------------------------------------------------
char AuxiliaresView::ValidarOpcion_char(char *Mensaje, char *MensajeError)
{
    char Result, Ingreso;
    bool IngresoValido = false;

    do
    {
        cout << Mensaje;
        cin >> Ingreso;

        if( (Ingreso >= 97 and Ingreso <= 122) or (Ingreso >= 65 and Ingreso <= 90) )
        {
            IngresoValido = true;
        }
        else
        {
            cout << MensajeError << endl;
            cin.ignore();
        }
    }
    while (!IngresoValido);

    Result = Ingreso;
    return Result;
}
//---------------------------------------------------------------------------
// METODO    : void AuxiliaresView::Alta_Partido()
// ACCION    : Da de alta una Partido
// PARAMETROS: NADA
// DEVUELVE  : NADA
//---------------------------------------------------------------------------
void AuxiliaresView::Alta_Partido()
{
    PartidoDTO      PartDTO;
    PartidoDAL      PartDAL;
    PuestoDAL       PuestoDAL;
    PuestoDTO       PuestoDTO;
    CandidatoDAL    CandDAL;
    CandidatoDTO    CandDTO;
    int ID;
    char Nombre[25], Cand[25],Puesto[25];

    cout << "Ingrese el nombre del partido: " ;
    cin.getline(Nombre,50);

    ID = PartDAL.Busco_ID(Nombre);

    if (ID == 0)
    {
        PartDTO.SetID_Partido(PartDAL.Mayor_ID());
        PartDTO.SetNombre(Nombre);

        for (int i=0; i<3; i++)
        {
            cout << "Ingrese el nombre del puesto: " ;
            cin.getline (Puesto,25);
            PartDTO.SetID_Puesto(PuestoDAL.Busco_ID(Puesto));

            cout << "Ingrese el nombre del candidato: " ;
            cin.getline (Cand,25);
            PartDTO.SetID_Candidato(CandDAL.Busco_ID(Cand));

            PartDAL.Guardar_EnDisco(PartDTO);
        }
    }
}
//---------------------------------------------------------------------------
// METODO    : void AuxiliaresView::Alta_Candidato()
// ACCION    : Da de alta un Candidato
// PARAMETROS: NADA
// DEVUELVE  : NADA
//---------------------------------------------------------------------------
void AuxiliaresView::Alta_Candidato()
{
    CandidatoDTO CandDTO;
    CandidatoDAL CandDAL;
    char Nombre[25], Apellido[25];
    int ID;

    cout << "Ingrese el Apellido del candidado: ";
    cin.getline (Apellido,25);
    cout << "Ingrese el nombre del candidado: ";
    cin.getline (Nombre,25);

    ID = CandDAL.Busco_ID(Apellido);

    if(ID == 0)
    {
        CandDTO.SetApellido(Apellido);
        CandDTO.SetNombre(Nombre);
        CandDTO.SetID_Candidato(CandDAL.Mayor_ID());

        if (CandDAL.Guardar_EnDisco(CandDTO))
        {
            cout << "Candidato dada de alta correctamente" << endl;
        }
        else
        {
            cout << "error al dar de alta la provincia" << endl;
        }
    }
    else
    {
        cout << "La provincia ya se encuentra dada de alta"<< endl;
    }
    system("pause");
}
//---------------------------------------------------------------------------
// METODO    : void AuxiliaresView::Mostrar_Candidatos()
// ACCION    : Lista todos los candidatos
// PARAMETROS: NADA
// DEVUELVE  : NADA
//---------------------------------------------------------------------------
void AuxiliaresView::Mostrar_Candidatos()
{
    CandidatoDAL CandDAL;
    CandidatoDTO CandDTO;

    int Pos = 0;

    cout.width(5);
    cout << left<<"ID";
    cout.width(25);
    cout << left<<"Nombre";
    cout.width(25);
    cout << left<<"Apellido";
    cout.width(5);
    cout << left<<"Votos" << endl ;

    while (CandDAL.Leer_DeDisco(Pos,CandDTO))
    {
        cout.width(5);
        cout << left << CandDTO.GetID_Candidato() ;
        cout.width(25);
        cout <<left << CandDTO.GetNombre();
        cout.width(25);
        cout <<left << CandDTO.GetApellido();
        cout.width(5);
        cout << left << CandDTO.GetVotos() << endl;
        Pos++;
    }
    system("pause");
}
//---------------------------------------------------------------------------
// METODO    : void AuxiliaresView::Mostrar_Puestos()
// ACCION    : Lista todos los Puestos
// PARAMETROS: NADA
// DEVUELVE  : NADA
//---------------------------------------------------------------------------
void AuxiliaresView::Mostrar_Puestos()
{
    PuestoDAL PuestoDAL;
    PuestoDTO PuestoDTO;

    int Pos = 0;

    cout.width(5);
    cout << left<<"ID";
    cout.width(40);
    cout << left<<"Descripcion" << endl;
    cout << endl;


    while (PuestoDAL.Leer_DeDisco(Pos,PuestoDTO))
    {
        cout.width(5);
        cout << left << PuestoDTO.GetID_Puesto() ;
        cout.width(40);
        cout <<left << PuestoDTO.GetDescripcion() << endl;
        Pos++;
    }
    cout << endl;
    system("pause");
}
//---------------------------------------------------------------------------
// METODO    : void AuxiliaresView::Mostrar_Partidos()
// ACCION    : Lista todos los Partidos
// PARAMETROS: NADA
// DEVUELVE  : NADA
//---------------------------------------------------------------------------
void AuxiliaresView::Mostrar_Partidos()
{
    PartidoDAL PartDAL;
    PartidoDTO PartDTO;

    int Pos = 0;

    cout.width(10);
    cout << left<<"ID";
    cout.width(50);
    cout << left<<"Nombre";
    cout.width(10);
    cout << left<<"ID Puesto";
    cout.width(10);
    cout << left<<"ID Candidato" << endl;
    cout << endl;

    while (PartDAL.Leer_DeDisco(Pos,PartDTO))
    {
        cout.width(10);
        cout << left<<PartDTO.GetID_Partido();
        cout.width(50);
        cout << left<<PartDTO.GetNombre();
        cout.width(10);
        cout << left<<PartDTO.GetID_Puesto();
        cout.width(10);
        cout << left<<PartDTO.GetID_Candidato() << endl;
        Pos++;
    }
    cout << endl;
    system("pause");
}
//---------------------------------------------------------------------------
// METODO    : int AuxiliaresView::Validar_Int(char *Mensaje, char *MensajeError)
// ACCION    : valida un ingreso de un caracter
// PARAMETROS: char *Mensaje, char *MensajeError
// DEVUELVE  : Opcion seleccionada
//---------------------------------------------------------------------------
int AuxiliaresView::Validar_Int(char *Mensaje, char *MensajeError)
{
    char  Ingreso;
    int Result = 0;
    bool IngresoValido = false;

    do
    {
        cout << Mensaje;
        cin >> Ingreso;

        if(Ingreso >= 49 and Ingreso <= 52 )
        {
            IngresoValido = true;
        }
        else
        {
            cout << MensajeError << endl;
            cin.ignore();
        }
    }
    while (!IngresoValido);

    Result = Ingreso -48;

    return Result;
}
//---------------------------------------------------------------------------
// METODO    : void AuxiliaresView::Mostrar_Votos()
// ACCION    : Lista todos los Votos
// PARAMETROS: NADA
// DEVUELVE  : NADA
//---------------------------------------------------------------------------
void AuxiliaresView::Mostrar_Votos()
{
    VotoDAL VotDAL;
    VotoDTO VotDTO;

    int Pos = 0;

    cout.width(10);
    cout << left<<"ID";
    cout.width(10);
    cout << left<<"DNI";
    cout.width(25);
    cout << left<<"ID Presidente";
    cout.width(25);
    cout << left<<"ID VicePresidente" ;
    cout.width(25);
    cout << left<<"ID Gobernador"  << endl;
    cout << endl;

    while (VotDAL.Leer_DeDisco(Pos,VotDTO))
    {
        cout.width(10);
        cout << left << VotDTO.GetID_Voto() ;
        cout.width(10);
        cout << left << VotDTO.GetDNI() ;
        cout.width(25);
        cout <<left << VotDTO.GetID_Presidente() ;
        cout.width(25);
        cout <<left << VotDTO.GetID_VicePresidente();
        cout.width(25);
        cout <<left << VotDTO.GetID_Gobernador()<< endl;
        Pos++;
    }
    cout << endl;
    system("pause");
}
//---------------------------------------------------------------------------
// METODO    : void AuxiliaresView::Mostrar_Votantes()
// ACCION    : Lista todos los Votantes
// PARAMETROS: NADA
// DEVUELVE  : NADA
//---------------------------------------------------------------------------
void AuxiliaresView::Mostrar_Votantes()
{
    VotanteDAL VotDAL;
    VotanteDTO VotDTO;

    int Pos = 0;

    cout.width(10);
    cout << left<<"DNI";
    cout.width(25);
    cout << left<<"Nombre";
    cout.width(25);
    cout << left<<"Apellido";
    cout.width(30);
    cout << left<<"Direccion" ;
    cout.width(15);
    cout << left<<"Provincia";
    cout.width(5);
    cout << left<<"Edad" << endl;
    cout << endl;

    while (VotDAL.Leer_DeDisco(Pos,VotDTO))
    {
        cout.width(10);
        cout << left<<VotDTO.GetDNI();
        cout.width(25);
        cout << left<<VotDTO.GetNombre();
        cout.width(25);
        cout << left<<VotDTO.GetApellido();
        cout.width(30);
        cout << left<<VotDTO.GetDireccion();
        cout.width(15);
        cout << left<<VotDTO.GetID_Provincia();
        cout.width(5);
        cout << left<<VotDTO.GetEdad() << endl;
        Pos++;
    }
    cout << endl;
    system("pause");
}
//---------------------------------------------------------------------------
// METODO    : Menu con ayuda para el usuario
// PARAMETROS: NADA
// DEVUELVE  : NADA
//---------------------------------------------------------------------------
void AuxiliaresView::Ayuda()
{
    system("cls");

    Menu_Datos_Sistema();

    cout << "                           AYUDA" << endl;
    cout << "_______________________________________________________________________________________"<< endl;
    cout << endl;
    cout << "  MODULO ALTA: se ingresa un votante al sistema que no se encuentre en los padrones" <<endl;
    cout << endl;

    cout << "  CONSULTA PADRONES: Se verifica si el votante se encuentra en los padros y es apto"<<endl;
    cout << "  para votar" <<endl;
    cout << endl;

    cout << "  VOTAR: en este modulo se puede ingresar un voto, el usuario podra elegir entre los"<<endl;
    cout << "  distintos puestos(presidente, vicepresidente y gobernador), una vez seleccionado el "<<endl;
    cout << "  puesto se le mostrara todos los partidos politicos disponibles para seleccionar, "<<endl;
    cout << "  cuando finalice podra elegir otro puesto, asi esta completar todos los puestos."<<endl;
    cout << endl;

    cout << "  RESULTADOS DE ELECCION: En este modulo se puede ver como se encuentran los resultados" <<endl;
    cout << "   de las votaciones, aperturado por Puestos y por partido Politico " << endl;
    cout << endl;


    system("Pause");


}

