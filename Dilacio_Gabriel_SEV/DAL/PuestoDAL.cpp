#include "PuestoDAL.h"

//---------------------------------------------------------------------------
// METODO    : int PuestoDAL::Busco_ID(char* Puesto)
// ACCION    : Busca un ID de candidato por medio de un nombre de puesto
// PARAMETROS: char* Cand --> Nombre a buscar
// DEVUELVE  : int --> ID encontrado
//---------------------------------------------------------------------------
int PuestoDAL::Busco_ID(char* Puesto)
{
    FILE *Archivo;
    PuestoDTO Reg;
    int Resultado = 0;
    Auxiliar Aux;
    char Nombre[25];


    Archivo = fopen(Ruta_Puesto,"rb");

    if (Archivo != NULL)
    {
        while (fread(&Reg,sizeof (PuestoDTO),1,Archivo))
        {
            strcpy(Nombre,Puesto);

            if (strcmp(Aux.toUpper(Reg.GetDescripcion()),Aux.toUpper(Nombre)) == 0)
            {
                Resultado = Reg.GetID_Puesto();
            }
        }
        fclose(Archivo);
    }
    return Resultado;
}
//---------------------------------------------------------------------------
// METODO    : int PuestoDAL::Mayor_ID ()
// ACCION    : Busca el siguiete ID para grabar un nuevo registro
// PARAMETROS: NADA
// DEVUELVE  : int --> ID Nuevo
//---------------------------------------------------------------------------
int PuestoDAL::Mayor_ID ()
{
    FILE *Archivo;
    PuestoDTO Obj;
    int Max = 0;

    Archivo = fopen(Ruta_Puesto,"rb");

    if(Archivo != NULL)
    {
        while (fread(&Obj,sizeof(PuestoDTO),1,Archivo))
        {
            if(Obj.GetID_Puesto()>Max)

                Max = Obj.GetID_Puesto();
        }
        fclose(Archivo);
    }
    Max ++;
    return Max;
}
//---------------------------------------------------------------------------
// METODO    : bool PuestoDAL::Guardar_EnDisco(PuestoDTO dto)
// ACCION    : Guarda un registro en el archivo de puestos
// PARAMETROS: PuestoDTO --> registro a guardar
// DEVUELVE  : true si grabo, false si no grabo
//---------------------------------------------------------------------------
bool PuestoDAL::Guardar_EnDisco(PuestoDTO dto)
{
    FILE *Archivo;
    bool Resultado= false;

    Archivo = fopen(Ruta_Puesto, "ab");

    if (Archivo != NULL)
    {
        if (fwrite(&dto, sizeof (PuestoDTO),1,Archivo))
        {
            Resultado = true;
            fclose(Archivo);
        }
    }
    return Resultado;
}
//---------------------------------------------------------------------------
// METODO    : bool PuestoDAL::Leer_DeDisco(int Pos, PuestoDTO &Obj)
// ACCION    : Lee un registro del archivo por medio de una posicion de registro
// PARAMETROS: int Pos, PuestoDTO &Obj --> Posicion a leer y objeto a cargar datos
// DEVUELVE  : true si leyo, false si no leyo
//---------------------------------------------------------------------------
bool PuestoDAL::Leer_DeDisco(int Pos, PuestoDTO &Obj)
{
    FILE *Archivo;

    Archivo = fopen(Ruta_Puesto, "rb");

    if (Archivo != NULL)
    {
        fseek(Archivo,sizeof (PuestoDTO)*Pos,SEEK_SET);

        if (fread(&Obj, sizeof(PuestoDTO),1,Archivo))
        {
            fclose(Archivo);
            return true;
        }

    }
    return false;
}
//---------------------------------------------------------------------------
// METODO    : char* PuestoDAL::Busco_Nombre(int ID)
// ACCION    : busca un nombre por un ID
// PARAMETROS: Int ID --> ID a buscar
// DEVUELVE  : Nombre del puesto
//---------------------------------------------------------------------------
char* PuestoDAL::Busco_Nombre(int ID)
{
    PuestoDTO PuestDTO;
    FILE *Archivo;

    Archivo = fopen(Ruta_Puesto,"rb");

    if (Archivo != NULL)
    {
        while (fread(&PuestDTO,sizeof(PuestoDTO),1,Archivo))
        {
            if  (ID == PuestDTO.GetID_Puesto())
            {
                fclose(Archivo);
                return PuestDTO.GetDescripcion();
            }
        }
    }
    return "No Se Encontro";
}
