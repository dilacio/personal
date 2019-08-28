#include "VotoDAL.h"
//---------------------------------------------------------------------------
// METODO    : bool VotoDAL::Guardar_EnDisco(VotoDTO dto)
// ACCION    : Guarda un registro en el archivo de voto
// PARAMETROS: VotoDTO --> registro a guardar
// DEVUELVE  : true si grabo, false si no grabo
//---------------------------------------------------------------------------
bool VotoDAL::Guardar_EnDisco(VotoDTO dto)
{
    FILE *Archivo;
    bool Resultado= false;

    Archivo = fopen(Ruta_Voto, "ab");

    if (Archivo != NULL)
    {
        if (fwrite(&dto, sizeof (VotoDTO),1,Archivo))
        {
            Resultado = true;
            fclose(Archivo);
        }
    }
    return Resultado;
}
//---------------------------------------------------------------------------
// METODO    : int VotoDAL::Mayor_ID ()
// ACCION    : Busca el siguiete ID para grabar un nuevo registro
// PARAMETROS: NADA
// DEVUELVE  : int --> ID Nuevo
//---------------------------------------------------------------------------
int VotoDAL::Mayor_ID ()
{
    FILE *Archivo;
    VotoDTO Obj;
    int Max = 0;

    Archivo = fopen(Ruta_Voto,"rb");

    if(Archivo != NULL)
    {
        while (fread(&Obj,sizeof(VotoDTO),1,Archivo))
        {
            if(Obj.GetID_Voto()>Max)

                Max = Obj.GetID_Voto();
        }
        fclose(Archivo);
    }
    Max ++;
    return Max;
}
//---------------------------------------------------------------------------
// METODO    : bool VotoDAL::Leer_DeDisco(int Pos, VotoDTO &Obj)
// ACCION    : Lee un registro del archivo por medio de una posicion de registro
// PARAMETROS: int Pos, VotoDTO &Obj --> Posicion a leer y objeto a cargar datos
// DEVUELVE  : true si leyo, false si no leyo
//---------------------------------------------------------------------------
bool VotoDAL::Leer_DeDisco(int Pos, VotoDTO &Obj)
{
    FILE *Archivo;

    Archivo = fopen(Ruta_Voto, "rb");

    if (Archivo != NULL)
    {
        fseek(Archivo,sizeof (VotoDTO)*Pos,SEEK_SET);

        if (fread(&Obj, sizeof(VotoDTO),1,Archivo))
        {
            fclose(Archivo);
            return true;
        }

    }
    return false;
}
//---------------------------------------------------------------------------
// METODO    : bool VotoDAL::Ya_Voto (int DNI)
// ACCION    : Verifica si el votante ya realizo el voto
// PARAMETROS: int DNI --> DNI a verificar
// DEVUELVE  : true si ya voto, false si no voto
//---------------------------------------------------------------------------
bool VotoDAL::Ya_Voto (int DNI)
{
    VotoDTO Obj;
    bool Resultado = false ;
    FILE *P;

    P = fopen(Ruta_Voto,"rb");

    if (P != NULL)
    {
        while (fread(&Obj, sizeof (VotoDTO),1,P))
        {
            if (Obj.GetDNI()==DNI)
            {
                Resultado = true;
            }
        }
        fclose(P);
    }

    return Resultado;
}
//---------------------------------------------------------------------------
// METODO    : int VotoDAL::Cantidad_votos(int Candidato, int Puesto)
// ACCION    : cuenta la cantidad de votos por candidato y puesto
// PARAMETROS: int Candidato, int Puesto
// DEVUELVE  : cantidad de votos
//---------------------------------------------------------------------------
int VotoDAL::Cantidad_votos(int Candidato, int Puesto)
{
    FILE *Archivo;
    VotoDTO VotDTO;
    int Cantidad=0;

    Archivo = fopen(Ruta_Voto,"rb");

    if (Archivo != NULL)
    {
        while (fread(&VotDTO,sizeof(VotoDTO),1,Archivo))
        {
            if (Puesto == 1)
            {
                if (VotDTO.GetID_Presidente() == Candidato)
                {
                    Cantidad++;
                }
            }
            if (Puesto == 2)
            {
                if (VotDTO.GetID_VicePresidente() == Candidato)
                {
                    Cantidad++;
                }
            }
            if (Puesto == 3)
            {
                if (VotDTO.GetID_Gobernador() == Candidato)
                {
                    Cantidad++;
                }
            }
        }
        fclose(Archivo);
    }

    return Cantidad;
}
