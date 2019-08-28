#include "VotanteDAL.h"
//---------------------------------------------------------------------------
// METODO    : bool VotanteDAL::Existe_Votante (int DNI)
// ACCION    : Verifica si existe el registro por medio de un DNI
// PARAMETROS: int DNI --> DNI a buscar
// DEVUELVE  : true si existe, false si no existe
//---------------------------------------------------------------------------
bool VotanteDAL::Existe_Votante (int DNI)
{
    VotanteDTO Obj;
    bool Resultado = false ;
    FILE *P;

    P = fopen(Ruta_Votante,"rb");

    if (P != NULL)
    {
        while (fread(&Obj, sizeof (VotanteDTO),1,P))
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
// METODO    : bool VotanteDAL::Guardar_EnDisco (VotanteDTO Votante)
// ACCION    : Guarda un registro en el archivo de votantes
// PARAMETROS: VotanteDTO --> registro a guardar
// DEVUELVE  : true si grabo, false si no grabo
//---------------------------------------------------------------------------
bool VotanteDAL::Guardar_EnDisco (VotanteDTO Votante)
{
    FILE *Archivo ;
    bool Resultado = false;

    Archivo = fopen(Ruta_Votante, "ab");

    if (Archivo != NULL)
    {
        if (fwrite(&Votante, sizeof (VotanteDTO),1,Archivo))
        {
            Resultado = true;
            fclose(Archivo);
        }
    }
    return Resultado;
}
//---------------------------------------------------------------------------
// METODO    : bool VotanteDAL::Leer_DeDisco(int Pos, VotanteDTO &Obj)
// ACCION    : Lee un registro del archivo por medio de una posicion de registro
// PARAMETROS: int Pos, VotanteDTO &Obj --> Posicion a leer y objeto a cargar datos
// DEVUELVE  : true si leyo, false si no leyo
//---------------------------------------------------------------------------
bool VotanteDAL::Leer_DeDisco(int Pos, VotanteDTO &Obj)
{
   FILE *Archivo;

    Archivo = fopen(Ruta_Votante, "rb");

    if (Archivo != NULL)
    {
        fseek(Archivo,sizeof (VotanteDTO)*Pos,SEEK_SET);

        if (fread(&Obj, sizeof(VotanteDTO),1,Archivo))
        {
            fclose(Archivo);
            return true;
        }

    }
    return false;
}
////---------------------------------------------------------------------------
//// METODO    : bool VotanteDAL::Leer_DeDisco(VotanteDTO &Obj)
//// ACCION    : Lee un registro del archivo por medio de una posicion de registro
//// PARAMETROS: int Pos, VotanteDTO &Obj --> Posicion a leer y objeto a cargar datos
//// DEVUELVE  : true si leyo, false si no leyo
////---------------------------------------------------------------------------
//bool VotanteDAL::Leer_DeDisco(VotanteDTO &Obj)
//{
//   FILE *Archivo;
//
//    Archivo = fopen(Ruta_Votante, "rb");
//
//    if (Archivo != NULL)
//    {
//        while(fread(&Obj, sizeof(VotanteDAL),1,Archivo))
//        {
//            fclose(Archivo);
//            return true;
//        }
//    }
//    return false;
//}

//---------------------------------------------------------------------------
// METODO    : int VotanteDAL::Busco_Posicion(int DNI)
// ACCION    : Busca la posicion que ocupa un votante en un archivo
// PARAMETROS: int ID --> ID a buscar
// DEVUELVE  : Posicion dentro del archivo
//---------------------------------------------------------------------------
int VotanteDAL::Busco_Posicion(int DNI)
{
    FILE *Archivo;
    VotanteDTO VotDTO;
    int Posicion_Final = 0, Pos=0;

    Archivo = fopen(Ruta_Votante,"rb");

    if (Archivo != NULL)
    {
        while (fread(&VotDTO,sizeof(VotanteDTO),1,Archivo))
        {
            if (DNI == VotDTO.GetDNI())
            {
                Posicion_Final = Pos;
            }
            Pos ++;
        }
        fclose(Archivo);
    }
    return Posicion_Final;
}
