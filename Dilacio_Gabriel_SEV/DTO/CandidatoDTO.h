#ifndef CANDIDATODTO_H
#define CANDIDATODTO_H
#include <cstring>

class CandidatoDTO
{
    public:
        CandidatoDTO();

        int GetID_Candidato() { return ID_Candidato; }
        void SetID_Candidato(int val) { ID_Candidato = val; }
        char* GetNombre() { return Nombre; }
        void SetNombre(char* val) { strcpy(Nombre,val); }
        char* GetApellido() { return Apellido; }
        void SetApellido(char* val) { strcpy(Apellido,val); }
        int GetVotos() { return Votos; }
        void SetVotos(int val) { Votos = val; }

    private:
        int ID_Candidato;
        char Nombre[25];
        char Apellido[25];
        int Votos;
};

#endif // CANDIDATODTO_H
