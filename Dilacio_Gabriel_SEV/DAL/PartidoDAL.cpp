#include "PartidoDAL.h"

//---------------------------------------------------------------------------
// METODO    : bool PartidoDAL::Guardar_EnDisco(PartidoDTO dto)
// ACCION    : Guarda un registro en el archivo de Partidos
// PARAMETROS: PartidoDTO --> registro a guardar
// DEVUELVE  : true si grabo, false si no grabo
//---------------------------------------------------------------------------
bool PartidoDAL::Guardar_EnDisco(PartidoDTO dto)
{
    FILE *Archivo;
    bool Resultado= false;

    Archivo = fopen(Ruta_Partido, "ab");

    if (Archivo != NULL)
    {
        if (fwrite(&dto, sizeof (PartidoDTO),1,Archivo))
        {
            Resultado = true;
            fclose(Archivo);
        }
    }
    return Resultado;
}
//---------------------------------------------------------------------------
// METODO    : int PartidoDAL::Busco_ID (char* Part)
// ACCION    : Busca un ID de Partido por medio de un nombre de partido
// PARAMETROS: char*  --> Nombre a buscar
// DEVUELVE  : int --> ID encontrado
//---------------------------------------------------------------------------
int PartidoDAL::Busco_ID (char* Part)
{
    FILE *Archivo;
    PartidoDTO Reg;
    int Resultado = 0;
    Auxiliar Aux;
    char Partido[25];

    Archivo = fopen(Ruta_Partido,"rb");

    if (Archivo != NULL)
    {
        while (fread(&Reg,sizeof (PartidoDTO),1,Archivo))
        {
            strcpy(Partido,Part);

            if (strcmp(Aux.toUpper(Reg.GetNombre()),Aux.toUpper(Partido)) == 0)
            {
                Resultado = Reg.GetID_Candidato();
            }
        }
        fclose(Archivo);
    }
    return Resultado;
}
//---------------------------------------------------------------------------
// METODO    : int PartidoDAL::Mayor_ID ()
// ACCION    : Busca el siguiete ID para grabar un nuevo registro
// PARAMETROS: NADA
// DEVUELVE  : int --> ID Nuevo
//---------------------------------------------------------------------------
int PartidoDAL::Mayor_ID ()
{
    FILE *Archivo;
    PartidoDTO Obj;
    int Max = 0;

    Archivo = fopen(Ruta_Partido,"rb");

    if(Archivo != NULL)
    {
        while (fread(&Obj,sizeof(PartidoDTO),1,Archivo))
        {
            if(Obj.GetID_Partido()>Max)

                Max = Obj.GetID_Partido();
        }
        fclose(Archivo);
    }
    Max ++;
    return Max;
}
//---------------------------------------------------------------------------
// METODO    : bool PartidoDAL::Leer_DeDisco(int Pos, PartidoDTO &Obj)
// ACCION    : Lee un registro del archivo por medio de una posicion de registro
// PARAMETROS: int Pos, PartidoDTO &Obj --> Posicion a leer y objeto a cargar datos
// DEVUELVE  : true si leyo, false si no leyo
//---------------------------------------------------------------------------
bool PartidoDAL::Leer_DeDisco(int Pos, PartidoDTO &Obj)
{
    FILE *Archivo;

    Archivo = fopen(Ruta_Partido, "rb");

    if (Archivo != NULL)
    {
        fseek(Archivo,sizeof (PartidoDTO)*Pos,SEEK_SET);

        if (fread(&Obj, sizeof(PartidoDTO),1,Archivo))
        {
            fclose(Archivo);
            return true;
        }
    }
    return false;
}
//---------------------------------------------------------------------------
// METODO    : int PartidoDAL::Cuento_Partidos(int Tipo)
// ACCION    : Cuenta la cantidad de partidos dentro del archivo
// PARAMETROS: Int tipo --> tipo de puesto
// DEVUELVE  : cantidad de partidos
//---------------------------------------------------------------------------
int PartidoDAL::Cuento_Partidos(int Tipo)
{
    FILE *Archivo;
    int Cant = 0;
    PartidoDTO PartDTO;

    Archivo = fopen(Ruta_Partido,"rb");

    if (Archivo != NULL)
    {
        while (fread(&PartDTO,sizeof(PartidoDTO),1,Archivo))
        {
            if (PartDTO.GetID_Puesto()==Tipo)
            {
                Cant ++;
            }
        }
        fclose(Archivo);
    }
    return Cant;
}
//---------------------------------------------------------------------------
// METODO    : char* PartidoDAL::Busco_Nombre_x_Cand(int ID)
// ACCION    : busca un nombre por un ID
// PARAMETROS: Int ID --> ID a buscar
// DEVUELVE  : Nombre del partido
//---------------------------------------------------------------------------
char* PartidoDAL::Busco_Nombre_x_Cand(int ID)
{
    PartidoDTO PartDTO;
    FILE *Archivo;

    Archivo = fopen(Ruta_Partido,"rb");

    if (Archivo != NULL)
    {
        while (fread(&PartDTO,sizeof(PartidoDTO),1,Archivo))
        {
            if  (ID == PartDTO.GetID_Candidato())
            {
                fclose(Archivo);
                return PartDTO.GetNombre();
            }
        }
    }
    return "No Se Encontro";
}
//---------------------------------------------------------------------------
// METODO    : int PartidoDAL::Busco_x_Cand(int ID_Cand)
// ACCION    : Busca un ID de partido por medio de un ID de candidato
// PARAMETROS: Int ID_Cand --> Id a buscar
// DEVUELVE  : ID del partido
//---------------------------------------------------------------------------
int PartidoDAL::Busco_x_Cand(int ID_Cand)
{
    FILE *Archivo;
    PartidoDTO PartDTO;
    int ID_Part=0;

    Archivo = fopen(Ruta_Partido,"rb");

    if (Archivo != NULL)
    {

        while(fread(&PartDTO,sizeof(PartidoDTO),1,Archivo))
        {
            if ( ID_Cand == PartDTO.GetID_Candidato())
            {
                fclose(Archivo);
                return PartDTO.GetID_Partido();
            }
        }
    }
    return ID_Part;
}
