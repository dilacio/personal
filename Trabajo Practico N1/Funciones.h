#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

using namespace std;

const char Ruta_Sueldos[] = "Sueldos.dat";
const char Ruta_Freelance[] = "Freelance.dat";
const char Ruta_Horas[] = "Horas.dat";

struct Tipo_Precio
{
    int ID_Posicion;
    char Posicion[15];
    float Sueldo;
};

struct Freelance
{
    int DNI;
    char Nombre[20];
    char Apellido[20];
    int ID_Posicion;
    int Horas = 0;
    bool Baja = false;
};


//---------------------------------------------------------------------------
// FUNCION   : void strToUpper(char *Cadena)
// ACCION    : Convierte una cadena a mayuscula
// PARAMETROS: Puntero char
// DEVUELVE  : NADA
//---------------------------------------------------------------------------
void strToUpper(char *Cadena)
{
    int i = 0, Caracter=0;
    while (Cadena[i] != '\0')
    {
        Caracter = Cadena[i] ;

        if (Caracter > 96 && Caracter < 123)
        {
            Caracter = Caracter - 32;
        }
        Cadena [i] = Caracter;
        i++;
    }
}
//---------------------------------------------------------------------------
// FUNCION   : char ValidarOpcion(char *Mensaje, char *MensajeError)
// ACCION    : Valida el ingreso correcto de una opcion de menú
// PARAMETROS: Puntero char mensaje, puntero char del mensaje de error
// DEVUELVE  : char con la opcion valida
//---------------------------------------------------------------------------
char ValidarOpcion(char *Mensaje, char *MensajeError)
{
    char Result, Ingreso[3];
    bool IngresoValido = false;
    do
    {
        cout << Mensaje;
        sys::getline(Ingreso,3);
        if(strlen(Ingreso) == 1)
        {
            IngresoValido = true;
        }
        else
        {
            cout << MensajeError;
            cin.get();
        }
    }
    while (!IngresoValido);

    Result = Ingreso[0];
    return Result;
}
//---------------------------------------------------------------------------
// FUNCION   : bool Valida_Opcion_Volver ()
// ACCION    : Valida si el usuario quiere volver al menu anterior
// PARAMETROS: NADA
// DEVUELVE  : 1 - si desea volver
//             0 - si no desea volver
//---------------------------------------------------------------------------
bool Valida_Opcion_Volver ()
{
    bool Salir=false;
    char Val_Salir[3];

    system("cls");

    cout << "Esta usted seguro que quiere volver al menu anterior? SI/NO :" ;
    cin.getline(Val_Salir,3);

    strToUpper(Val_Salir);

    if (strcmp(Val_Salir,"SI") == 0)
    {
        Salir=true;
    }
    else
    {
        if(strcmp(Val_Salir,"NO") != 0)
        {
            cout << "opcion no valida" << endl;
            system("pause");
        }
    }
    return Salir;
}
//---------------------------------------------------------------------------
// FUNCION   : bool Existe_File(const char *Ruta)
// ACCION    : Valida si existe un archivo en la ruta obtenida por parametro
// PARAMETROS: Ruta del archivo
// DEVUELVE  : 1 - si existe
//             0 - si no existe
//---------------------------------------------------------------------------
bool Existe_File(const char *Ruta)
{
    bool Resultado=false;
    FILE *Archivo;

    Archivo = fopen(Ruta,"ab");

    if(Archivo != NULL)
    {
        Resultado = true;
        fclose(Archivo);
    }
    return Resultado;
}
//---------------------------------------------------------------------------
// FUNCION   : void Busco_Posicion(int IDPosicion, char* Posicion)
// ACCION    : Busca una posicion a partir de un ID de posicion
// PARAMETROS: int ID_POsicion, puntero char Posicion
// DEVUELVE  : NADA
//---------------------------------------------------------------------------
void Busco_Posicion(int IDPosicion, char* Posicion)
{
    FILE *Archivo;
    Tipo_Precio Registro;

    Archivo = fopen(Ruta_Sueldos,"rb");

    if (Archivo != NULL)
    {
        while (fread(&Registro,sizeof (Tipo_Precio),1,Archivo))
        {
            if(Registro.ID_Posicion == IDPosicion)
            {
                fclose(Archivo);
                strcpy(Posicion,Registro.Posicion);
            }
        }
    }
    fclose(Archivo);
}
//---------------------------------------------------------------------------
// FUNCION   : bool Guardar_Tipo(const char *Ruta,Tipo_Precio *Registro)
// ACCION    : Guardaa un registro en el archivo de sueldos
// PARAMETROS: Ruta del archivo, Estructura a grabar
// DEVUELVE  : 1 - si grabo con exito
//             0 - si no pudo guardar el registro
//---------------------------------------------------------------------------
bool Guardar_Tipo(const char *Ruta,Tipo_Precio *Registro)
{
    bool Resultado = false;
    FILE *Archivo;

    Archivo = fopen(Ruta, "ab");

    if(fwrite(Registro, sizeof (Tipo_Precio), 1,Archivo) == 1)
    {
        Resultado = true;
        fclose(Archivo);
    }
    return Resultado;
}
//---------------------------------------------------------------------------
// FUNCION   : void Crea_Limpia_Archivo(const char *Ruta)
// ACCION    : limpia o si no existe crea un archivo
// PARAMETROS: Ruta del archivo
// DEVUELVE  : NADA
//---------------------------------------------------------------------------
void Crea_Limpia_Archivo(const char *Ruta)
{
    FILE *Archivo;

    Archivo = fopen(Ruta,"wb");

    if (Archivo != NULL)
    {
        fclose(Archivo);
    }
}
//---------------------------------------------------------------------------
// FUNCION   : bool Crear_Tipo_Precio (const char *Ruta)
// ACCION    : Crea un registro de tipo-precio
// PARAMETROS: Ruta del archivo, Estructura a grabar
// DEVUELVE  : 1 - si creo con exito
//             0 - si no pudo crear el registro
//---------------------------------------------------------------------------
bool Crear_Tipo_Precio (const char *Ruta)
{
    Tipo_Precio Registro;
    bool Resultado = false;

    if (Existe_File(Ruta))
    {
        cout << "Ingrese el ID de posicion: " ;
        cin >> Registro.ID_Posicion;
        cin.ignore();

        cout << "Ingrese la posicion: " ;
        sys::getline(Registro.Posicion,15);

        cout << "Ingrese el Precio hora: ";
        cin >> Registro.Sueldo ;

        cin.ignore();

        Guardar_Tipo(Ruta,&Registro);
        Resultado = true;
    }
    return Resultado;
}
//---------------------------------------------------------------------------
// FUNCION   : void Mostrar_Tipo_Precio(const char *Ruta)
// ACCION    : Lista los registros del archivo de sueldos
// PARAMETROS: Ruta del archivo
// DEVUELVE  : NADA
//---------------------------------------------------------------------------
void Mostrar_Tipo_Precio(const char *Ruta)
{
    FILE *Archivo;
    Tipo_Precio Registro;

    cout << "_____________________________________________________________" << endl;

    if(Existe_File(Ruta))
    {
        Archivo = fopen(Ruta,"rb");

        cout.width(30);
        cout << "Posicion";

        cout.width(20);
        cout << "Valor Hora"<< endl;

        while(fread(&Registro, sizeof (Tipo_Precio),1,Archivo))
        {
            cout.width(30);
            cout << Registro.Posicion;

            cout.width(20);
            cout << Registro.Sueldo << endl;
        }
    }
    else
    {
        cout <<"El archivo no existe";
    }
    fclose(Archivo);
    cout << "_____________________________________________________________" << endl;
}
//---------------------------------------------------------------------------
// FUNCION   : bool Existe_DNI(int DNI)
// ACCION    : Verifica si existe un dni en el archivo de Freelance
// PARAMETROS: DNI
// DEVUELVE  : 1 - si existe
//             0 - si no existe
//---------------------------------------------------------------------------
bool Existe_DNI(int DNI)
{
    bool Resultado=false;
    FILE *Archivo;
    Freelance Registro;

    Archivo = fopen(Ruta_Freelance,"rb");

    while (fread(&Registro, sizeof (Freelance),1,Archivo))
    {
        if (Registro.DNI == DNI && Registro.Baja == false)
        {
            Resultado = true;
        }
    }
    fclose(Archivo);

    return Resultado;
}
//---------------------------------------------------------------------------
// FUNCION   : bool Guardar_Frelance(const char *Ruta,Freelance *Registro)
// ACCION    : Guarda un registro en el archivo de freelance
// PARAMETROS: Ruta del archivo, estructura de Freelance
// DEVUELVE  : 1 - si pudo guardarlo
//             0 - si no pudo guardarlo
//---------------------------------------------------------------------------
bool Guardar_Frelance(const char *Ruta,Freelance *Registro)
{
    bool Resultado = false;
    FILE *Archivo;

    Archivo = fopen(Ruta, "ab+");

    if(fwrite(Registro, sizeof (Freelance), 1,Archivo) == 1)
    {
        Resultado = true;
        fclose(Archivo);
    }

    return Resultado;
}
//---------------------------------------------------------------------------
// FUNCION   : int Busca_IDPosicion (char Posicion[15])
// ACCION    : Busca un ID de posicion a partir de una cadena de posicion
// PARAMETROS: int ID_POsicion, puntero char Posicion
// DEVUELVE  : NADA
//---------------------------------------------------------------------------
int Busca_IDPosicion (char Posicion[15])
{
    int Resultado = 0;
    FILE *Archivo;
    Tipo_Precio Registro;

    Archivo = fopen(Ruta_Sueldos,"rb");
    if(Archivo != NULL)
    {
        while (fread(&Registro,sizeof (Tipo_Precio),1,Archivo))
        {
            strToUpper(Posicion);
            strToUpper(Registro.Posicion);

            if(strcmp(Posicion,Registro.Posicion) == 0)
            {
                Resultado = Registro.ID_Posicion;
                fclose(Archivo);
                return Resultado;
            }
        }
        fclose(Archivo);
        return Resultado;
    }
}
//---------------------------------------------------------------------------
// FUNCION   : int Busco_Sueldo(const char *Ruta, int ID_Posicion)
// ACCION    : busco el campo sueldo apartir de un ID de posicion
// PARAMETROS: Ruta del archivo, ID posicion
// DEVUELVE  : int Sueldo
//--------------------------------------------------------------------------
int Busco_Sueldo(const char *Ruta, int ID_Posicion)
{
    FILE *Archivo;
    Tipo_Precio Registro;
    int Resultado = 0;

    Archivo = fopen(Ruta, "rb");

    if (Archivo!= NULL)
    {
        while (fread(&Registro,sizeof(Tipo_Precio),1,Archivo))
        {
            if(Registro.ID_Posicion == ID_Posicion)
            {
                Resultado = Registro.Sueldo;
            }
        }
    }
    else
    {
        cout << "Error al leer el archivo de Tipo_Precio" << endl;
    }
    fclose(Archivo);

    return Resultado;
}

//---------------------------------------------------------------------------
// FUNCION   : bool Crear_Freelance(const char *Ruta)
// ACCION    : Crea un registro para grabar en el archivo de Freelance
// PARAMETROS: Ruta del archivo
// DEVUELVE  : 1 - si lo pudo crear
//             0 - si no pudo crearlo
//---------------------------------------------------------------------------
bool Crear_Freelance(const char *Ruta)
{
    bool Resultado= false;
    Freelance Registro;
    int ID_Posicion;
    char Posicion[15];

    if (Existe_File(Ruta))
    {
        cout << "Ingrese el DNI: " ;
        cin >> Registro.DNI;
        cin.ignore();

        cout << "Ingrese el nombre: " ;
        sys::getline(Registro.Nombre,20);

        cout << "Ingrese el Apellido: " ;
        sys::getline(Registro.Apellido,20);

        cout << "Ingrese la posicion: " ;
        sys::getline(Posicion,15);

        ID_Posicion = Busca_IDPosicion (Posicion);

        Registro.ID_Posicion = ID_Posicion;

        cin.ignore();

        Guardar_Frelance(Ruta,&Registro);
        Resultado = true;
    }
    return Resultado;
}
//---------------------------------------------------------------------------
// FUNCION   : void Mostrar_Freelances(const char *Ruta)
// ACCION    : Lista todos los Freelance que existen en el archivo
// PARAMETROS: Ruta del archivo
// DEVUELVE  : NADA
//--------------------------------------------------------------------------
void Mostrar_Freelances(const char *Ruta,bool Mostrar_Horas)
{
    char Posicion[15];
    int ID_Posicion;
    FILE *Archivo;
    Freelance Registro;

    if(Existe_File(Ruta))
    {
        Archivo = fopen(Ruta,"rb");

        cout<<" _________________________________________________________________________ "<<endl;
        while(fread(&Registro, sizeof (Freelance),1,Archivo))
        {
            Busco_Posicion(Registro.ID_Posicion,Posicion);

            cout.width(10);
            cout << Registro.DNI;
            cout.width(20);
            cout << Registro.Nombre;
            cout.width(20);
            cout << Registro.Apellido;
            cout.width(20);
            cout << Posicion ;

            if (Mostrar_Horas)
            {
                cout.width(10);
                cout << Registro.Horas ;
            }
            cout << endl;
        }
        cout<<" _________________________________________________________________________ "<<endl;
        system("pause");
    }
    else
    {
        cout <<"El archivo no existe";
    }
    fclose(Archivo);
}
//---------------------------------------------------------------------------
// FUNCION   : void Mostrar_Freelance(Freelance Registro)
// ACCION    : Muestra un freelance
// PARAMETROS: Freelance a mostrar
// DEVUELVE  : NADA
//---------------------------------------------------------------------------
void Mostrar_Freelance(Freelance Registro, bool Mostrar_Hora)
{
    char Posicion[15];

    cout.width(10);
    cout << "DNI";

    cout.width(20);
    cout << "Nombre";

    cout.width(20);
    cout << "Apellido";

    cout.width(20);
    cout << "Posicion" ;

    if (Mostrar_Hora)
    {

        cout.width(10);
        cout << "Horas"  ;
    }
    cout << endl;

    cout.width(10);
    cout << Registro.DNI;

    cout.width(20);
    cout << Registro.Nombre;

    cout.width(20);
    cout << Registro.Apellido;

    Busco_Posicion(Registro.ID_Posicion,Posicion);

    cout.width(20);
    cout << Posicion ;

    if (Mostrar_Hora)
    {
        cout.width(10);
        cout << Registro.Horas;
    }

}
//---------------------------------------------------------------------------
// FUNCION   : int Posicion_Freelance(int DNI,const char *Ruta)
// ACCION    : Busca la posicion de un freelance en un archivo
// PARAMETROS: DNI del freelance a buscar, y la ruta del archivo
// DEVUELVE  : posicion del registro
//---------------------------------------------------------------------------
int Posicion_Freelance(int DNI,const char *Ruta)
{
    int Resultado = -1,Contador = 0;
    FILE *Archivo;
    Freelance Registro;

    Archivo = fopen(Ruta,"rb");

    while (fread(&Registro,sizeof (Freelance),1,Archivo))
    {
        if(Registro.DNI == DNI)
        {
            Resultado = Contador;
            fclose(Archivo);
            return Resultado;
        }
        Contador ++;
    }
    fclose(Archivo);
    return Resultado;
}

//---------------------------------------------------------------------------
// FUNCION   : struct Freelance Busco_Freelance(int DNI,const char *Ruta)
// ACCION    : Busca un freelance con todos sus campos
// PARAMETROS: DNI del freelance a buscar, y la ruta del archivo
// DEVUELVE  : estructura con la informacion del registro
//---------------------------------------------------------------------------
struct Freelance Busco_Freelance(int DNI,const char *Ruta)
{
    Freelance Registro;
    FILE *Archivo;

    Archivo = fopen(Ruta,"rb");

    while(fread(&Registro,sizeof (Freelance), 1, Archivo))
    {
        if(DNI == Registro.DNI)
        {
            fclose(Archivo);
            return Registro;
        }
    }
}
//---------------------------------------------------------------------------
// FUNCION   : bool Modificar_Freelance (Freelance *Registro, const char *Ruta)
// ACCION    : Modifica un freelance
// PARAMETROS: estructura con las modificaciones, la ruta del archivo
// DEVUELVE  : true si modifico bien
//             false si no pudo abrir el archivo
//---------------------------------------------------------------------------
bool Modificar_Freelance (Freelance *Registro, const char *Ruta)
{
    bool Resultado = false;
    int Posicion;
    FILE *Archivo;

    Posicion = Posicion_Freelance(Registro->DNI,Ruta);

    Archivo= fopen(Ruta,"rb+");

    fseek(Archivo,sizeof (Freelance)*Posicion, SEEK_SET);

    if(fwrite(Registro,sizeof (Freelance),1,Archivo) == 1)
    {
        Resultado = true;
        fclose(Archivo);
    }

    return Resultado;
}
//-----------------------------------------------------------------------------
// FUNCION : int strSub(char *Cad, char *SCad)
// ACCION : busca una subcadena dentro de una cadena.
// PARAMETROS: cadena, subcadena.
// DEVUELVE : int - la posición inicial de la subcadena.
//            int - un -1 si no se encuentra.
//-----------------------------------------------------------------------------
int strSub(char *Cad, char *SCad)
{
    int x=0, Cont=0, z=0, Pos;
    bool Ba=0;
    while (Cad[x]!='\0' && SCad[z]!='\0')
    {
        if (Cad[x]==SCad[z])
        {
            if(Ba==0)
            {
                Pos=x;
                Ba=1;
            }
            Cont++;
            x++;
            z++;
        }
        else
        {
            Cont=0;
            x++;
            z=0;
            Ba=0;
        }
    }
    if (Cont==strlen(SCad))
    {
        return Pos;
    }
    else
    {
        return -1;
    }
}

//---------------------------------------------------------------------------
// FUNCION   : void Listado_Freelance_PorCadena (char *Cadena)
// ACCION    : funcion para realizar el listado por freelance
// PARAMETROS: Cadena a buscar
// DEVUELVE  : NADA
//--------------------------------------------------------------------------
void Listado_Freelance_PorCadena (char *Cadena)
{
    FILE *Archivo;
    Freelance Registro;
    int Sueldo;
    char Cadena_Nombre[20], Cadena_Apellido[20];

    Archivo = fopen (Ruta_Freelance,"rb");
    cout << "_____________________________________________________________________________________________" << endl;

    if (Archivo != NULL)
    {
        while (fread(&Registro,sizeof (Freelance),1,Archivo))
        {
            if(Registro.Baja == false)
            {

                strcpy(Cadena_Nombre,Registro.Nombre);
                strToUpper(Cadena_Nombre);
                strcpy(Cadena_Apellido,Registro.Apellido);
                strToUpper(Cadena_Apellido);
                strToUpper(Cadena);

                if( strSub(Cadena_Nombre,Cadena) != -1 || strSub(Cadena_Apellido,Cadena)!= -1  )
                {
                    Mostrar_Freelance(Registro,true);
                    Sueldo = (Busco_Sueldo(Ruta_Sueldos,Registro.ID_Posicion) * Registro.Horas);

                    cout.width(10);
                    cout << "Sueldo: ";
                    cout << Sueldo << endl;
                    cout << "_____________________________________________________________________________________________" << endl;
                }

            }
        }
    }
}
//---------------------------------------------------------------------------
// FUNCION   : int Cuento_Cantidad_X_Tipo(int ID_Posicion)
// ACCION    : cuento la cantidad de horas por tipo de freelance
// PARAMETROS: int ID de posicion
// DEVUELVE  : int Cantidad contada
//--------------------------------------------------------------------------
int Cuento_Cantidad_X_Tipo(int ID_Posicion)
{
    FILE *Archivo;
    Freelance Registro;
    int Resultado = 0;

    Archivo = fopen(Ruta_Freelance,"rb");

    if (Archivo != NULL)
    {
        while (fread(&Registro,sizeof (Freelance),1,Archivo))
        {
            if(Registro.ID_Posicion == ID_Posicion && Registro.Baja == false)
            {
                Resultado += Registro.Horas;
            }
        }
        fclose(Archivo);
    }
    return Resultado;
}
//---------------------------------------------------------------------------
// FUNCION   : void Listado_Total_Tipo(const char *Ruta_Sueldos)
// ACCION    : Funcion listado por tipo
// PARAMETROS: Ruta del archivo
// DEVUELVE  : NADA
//--------------------------------------------------------------------------
void Listado_Total_Tipo(const char *Ruta_Sueldos)
{
    FILE *Archivo;
    Tipo_Precio Registro;
    int Cantidad_Horas = 0,Sueldo = 0, Total = 0, Total_Sumarizado = 0, Horas_Totales=0;

    Archivo = fopen(Ruta_Sueldos,"rb");

    if(Archivo != NULL)
    {
        cout << "_______________________________________________________" << endl;
        cout.width(20);
        cout<< "Puesto";

        cout.width(20);
        cout<< "Horas trabajadas";

        cout.width(15);
        cout<< "Sueldo" << endl;
        while (fread(&Registro, sizeof (Tipo_Precio),1,Archivo))
        {

            Cantidad_Horas = Cuento_Cantidad_X_Tipo(Registro.ID_Posicion);
            Sueldo = Busco_Sueldo(Ruta_Sueldos,Registro.ID_Posicion);

            Total = Cantidad_Horas * Sueldo;
            Total_Sumarizado += Total;

            Horas_Totales += Cantidad_Horas;

            cout.width(20);
            cout<< Registro.Posicion;

            cout.width(20);
            cout<< Cantidad_Horas;

            cout.width(15);
            cout<< Total << endl;

        }
        fclose(Archivo);

        cout<< endl;
        SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),240);

        cout.width(20);
        cout <<"Total : ";

        cout.width(20);
        cout << Horas_Totales ;

        cout.width(15);
        cout << Total_Sumarizado << endl;

        SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),15);
        cout << "_______________________________________________________" << endl;
    }

}
//---------------------------------------------------------------------------
// FUNCION   : void Listado_Total_Tipo_Detalle(const char *Ruta_Sueldos)
// ACCION    : lista los freelance por tipo
// PARAMETROS: Ruta del archivo
// DEVUELVE  : NADA
//--------------------------------------------------------------------------
void Listado_Total_Tipo_Detalle(const char *Ruta_Sueldos)
{
    FILE *File_Sueldo;
    FILE *File_Free;
    Tipo_Precio Reg_Sueldo;
    Freelance Reg_Free;
    float Sueldo, Sueldo_Total;
    char Posicion[20];
    int Cant_Horas, Color = 1, X;

    File_Sueldo = fopen(Ruta_Sueldos,"rb");

    cout << "___________________________________________________________________________" << endl;

    if (File_Sueldo != NULL)
    {
        while (fread(&Reg_Sueldo,sizeof(Tipo_Precio),1,File_Sueldo))
        {
            cout << "     " << Reg_Sueldo.Posicion<< endl;

            SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),12);

            cout.width(10);
            cout << "DNI" ;

            cout.width(20);
            cout << "Nombre";

            cout.width(20);
            cout << "Apellido";

            cout.width(10);
            cout << "Horas" ;

            cout.width(15);
            cout << "Sueldo" << endl;


            File_Free = fopen(Ruta_Freelance,"rb");
            Sueldo_Total=0;
            Cant_Horas=0;

            if(File_Free!=NULL)
            {
                while (fread(&Reg_Free,sizeof (Freelance),1,File_Free))
                {
                    if(Reg_Sueldo.ID_Posicion == Reg_Free.ID_Posicion && Reg_Free.Baja == false)
                    {
                        Sueldo = 0;

                        cout.width(10);
                        cout << Reg_Free.DNI;

                        cout.width(20);
                        cout << Reg_Free.Nombre;

                        cout.width(20);
                        cout << Reg_Free.Apellido;

                        cout.width(10);
                        cout << Reg_Free.Horas ;

                        Sueldo = (Reg_Free.Horas * Reg_Sueldo.Sueldo);

                        cout.width(15);
                        cout << Sueldo << endl ;


                        Sueldo_Total += Sueldo;
                        Cant_Horas += Reg_Free.Horas;
                    }
                }
            }

            SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),240);

            cout << endl;
            cout.width(40);
            cout <<"Total : ";

            cout.width(20);
            cout << Cant_Horas;
            cout.width(15);
            cout << Sueldo_Total << endl;

            SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),15);
            cout << "___________________________________________________________________________" << endl;
        }
    }
}
//---------------------------------------------------------------------------
// FUNCION   : bool Elimina_Freelance (int DNI)
// ACCION    : Busca y elimina un Freelance atraves de un DNI
// PARAMETROS: DNI del freelance
// DEVUELVE  : true si lo elimino, false si no pudo eliminarlo.
//--------------------------------------------------------------------------
bool Elimina_Freelance (int DNI)
{
    FILE *Archivo;
    Freelance Registro;
    int Posicion;

    Archivo = fopen(Ruta_Freelance,"rb+");

    if (Archivo != NULL)
    {
        while (fread(&Registro,sizeof (Freelance),1,Archivo))
        {
            if (Registro.DNI == DNI && Registro.Baja == false)
            {
                Posicion = Posicion_Freelance(DNI,Ruta_Freelance);

                Registro.Baja = true;

                fseek(Archivo,sizeof (Freelance)*Posicion, SEEK_SET);

                if(fwrite(&Registro,sizeof (Freelance),1,Archivo) )
                {
                    fclose(Archivo);
                    return true;
                }
            }
        }
    }

    return false;

}

void Listado_Freelance_Baja()
{
    FILE *Archivo;
    Freelance Registro;
    int Contador=0;

    Archivo = fopen(Ruta_Freelance,"rb");

    if (Archivo != NULL)
    {
        while (fread(&Registro,sizeof(Freelance),1,Archivo))
        {
            if (Registro.Baja == true)
            {
                Contador ++;

                Mostrar_Freelance(Registro,false);
                cout << endl;
            }
        }
        fclose(Archivo);
    }

    if (Contador == 0)
    {
        cout << "No existen Freelances dados de baja!!! " << endl;
        cout << endl;
    }
}
void Listado_Free_Rango_Sueldo()
{
    int Max=0, Min=0, Contador = 0;
    FILE *Archivo;
    Freelance Registro;
    float Sueldo;

    cout << "Ingrese el sueldo minimo a filtrar: ";
    cin >> Min;

    cout << "Ingrese el sueldo Maximo a filtrar: ";
    cin >> Max;

    Archivo = fopen(Ruta_Freelance,"rb");

    if (Archivo != NULL)
    {
        cout.width(10);
        cout << "DNI" ;

        cout.width(20);
        cout << "Nombre";

        cout.width(20);
        cout << "Apellido";

        cout.width(15);
        cout << "Sueldo" << endl;

        while (fread(&Registro,sizeof(Freelance),1,Archivo))
        {
            Sueldo = (Busco_Sueldo(Ruta_Sueldos,Registro.ID_Posicion) * Registro.Horas);

            if (Sueldo > Min && Sueldo < Max && Registro.Baja == false)
            {
                Contador ++;



                cout.width(10);
                cout << Registro.DNI;

                cout.width(20);
                cout << Registro.Nombre;

                cout.width(20);
                cout << Registro.Apellido;

                cout.width(15);
                cout << Sueldo << endl;

            }
        }
        fclose(Archivo);
    }

    if (Contador == 0)
    {
        cout << endl;
        cout << "No se encontraron Freelances para ese rango de precio" << endl;
    }
}
#endif // FUNCIONES_H_INCLUDED
