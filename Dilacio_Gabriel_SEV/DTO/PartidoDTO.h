#ifndef PARTIDODTO_H
#define PARTIDODTO_H
#include <cstring>

class PartidoDTO
{
    public:
        PartidoDTO();

        int GetID_Partido() { return ID_Partido; }
        void SetID_Partido(int val) { ID_Partido = val; }
        char* GetNombre() { return Nombre; }
        void SetNombre(char* val) { strcpy(Nombre,val); }
        int GetID_Candidato() { return ID_Candidato; }
        void SetID_Candidato(int val) { ID_Candidato = val; }
        int GetID_Puesto() { return ID_Puesto; }
        void SetID_Puesto(int val) { ID_Puesto = val; }

    private:
        int ID_Partido;
        char Nombre[50];
        int ID_Candidato;
        int ID_Puesto;
};

#endif // PARTIDODTO_H
