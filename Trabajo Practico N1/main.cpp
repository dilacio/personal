//#############################################################################
// ARCHIVO             : main.cpp
// AUTOR/ES            : Dilacio Gabriel
// VERSION             : 0.01 beta.
// FECHA DE CREACION   : 19/04/2019.
// ULTIMA ACTUALIZACION: 01/05/2019.
// LICENCIA            : GPL (General Public License) - Version 3.
//
//  **************************************************************************
//  * El software libre no es una cuestion economica sino una cuestion etica *
//  **************************************************************************
//
// Este programa es software libre;  puede redistribuirlo  o  modificarlo bajo
// los terminos de la Licencia Publica General de GNU  tal como se publica por
// la  Free Software Foundation;  ya sea la version 3 de la Licencia,  o (a su
// eleccion) cualquier version posterior.
//
// Este programa se distribuye con la esperanza  de que le sea util,  pero SIN
// NINGUNA  GARANTIA;  sin  incluso  la garantia implicita de MERCANTILIDAD  o
// IDONEIDAD PARA UN PROPOSITO PARTICULAR.
//
// Vea la Licencia Publica General GNU para mas detalles.
//
// Deberia haber recibido una copia de la Licencia Publica General de GNU junto
// con este proyecto, si no es asi, escriba a la Free Software Foundation, Inc,
// 59 Temple Place - Suite 330, Boston, MA 02111-1307, EE.UU.

//=============================================================================
// SISTEMA OPERATIVO   : Linux (Ubuntu) / Windows XP / Windows 7.
// IDE                 : Code::Blocks - 8.02 / 10.05
// COMPILADOR          : GNU GCC Compiler (Linux) / MinGW (Windows).
// LICENCIA            : GPL (General Public License) - Version 3.
//=============================================================================
// DESCRIPCION:
//              Breve explicacion sobre el contenido del archivo.
//
////////////////////////////////////////////////////////////////////////////////

//*****************************************************************************
//                       CONFIGURACION MULTIPLATAFORMA
//=============================================================================
// COMPILACION EN WINDOWS
//-----------------------------------------------------------------------------
// Si este programa se va a compilar en Windows, descomente las tres lineas
// siguientes, y comente las tres lineas de "COMPILACION EN LINUX".
//-----------------------------------------------------------------------------
#ifndef _WIN32
# define _WIN32
#endif

//=============================================================================
// COMPILACION EN LINUX
//-----------------------------------------------------------------------------
// Si este programa se va a compilar en Linux, descomente las tres lineas
// siguientes, y comente las tres lineas de "COMPILACION EN WINDOWS".
//-----------------------------------------------------------------------------
//#ifndef _LINUX
//  # define _LINUX
//#endif

//*****************************************************************************
//                             INCLUSIONES ESTANDAR
//=============================================================================
#include <iostream> // Libreria de flujos de  Entrada/Salida  que contiene  los
// objetos cin, cout y endl.

#include <cstdlib>  // Libreria estandar que contiene la funcion exit().
#include <cstring>
#include <iostream>
#include <stdio.h>
//*****************************************************************************
//                             INCLUSIONES PERSONALES
//=============================================================================
#include "CSYSTEM/csystem.h" // Libreria para multiplataforma.
#include "Pantallas.h"
#include "Funciones.h"
#include "Menus.h"
//==============================================================================
// DECLARACION DEL ESPACIO DE NOMBRES POR DEFECTO
//------------------------------------------------------------------------------
using namespace std;



//==============================================================================
// FUNCION PRINCIPAL - PUNTO DE INICIO DEL PROYECTO
//------------------------------------------------------------------------------
int main()
{

    char Opcion;
    bool Salir = false;

    //PresBienvenida();
    //sys::msleep(4);

    while (!Salir)
    {
        Menu_Principal();
        Opcion = ValidarOpcion("Ingrese una Opcion: ", "Opcion no valida");

        switch (Opcion)
        {
        case 'A':
        case 'a':
        {
            Menu_Conf_Precio_Hora();

        }
        break;

        case 'B':
        case 'b':
        {
            Menu_AM_Freelance();
        }
        break;

        case 'C':
        case 'c':
        {
            Menu_Carga_Horas();
        }
        break;

        case 'D':
        case 'd':
        {
            Menu_Listados_Busquedas();
        }
        break;

        case 'E':
        case 'e':
        {
            Pantalla_Ayuda();
        }
        break;

        case 'S':
        case 's':
        {
            Pantalla_Salida();

            Salir=true;
        }
        break;

        default:
        {
            cout<<"Opcion no valida"<<endl;
        }
        break;
        }
        system("pause");
    }

    //--------------------------------------------------------------------------
    // FIN DE LA FUNCION main() SIN ERRORES.
    //--------------------------------------------------------------------------
    return 0;
}

//=============================================================================
//                            FIN DE ARCHIVO
//#############################################################################

