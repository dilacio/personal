#ifndef MENUS_H_INCLUDED
#define MENUS_H_INCLUDED

using namespace std;

//---------------------------------------------------------------------------
// FUNCION   : Menu_Conf_Precio_Hora()
// ACCION    : Contiene la logica del menu de Configuracion Precio Hora
// PARAMETROS: NADA.
// DEVUELVE  : NADA
//---------------------------------------------------------------------------
void Menu_Conf_Precio_Hora()
{
    char Opcion, Val_Salir[3], Reg_Modificacion[15];
    bool Salir = false,Creo = false,Limpio = false ;

    while (!Salir)
    {
        system("cls");

        Mostrar_Tipo_Precio(Ruta_Sueldos);


        Pantalla_Conf_Precio_Hora();
        Opcion = ValidarOpcion("Ingrese una Opcion: ", "Opcion no valida");

        switch (Opcion)
        {
        case 'A':
        case 'a':
        {
            Crea_Limpia_Archivo(Ruta_Sueldos);

            for (int i=0; i<3; i++)
            {
                Creo = Crear_Tipo_Precio(Ruta_Sueldos);
                cout << endl;

                if (!Creo)
                {
                    cout << "Error al crear el registro" << endl;
                    i = 4;
                }
            }
            system("pause");
            cin.get();
        }
        break;

        case 'V':
        case 'v':
        {
            Salir = Valida_Opcion_Volver();
        }
        break;

        default:
        {
            cout<<"Opcion no valida"<<endl;
            system("pause");
        }
        break;
        }
    }
}
//---------------------------------------------------------------------------
// FUNCION   : void Menu_M_Freelance()
// ACCION    : Contiene la logica del menu de modificacion de un freelance
// PARAMETROS: NADA.
// DEVUELVE  : NADA
//---------------------------------------------------------------------------
void Menu_M_Freelance()
{
    int DNI_Ingreso, ID_Posicion;;
    Freelance Registro;
    char Opcion_Modificacion,Posicion[20];

    bool Volver=false;

    system("cls");

    cout << "Ingrese el DNI a modificar: ";

    cin >> DNI_Ingreso;
    cin.ignore();

    if(!Existe_DNI(DNI_Ingreso))
    {
        cout << "El Dni no existe o esta dado de baja" << endl;
        system("pause");
    }
    else
    {
        while (!Volver)
        {

            Registro = Busco_Freelance(DNI_Ingreso,Ruta_Freelance);

            system("cls");
            Mostrar_Freelance(Registro,false);
            cout << endl;
            Pantalla_AM_Freelance_2();

            Opcion_Modificacion = ValidarOpcion("Ingrese una Opcion: ", "Opcion no valida");

            switch(Opcion_Modificacion)
            {
            case 'A':
            case 'a':
            {
                cout << "Ingrese el nuevo Nombre: ";
                sys::getline(Registro.Nombre,20);

                Modificar_Freelance(&Registro, Ruta_Freelance);

                cout << endl;
                cout << "Se modifico con exito!!"<<endl;
            }
            break;
            case 'B':
            case 'b':
            {
                cout << "Ingrese el nuevo Apellido: ";
                sys::getline(Registro.Apellido,20);

                Modificar_Freelance(&Registro, Ruta_Freelance);


            }
            break;
            case 'C':
            case 'c':
            {
                cout << "Ingrese la nueva posicion: ";
                sys::getline(Posicion,20);

                ID_Posicion = Busca_IDPosicion(Posicion);
                Registro.ID_Posicion = ID_Posicion;

                Modificar_Freelance(&Registro, Ruta_Freelance);

            }
            break;
            case 'V':
            case 'v':
            {
                Volver = Valida_Opcion_Volver();

            }
            break;
            default:
            {
                cout<<"Opcion no valida"<<endl;
                system("pause");
            }
            }
            system("pause");
        }
    }
}
//---------------------------------------------------------------------------
// FUNCION   : void Pantalla_AM_Freelance()
// ACCION    : Contiene la logica del menu de Freelance
// PARAMETROS: NADA.
// DEVUELVE  : NADA
//---------------------------------------------------------------------------
void Menu_AM_Freelance()
{
    char Opcion, Val_Salir[3];
    bool Salir = false, Creo=false, Modifico = false;
    Freelance Registro;
    int DNI;

    while (!Salir)
    {
        Pantalla_AM_Freelance();

        Opcion = ValidarOpcion("Ingrese una Opcion: ", "Opcion no valida");

        switch (Opcion)
        {
        case 'A':
        case 'a':
        {

            Creo = Crear_Freelance(Ruta_Freelance);

            if(Creo)
                if(Creo)
                {
                    cout << "se dio de alta correctamente" <<endl;
                    system("pause");
                }
                else
                {
                    cout << "error al crear el alta";
                }
        }
        break;

        case 'B':
        case 'b':
        {
            Menu_M_Freelance();
        }
        break;

        case 'C':
        case 'c':
        {
            system("cls");

            cout << "Ingrese el DNI del freelance: ";
            cin >> DNI;

            if(Elimina_Freelance(DNI))
            {
                cout <<"Freelance dado de baja correctamente" << endl;
            }
            else
            {
                cout << "Error al dar de baja el Freelance"<< endl;
            }
            system("pause");
        }
        break;

        case 'D':
        case 'd':
        {
            Mostrar_Freelances(Ruta_Freelance,true);
        }
        break;

        case 'V':
        case 'v':
        {
            Salir = Valida_Opcion_Volver();
        }
        break;

        default:
        {
            cout<<"Opcion no valida"<<endl;
            system("pause");
        }
        break;
        }
    }
}

//---------------------------------------------------------------------------
// FUNCION   : Menu_Conf_Precio_Hora()
// ACCION    : Contiene la logica del menu de Configuracion Precio Hora
// PARAMETROS: NADA.
// DEVUELVE  : NADA
//---------------------------------------------------------------------------
void Menu_Carga_Horas()
{
    char Opcion, Val_Salir[3];
    bool Salir = false;
    Freelance Registro;
    FILE *Archivo;
    int DNI_Ingreso;

    while (!Salir)
    {
        Pantalla_Carga_Hora();

        Opcion = ValidarOpcion("Ingrese una Opcion: ", "Opcion no valida");

        switch (Opcion)
        {
        case 'A':
        case 'a':
        {
            if (Existe_File(Ruta_Freelance))
            {
                Archivo = fopen(Ruta_Freelance,"rb");

                while (fread(&Registro,sizeof (Freelance),1,Archivo))
                {
                    if (Registro.Baja == false)
                    {

                        Mostrar_Freelance(Registro,true);
                        cout << endl;

                        cout << "Ingrese la cantidad de horas: ";
                        cin >> Registro.Horas;

                        Modificar_Freelance(&Registro,Ruta_Freelance);

                    }
                }
                fclose(Archivo);
                cout << "La carga fue exitosa" << endl;
                system("pause");
            }

        }
        break;

        case 'B':
        case 'b':
        {
            system("cls");

            cout << "Ingrese el DNI a modificar: ";

            cin >> DNI_Ingreso;
            cin.ignore();

            Registro = Busco_Freelance(DNI_Ingreso,Ruta_Freelance);

            if (Registro.Baja == false)
            {
                Mostrar_Freelance(Registro,true);
                cout << endl;

                cout << "Ingrese la cantidad de horas: " ;
                cin >> Registro.Horas;

                Modificar_Freelance(&Registro,Ruta_Freelance);
            }
            else
            {
                cout << "Freelance dado de baja" << endl;
            }
            system("pause");

        }
        break;

        case 'C':
        case 'c':
        {

        }
        break;

        case 'V':
        case 'v':
        {
            Salir = Valida_Opcion_Volver();
        }
        break;

        default:
        {
            cout<<"Opcion no valida"<<endl;
            system("pause");
        }
        break;
        }
    }
}

//---------------------------------------------------------------------------
// FUNCION   : Menu_Conf_Precio_Hora()
// ACCION    : Contiene la logica del menu de Configuracion Precio Hora
// PARAMETROS: NADA.
// DEVUELVE  : NADA
//---------------------------------------------------------------------------
void Menu_Listados_Busquedas()
{
    char Opcion, Val_Salir[3], Cadena[20];
    bool Salir = false;

    while (!Salir)
    {
        Pantalla_Listados_Busquedas();
        Opcion = ValidarOpcion("Ingrese una Opcion: ", "Opcion no valida");

        switch (Opcion)
        {
        case 'A':
        case 'a':
        {
            system("cls");
            cout << "Ingrese la cadena a buscar: ";
            cin.getline(Cadena,20);

            Listado_Freelance_PorCadena(Cadena);
            system("pause");

        }
        break;

        case 'B':
        case 'b':
        {
            system("cls");
            Mostrar_Tipo_Precio(Ruta_Sueldos);

            system("pause");

        }
        break;

        case 'C':
        case 'c':
        {
            system("cls");
            Listado_Total_Tipo(Ruta_Sueldos);

            system("pause");

        }
        break;

        case 'D':
        case 'd':
        {
            system("cls");
            Listado_Total_Tipo_Detalle(Ruta_Sueldos);
            system("pause");

        }
        break;

        case 'E':
        case 'e':
        {
            system("cls");
            Listado_Freelance_Baja();
            system("pause");

        }
        break;

        case 'F':
        case 'f':
        {
            system("cls");
            Listado_Free_Rango_Sueldo();
            cout<< endl;
            system("pause");

        }
        break;

        case 'V':
        case 'v':
        {
            Salir = Valida_Opcion_Volver();
        }
        break;

        default:
        {
            cout<<"Opcion no valida"<<endl;
            system("pause");
        }
        break;
        }
    }
}
#endif // MENUS_H_INCLUDED
