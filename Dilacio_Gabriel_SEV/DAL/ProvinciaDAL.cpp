#include "ProvinciaDAL.h"

//---------------------------------------------------------------------------
// METODO    : int ProvinciaDAL::Mayor_ID ()
// ACCION    : Busca el siguiete ID para grabar un nuevo registro
// PARAMETROS: NADA
// DEVUELVE  : int --> ID Nuevo
//---------------------------------------------------------------------------
int ProvinciaDAL::Mayor_ID ()
{
    FILE *Archivo;
    ProvinciaDTO Obj;
    int Max = 0;

    Archivo = fopen(Ruta_Provincia,"rb");

    if(Archivo != NULL)
    {
        while (fread(&Obj,sizeof(ProvinciaDTO),1,Archivo))
        {
            if(Obj.GetID_Provincia()>Max)

                Max = Obj.GetID_Provincia();
        }
        fclose(Archivo);
    }
    Max ++;
    return Max;
}
//---------------------------------------------------------------------------
// METODO    : bool ProvinciaDAL::Existe(char* Prov)
// ACCION    : Verifica si existe una provincia
// PARAMETROS: char* Prov --> nombre de la provincia a buscar
// DEVUELVE  : true si grabo, false si no grabo
//---------------------------------------------------------------------------
bool ProvinciaDAL::Existe(char* Prov)
{
    FILE *Archivo;
    bool Resultado = false;
    ProvinciaDTO Obj;

    Archivo = fopen(Ruta_Provincia, "rb");

    if (Archivo != NULL)
    {
        while (fread(&Obj, sizeof (ProvinciaDTO),1,Archivo))
        {
            if (strcmp(Obj.GetNombre(),Prov)==0)
            {
                Resultado = true;
            }
        }
        fclose(Archivo);
    }
    return Resultado;
}
//---------------------------------------------------------------------------
// METODO    : bool ProvinciaDAL::Guardar_EnDisco(ProvinciaDTO Reg)
// ACCION    : Guarda un registro en el archivo de Provincias
// PARAMETROS: ProvinciaDTO --> registro a guardar
// DEVUELVE  : true si grabo, false si no grabo
//---------------------------------------------------------------------------
bool ProvinciaDAL::Guardar_EnDisco(ProvinciaDTO Reg)
{
    FILE *Archivo;
    bool Resultado = false;

    Archivo = fopen(Ruta_Provincia,"ab");

    if (Archivo != NULL)
    {
        if (fwrite(&Reg,sizeof (ProvinciaDTO),1,Archivo))
        {
            Resultado = true;
        }
        fclose(Archivo);
    }
    return Resultado;
}
//---------------------------------------------------------------------------
// METODO    : int ProvinciaDAL::Busco_ID (char* Prov)
// ACCION    : Busca un ID de provincia por medio de un nombre de provincia
// PARAMETROS: char* Prov --> Nombre a buscar
// DEVUELVE  : int --> ID encontrado
//---------------------------------------------------------------------------
int ProvinciaDAL::Busco_ID (char* Prov)
{
    FILE *Archivo;
    ProvinciaDTO Reg;
    int Resultado = 0;
    Auxiliar Aux;

    Archivo = fopen(Ruta_Provincia,"rb");

    if (Archivo != NULL)
    {
        while (fread(&Reg,sizeof (ProvinciaDTO),1,Archivo))
        {
            if (strcmp(Aux.toUpper(Reg.GetNombre()),Aux.toUpper(Prov)) == 0)
            {
                Resultado = Reg.GetID_Provincia();
            }
        }
        fclose(Archivo);
    }
    return Resultado;
}
//---------------------------------------------------------------------------
// METODO    : bool ProvinciaDAL::Leer_DeDisco(int Pos, ProvinciaDTO &Obj)
// ACCION    : Lee un registro del archivo por medio de una posicion de registro
// PARAMETROS: int Pos, ProvinciaDTO &Obj --> Posicion a leer y objeto a cargar datos
// DEVUELVE  : true si leyo, false si no leyo
//---------------------------------------------------------------------------
bool ProvinciaDAL::Leer_DeDisco(int Pos, ProvinciaDTO &Obj)
{
    FILE *Archivo;

    Archivo = fopen(Ruta_Provincia, "rb");

    if (Archivo != NULL)
    {
        fseek(Archivo,sizeof (ProvinciaDTO)*Pos,SEEK_SET);

        if (fread(&Obj, sizeof(ProvinciaDTO),1,Archivo))
        {
            fclose(Archivo);
            return true;
        }

    }
    return false;
}
