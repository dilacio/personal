#include "CandidatoDAL.h"
#include <cstdio>
#include "../DTO/CandidatoDTO.h"

//---------------------------------------------------------------------------
// METODO    : bool CandidatoDAL::Guardar_EnDisco(CandidatoDTO dto)
// ACCION    : Guarda un registro en el archivo de candidatos
// PARAMETROS: CandidatoDTO --> registro a guardar
// DEVUELVE  : true si grabo, false si no grabo
//---------------------------------------------------------------------------
bool CandidatoDAL::Guardar_EnDisco(CandidatoDTO dto)
{
    FILE *Archivo;
    bool Resultado= false;

    Archivo = fopen(Ruta_Candidato, "ab");

    if (Archivo != NULL)
    {
        if (fwrite(&dto, sizeof (CandidatoDTO),1,Archivo))
        {
            Resultado = true;
            fclose(Archivo);
        }
    }
    return Resultado;
}
//---------------------------------------------------------------------------
// METODO    : int CandidatoDAL::Busco_ID (char* Cand)
// ACCION    : Busca un ID de candidato por medio de un nombre de candidato
// PARAMETROS: char* Cand --> Nombre a buscar
// DEVUELVE  : int --> ID encontrado
//---------------------------------------------------------------------------
int CandidatoDAL::Busco_ID (char* Cand)
{
    FILE *Archivo;
    CandidatoDTO Reg;
    int Resultado = 0;
    Auxiliar Aux;
    char Apellido[25];


    Archivo = fopen(Ruta_Candidato,"rb");

    if (Archivo != NULL)
    {
        while (fread(&Reg,sizeof (CandidatoDTO),1,Archivo))
        {
            strcpy(Apellido,Cand);

            if (strcmp(Aux.toUpper(Reg.GetApellido()),Aux.toUpper(Apellido)) == 0)
            {
                Resultado = Reg.GetID_Candidato();
            }
        }
        fclose(Archivo);
    }
    return Resultado;
}
//---------------------------------------------------------------------------
// METODO    : int CandidatoDAL::Mayor_ID ()
// ACCION    : Busca el siguiete ID para grabar un nuevo registro
// PARAMETROS: NADA
// DEVUELVE  : int --> ID Nuevo
//---------------------------------------------------------------------------
int CandidatoDAL::Mayor_ID ()
{
    FILE *Archivo;
    CandidatoDTO Obj;
    int Max = 0;
//---------------------------------------------------------------------------
// METODO    : bool CandidatoDAL::Leer_DeDisco(int Pos, CandidatoDTO &Obj)
// ACCION    : Lee un registro del archivo por medio de una posicion de registro
// PARAMETROS: int Pos, CandidatoDTO &Obj --> Posicion a leer y objeto a cargar datos
// DEVUELVE  : true si leyo, false si no leyo
//---------------------------------------------------------------------------
    Archivo = fopen(Ruta_Candidato,"rb");

    if(Archivo != NULL)
    {
        while (fread(&Obj,sizeof(CandidatoDTO),1,Archivo))
        {
            if(Obj.GetID_Candidato()>Max)

                Max = Obj.GetID_Candidato();
        }
        fclose(Archivo);
    }
    Max ++;
    return Max;
}
//---------------------------------------------------------------------------
// METODO    : bool CandidatoDAL::Leer_DeDisco(int Pos, CandidatoDTO &Obj)
// ACCION    : Lee un registro del archivo por medio de una posicion de registro
// PARAMETROS: int Pos, CandidatoDTO &Obj --> Posicion a leer y objeto a cargar datos
// DEVUELVE  : true si leyo, false si no leyo
//---------------------------------------------------------------------------
bool CandidatoDAL::Leer_DeDisco(int Pos, CandidatoDTO &Obj)
{
    FILE *Archivo;

    Archivo = fopen(Ruta_Candidato, "rb");

    if (Archivo != NULL)
    {
        fseek(Archivo,sizeof (CandidatoDTO)*Pos,SEEK_SET);

        if (fread(&Obj, sizeof(CandidatoDTO),1,Archivo))
        {
            fclose(Archivo);
            return true;
        }

    }
    return false;
}
//---------------------------------------------------------------------------
// METODO    : char* CandidatoDAL::Busco_Nombre(int ID)
// ACCION    : Busca el nombre por medio de un ID
// PARAMETROS: int ID --> ID a buscar
// DEVUELVE  : Cadena con el nombre
//---------------------------------------------------------------------------
char* CandidatoDAL::Busco_Nombre(int ID)
{
    CandidatoDTO CandDTO;
    FILE *Archivo;

    Archivo = fopen(Ruta_Candidato,"rb");

    if (Archivo != NULL)
    {
        while (fread(&CandDTO,sizeof(CandidatoDTO),1,Archivo))
        {
            if  (ID == CandDTO.GetID_Candidato())
            {
                fclose(Archivo);
                return CandDTO.GetNombre();
            }
        }
    }
    return "No Se Encontro";
}
//---------------------------------------------------------------------------
// METODO    : char* CandidatoDAL::Busco_Apellido(int ID)
// ACCION    : Busca el apellido por medio de un ID
// PARAMETROS: int ID --> ID a buscar
// DEVUELVE  : Cadena con el Apellido
//---------------------------------------------------------------------------
char* CandidatoDAL::Busco_Apellido(int ID)
{
    CandidatoDTO CandDTO;
    FILE *Archivo;

    Archivo = fopen(Ruta_Candidato,"rb");

    if (Archivo != NULL)
    {
        while (fread(&CandDTO,sizeof(CandidatoDTO),1,Archivo))
        {
            if  (ID == CandDTO.GetID_Candidato())
            {
                fclose(Archivo);
                return CandDTO.GetApellido();
            }
        }
    }
    return "No Se Encontro";
}
//---------------------------------------------------------------------------
// METODO    : int CandidatoDAL::Busco_Posicion(int ID_Candidato)
// ACCION    : Busca la posicion que ocupa un candidato en un archivo
// PARAMETROS: int ID --> ID a buscar
// DEVUELVE  : Posicion dentro del archivo
//---------------------------------------------------------------------------
int CandidatoDAL::Busco_Posicion(int ID_Candidato)
{
    FILE *Archivo;
    CandidatoDTO CandDTO;
    int Posicion_Final = 0, Pos=0;

    Archivo = fopen(Ruta_Candidato,"rb");

    if (Archivo != NULL)
    {
        while (fread(&CandDTO,sizeof(CandidatoDTO),1,Archivo))
        {
            if (ID_Candidato == CandDTO.GetID_Candidato())
            {
                Posicion_Final = Pos;
            }
            Pos ++;
        }
        fclose(Archivo);
    }
    return Posicion_Final;
}
//---------------------------------------------------------------------------
// METODO    : bool CandidatoDAL::Modificar(int Pos,CandidatoDTO Reg)
// ACCION    : Modifica un registro por medio de una posicion
// PARAMETROS: int Pos,CandidatoDTO Reg --> Posicion dentro del archivo, nuevo registro
// DEVUELVE  : Posicion dentro del archivo
//---------------------------------------------------------------------------
bool CandidatoDAL::Modificar(int Pos,CandidatoDTO Reg)
{
    FILE *Archivo;
    bool Resultado = false;

    Archivo = fopen(Ruta_Candidato,"rb+");

    if (Archivo != NULL)
    {
        fseek(Archivo,sizeof (CandidatoDTO)*Pos,SEEK_SET);
        if (fwrite(&Reg,sizeof (CandidatoDTO),1,Archivo))
        {
            Resultado = true;
        }
        fclose(Archivo);
    }
    return Resultado;
}
