#include "PrincipalView.h"
//---------------------------------------------------------------------------
// METODO    : void PrincipalView::Presentacion()
// ACCION    : Pantalla de presentacion
// PARAMETROS: NADA
// DEVUELVE  : NADA
//---------------------------------------------------------------------------
void PrincipalView::Presentacion()
{
    for (int i = 1; i<11 ; i++)
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), i);
        system("cls");
        cout << endl;
        cout << endl;
        cout << endl;
        cout << endl;
        cout << "                   ____  ____  ___           ____  __  ____  ____  ____  _  _   __  "<<endl;
        cout << "                  / ___)(  __)/ __)   ___   / ___)(  )/ ___)(_  _)(  __)( \\/ ) / _\\ "<<endl;
        cout << "                  \\___ \\ ) _)( (__   (___)  \\___ \\ )( \\___ \\  )(   ) _) / \\/ \\/    \\ "<<endl;
        cout << "                  (____/(____)\\___)         (____/(__)(____/ (__) (____)\\_)(_/\\_/\\_/"<<endl;
        cout << "                   ____  ____    _  _   __  ____  __                                "<<endl;
        cout << "                  (    \\(  __)  / )( \\ /  \\(_  _)/  \\                               "<<endl;
        cout << "                   ) D ( ) _)   \\ \\/ /(  O ) )( (  O )                              "<<endl;
        cout << "                  (____/(____)   \\__/  \\__/ (__) \\__/                               "<<endl;
        cout << "                   ____  __    ____  ___  ____  ____   __   __ _  __  ___  __       "<<endl;
        cout << "                  (  __)(  )  (  __)/ __)(_  _)(  _ \\ /  \\ (  ( \\(  )/ __)/  \\      "<<endl;
        cout << "                   ) _) / (_/\\ ) _)( (__   )(   )   /(  O )/    / )(( (__(  O )     "<<endl;
        cout << "                  (____)\\____/(____)\\___) (__) (__\\_) \\__/ \\_)__)(__)\\___)\\__/       "<<endl;
        Sleep(300);
    }
}
//---------------------------------------------------------------------------
// METODO    : void PrincipalView::MenuPrincipal()
// ACCION    : Menu principal del programa
// PARAMETROS: NADA
// DEVUELVE  : NADA
//---------------------------------------------------------------------------
void PrincipalView::MenuPrincipal()
{
    bool Salir = false;
    char Opcion;
    Alta_VotanteView Modulo_Alta;
    AuxiliaresView Aux;
    VotarView Modulo_Votar;
    Consulta_PadronView Modulo_Consulta_Padron;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
    ResultadosView Resultados;


    while (!Salir)
    {
        system("cls");

        Aux.Menu_Datos_Sistema();
        cout << "                       MENU PRINCIPAL" << endl;
        cout << "_______________________________________________________________________________________"<< endl;
        cout << endl;
        cout << endl;
        cout << "                       A - ALTA DE VOTANTES" << endl;
        cout << "                       B - CONSULTA DE PADRONES" << endl;
        cout << "                       C - VOTAR" << endl;
        cout << "                       D - RESULTADO DE ELECCIONES" << endl;
        cout << "                       E - AUXILIARES" << endl;
        cout << endl;
        cout << "                       H - AYUDA" << endl;
        cout << "                       S - SALIR" << endl;
        cout << "                                           " <<endl;
        cout << "_______________________________________________________________________________________"<< endl;


        Opcion =  Aux.ValidarOpcion_char("Ingrese una Opcion: ", "Opcion no valida");
        switch (Opcion)
        {

        case 'a':
        case 'A':
        {
            Modulo_Alta.Menu();
        }
        break;

        case 'B':
        case 'b':
        {
            Modulo_Consulta_Padron.Consulta_Padron();

        }
        break;
        case 'C':
        case 'c':
        {
            Modulo_Votar.Menu();
        }
        break;
        case 'D':
        case 'd':
        {
            Resultados.Menu();
        }
        break;
        case 'E':
        case 'e':
        {
            Aux.Menu();
        }
        break;
        case 'H':
        case 'h':
        {
            Aux.Ayuda();
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
            cout << "Opcion no valida!" << endl;
            system("pause");

        }
        break;


        }
    }
}
//---------------------------------------------------------------------------
// METODO    : void PrincipalView::Despedida()
// ACCION    : Pantalla de despedida
// PARAMETROS: NADA
// DEVUELVE  : NADA
//---------------------------------------------------------------------------
void PrincipalView::Despedida()
{
    for (int i = 1; i<7 ; i++)
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), i);
        system("cls");

        cout << "                                                                 "<<endl;
        cout << "  ___  ____   __    ___  __   __   ____    ____   __  ____       "<<endl;
        cout << " / __)(  _ \\ / _\\  / __)(  ) / _\\ / ___)  (  _ \\ /  \\(  _ \\ "<<endl;
        cout << "( (_ \\ )   //    \\( (__  )( /    \\\\___ \\   ) __/(  O ))   /    "<<endl;
        cout << " \\___/(__\\_)\\_/\\_/ \\___)(__)\\_/\\_/(____/  (__)   \\__/(__\\_) "<<endl;
        cout << " _  _  ____  __  __    __  ____   __   ____                      "<<endl;
        cout << "/ )( \\(_  _)(  )(  )  (  )(__  ) / _\\ (  _ \\                   "<<endl;
        cout << ") \\/ (  )(   )( / (_/\\ )(  / _/ /    \\ )   /                    "<<endl;
        cout << "\\____/ (__) (__)\\____/(__)(____)\\_/\\_/(__\\_)                   "<<endl;
        cout << " ____  __      ____  __  ____  ____  ____  _  _   __             "<<endl;
        cout << "(  __)(  )    / ___)(  )/ ___)(_  _)(  __)( \\/ ) / _\\           "<<endl;
        cout << " ) _) / (_/\\  \\___ \\ )( \\___ \\  )(   ) _) / \\/ \\/    \\      "<<endl;
        cout << "(____)\\____/  (____/(__)(____/ (__) (____)\\_)(_/\\_/\\_/           "<<endl;
        Sleep(300);
    }
}
