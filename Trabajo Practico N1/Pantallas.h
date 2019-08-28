#ifndef PANTALLAS_H_INCLUDED
#define PANTALLAS_H_INCLUDED


using namespace std;


//---------------------------------------------------------------------------
// FUNCION   : void Menu_Principal ()
// ACCION    : Muestra el texto del menu principal
// PARAMETROS: NADA.
// DEVUELVE  : NADA
//---------------------------------------------------------------------------
void Menu_Principal ()
{

    sys::cls();

    cout<<" ___________________________________________________________ "<<endl;
    cout<<"|                       MENU PRINCIPAL                      |"<<endl;
    cout<<"|___________________________________________________________|"<<endl;
    cout<<"|                                                           |"<<endl;
    cout<<"|   A - CONFIGURACION PRECIO-HORA                           |"<<endl;
    cout<<"|   B - ABM FREELANCER                                      |"<<endl;
    cout<<"|   C - CARGA DE HORAS                                      |"<<endl;
    cout<<"|   D - LISTADOS Y BUSQUEDAS                                |"<<endl;
    cout<<"|   E - AYUDA                                               |"<<endl;
    cout<<"|                                                           |"<<endl;
    cout<<"|   S - Salir                                               |"<<endl;
    cout<<"|___________________________________________________________|"<<endl;

}

//---------------------------------------------------------------------------
// FUNCION   : void Pantalla_Conf_Precio_Hora()
// ACCION    : Muestra el texto del menu sueldos
// PARAMETROS: NADA.
// DEVUELVE  : NADA
//---------------------------------------------------------------------------

//TODO modificar pantalla con funcion correcta
void Pantalla_Conf_Precio_Hora()
{

    cout<<" ___________________________________________________________ "<<endl;
    cout<<"|              CONFIGURACION PRECIO-HORA                    |"<<endl;
    cout<<"|___________________________________________________________|"<<endl;
    cout<<"|                                                           |"<<endl;
    cout<<"|   A - Modificar valores                                   |"<<endl;
    cout<<"|                                                           |"<<endl;
    cout<<"|   V - Volver                                              |"<<endl;
    cout<<"|___________________________________________________________|"<<endl;

}
//---------------------------------------------------------------------------
// FUNCION   : void Pantalla_AM_Freelance()
// ACCION    : Muestra el texto del menu de Alta y  Modificacion de Frealances
// PARAMETROS: NADA.
// DEVUELVE  : NADA
//---------------------------------------------------------------------------
void Pantalla_AM_Freelance()
{
    sys::cls();

    cout<<" ___________________________________________________________ "<<endl;
    cout<<"|              ALTA/MODIFICACION FREELANCE                  |"<<endl;
    cout<<"|___________________________________________________________|"<<endl;
    cout<<"|                                                           |"<<endl;
    cout<<"|   A - Agregar Freelance                                   |"<<endl;
    cout<<"|   B - Modificar Freelance                                 |"<<endl;
    cout<<"|   C - Dar de baja un Freelance                            |"<<endl;
    cout<<"|                                                           |"<<endl;
    cout<<"|   V - Volver                                              |"<<endl;
    cout<<"|___________________________________________________________|"<<endl;
}
void Pantalla_AM_Freelance_2()
{
    cout<<" ___________________________________________________________ "<<endl;
    cout<<"|              SELECCIONE EL CAMPO A MODIFICAR              |"<<endl;
    cout<<"|___________________________________________________________| "<<endl;
    cout<<"|                                                           |"<<endl;
    cout<<"|   A - Nombre                                              |"<<endl;
    cout<<"|   B - Apellido                                            |"<<endl;
    cout<<"|   C - Posicion                                            |"<<endl;
    cout<<"|                                                           |"<<endl;
    cout<<"|   V - Volver                                              |"<<endl;
    cout<<"|___________________________________________________________|"<<endl;
    cout << endl;
}
//---------------------------------------------------------------------------
// FUNCION   : void Pantalla_Carga_Hora()
// ACCION    : Muestra el texto del menu de tratamiento de horas
// PARAMETROS: NADA.
// DEVUELVE  : NADA
//---------------------------------------------------------------------------
void Pantalla_Carga_Hora()
{
    sys::cls();

    cout<<" ___________________________________________________________ "<<endl;
    cout<<"|              TRATAMIENTO DE HORAS                         |"<<endl;
    cout<<"|___________________________________________________________|"<<endl;
    cout<<"|                                                           |"<<endl;
    cout<<"|   A - Carga Masiva de Horas                               |"<<endl;
    cout<<"|   B - Carga Individual                                    |"<<endl;
    cout<<"|                                                           |"<<endl;
    cout<<"|   V - Volver                                              |"<<endl;
    cout<<"|___________________________________________________________|"<<endl;
}
//---------------------------------------------------------------------------
// FUNCION   : void Pantalla_Listados_Busquedas()
// ACCION    : Muestra el texto del menu de Listados y Busquedas
// PARAMETROS: NADA.
// DEVUELVE  : NADA
//---------------------------------------------------------------------------
//TODO modificar el D
void Pantalla_Listados_Busquedas()
{
    sys::cls();

    cout<<" ___________________________________________________________ "<<endl;
    cout<<"|              LISTADOS Y BUSQUEDAS                         |"<<endl;
    cout<<"|___________________________________________________________|"<<endl;
    cout<<"|                                                           |"<<endl;
    cout<<"|   A - Busqueda de freelance                               |"<<endl;
    cout<<"|   B - Listado de precio/Hora por tipo de Freelance        |"<<endl;
    cout<<"|   C - Listado de Horas por mes y por tipo de Freelance    |"<<endl;
    cout<<"|   D - Totalizador de horas por tipo y freelance           |"<<endl;
    cout<<"|   E - Listado Freelance dados de baja                     |"<<endl;
    cout<<"|   F - Listado de Freelance por Rango de precio            |"<<endl;
    cout<<"|                                                           |"<<endl;
    cout<<"|   V - Volver                                              |"<<endl;
    cout<<"|___________________________________________________________|"<<endl;
}

//---------------------------------------------------------------------------
// FUNCION   : void Pantalla_Listados_Busquedas()
// ACCION    : Muestra el texto del menu de Listados y Busquedas
// PARAMETROS: NADA.
// DEVUELVE  : NADA
//---------------------------------------------------------------------------
//TODO modificar el D
void Pantalla_Ayuda()
{
    sys::cls();

    cout <<" ___________________________________________________________" << endl;
    cout <<"|			  MENU AYUDA	                    |" << endl;
    cout <<"|___________________________________________________________|" << endl;
    cout <<"|                                                           |" << endl;
    cout <<"|                MODIFICAR PRECIO POR HORA                  |" << endl;
    cout <<"|___________________________________________________________|" << endl;
    cout <<"|             Esta opci\242n te permite modificar              |" << endl;
    cout <<"|             el valor de la hora por cada tipo             |" << endl;
    cout <<"|               de freelancer, tanto de forma               |" << endl;
    cout <<"|                  general como individual                  |" << endl;
    cout <<"|___________________________________________________________|" << endl;
    cout <<"|                                                           |" << endl;
    cout <<"|               AGREGAR/MODIFICAR FREELANCER                |" << endl;
    cout <<"|___________________________________________________________|" << endl;
    cout <<"|            En este apartado podes agregar                 |" << endl;
    cout <<"|             y/o modificar un freelancer                   |" << endl;
    cout <<"|             a partir del n\243mero de DNI                    |" << endl;
    cout <<"|___________________________________________________________|" << endl;
    cout <<"|                                                           |" << endl;
    cout <<"|               CARGAR HORAS DE TRABAJO                     |" << endl;
    cout <<"|___________________________________________________________|" << endl;
    cout <<"|            Con esta opci\242n le podes asignar               |" << endl;
    cout <<"|              la cantidad de horas trabajadas              |" << endl;
    cout <<"|             a cada freelancer, tambi\202n de                 |" << endl;
    cout <<"|              manera general como individial               |" << endl;
    cout <<"|___________________________________________________________|" << endl;
    cout <<"|                                                           |" << endl;
    cout <<"|                  BUSCAR FREELANCER                        |" << endl;
    cout <<"|___________________________________________________________|" << endl;
    cout <<"|                En esta opci\242n podes buscar                |" << endl;
    cout <<"|            freelancers mediante nombre o apellido         |" << endl;
    cout <<"|                                                           |" << endl;
    cout <<"|___________________________________________________________|" << endl;
    cout <<"|                                                           |" << endl;
    cout <<"|                LISTAR LOS PRECIOS POR HORA                |" << endl;
    cout <<"|___________________________________________________________|" << endl;
    cout <<"|               Crea una tabla con el precio                |" << endl;
    cout <<"|              por hora correspondiente a cada              |" << endl;
    cout <<"|                    tipo de freelancer                     |" << endl;
    cout <<"|___________________________________________________________|" << endl;
    cout <<"|                                                           |" << endl;
    cout <<"|                TOTAL HORAS POR ESPECIALIDAD               |" << endl;
    cout <<"|___________________________________________________________|" << endl;
    cout <<"|              Crea una tabla con el total de horas         |" << endl;
    cout <<"|               discriminado por tipo de freelancer         |" << endl;
    cout <<"|                                                           |" << endl;
    cout <<"|___________________________________________________________|" << endl;
    cout <<"|             Crea tres tablas discriminadas por            |" << endl;
    cout <<"|            tipo de freelancer y cada una posee            |" << endl;
    cout <<"|                 un total de horas y sueldo                |" << endl;
    cout <<"|                     por cada freelancer                   |" << endl;
    cout <<"|                                                           |" << endl;
    cout <<"|___________________________________________________________|" << endl;
}

//---------------------------------------------------------------------------
// FUNCION   : void PresBienvenida()
// ACCION    : Muestra el texto de la primera pantalla que ve el usuario
// PARAMETROS: NADA.
// DEVUELVE  : NADA
//---------------------------------------------------------------------------
void PresBienvenida()
{

    cout << endl;
    cout << "                 __  __                   _                             " << endl;
    cout << "                |  \\/  |   __ _    __ _  (_)   ___                     " << endl;
    cout << "                | |\\/| |  / _` |  / _` | | |  / __|                    " << endl;
    cout << "                | |  | | | (_| | | (_| | | | | (__                      " << endl;
    cout << "                |_|  |_|  \\__,_|  \\__, | |_|  \\___|                  " << endl;
    cout << "                                  |___/                                 " << endl;
    cout << "     ____             __   _                                            " << endl;
    cout << "    / ___|    ___    / _| | |_  __      __   __ _   _ __    ___         " << endl;
    cout << "    \\___ \\   / _ \\  | |_  | __| \\ \\ /\\ / /  / _` | | '__|  / _ \\ " << endl;
    cout << "     ___) | | (_) | |  _| | |_   \\ V  V /  | (_| | | |    |  __/       " << endl;
    cout << "    |____/   \\___/  |_|    \\__|   \\_/\\_/    \\__,_| |_|     \\___|  " << endl;
    cout << "                         ____           _                               " << endl;
    cout << "                        / ___|         / \\                             " << endl;
    cout << "                        \\___ \\        / _ \\                          " << endl;
    cout << "                         ___) |  _   / ___ \\                           " << endl;
    cout << "                        |____/  (_) /_/   \\_\\                         " << endl;
    cout << "                                                                        " << endl;
    cout << "          ___              _                      _                     " << endl;
    cout << "         / __|  ___   ___ | |_   ___   _ _     __| |  ___               " << endl;
    cout << "        | (_ | / -_) (_-< |  _| / _ \\ | '_|   / _` | / -_)             " << endl;
    cout << "         \\___| \\___| /__/  \\__| \\___/ |_|     \\__,_| \\___|        " << endl;
    cout << "                            _                   _                       " << endl;
    cout << "       ___   _ __    _ __  | |  ___   __ _   __| |  ___   ___           " << endl;
    cout << "      / -_) | '  \\  | '_ \\ | | / -_) / _` | / _` | / _ \\ (_-<        " << endl;
    cout << "      \\___| |_|_|_| | .__/ |_| \\___| \\__,_| \\__,_| \\___/ /__/      " << endl;
    cout << "                    |_|                                                 " << endl;
}

//---------------------------------------------------------------------------
// FUNCION   : void Pantalla_Salida ()
// ACCION    : Muestra la pantalla de salida
// PARAMETROS: NADA
// DEVUELVE  : NADA
//---------------------------------------------------------------------------
void Pantalla_Salida ()
{
    system("cls");
    cout << " ________________________________________________________"<<endl;
    cout << "|                                                        |" <<endl;
    cout << "|                                                        |" <<endl;
    cout << "|           GRACIAS POR HABER UTILIZADO EL SISTEMA       |" << endl;
    cout << "|                                                        |" <<endl;
    cout << "|                                                        |" <<endl;
    cout << " ________________________________________________________"<<endl;
    cout <<endl;
}
#endif // PANTALLAS_H_INCLUDED
