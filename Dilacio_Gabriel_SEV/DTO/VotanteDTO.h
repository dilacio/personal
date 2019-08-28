#ifndef VOTANTEDTO_H
#define VOTANTEDTO_H
#include <cstring>

class VotanteDTO
{
    public:
        VotanteDTO();

        int GetDNI() { return DNI; }
        void SetDNI(int val) { DNI = val; }
        char* GetNombre() { return Nombre; }
        void SetNombre(char* val) { strcpy(Nombre, val); }
        char* GetApellido() { return Apellido; }
        void SetApellido(char* val) { strcpy(Apellido, val); }
        char* GetDireccion() { return Direccion; }
        void SetDireccion(char* val) { strcpy(Direccion, val); }
        int GetID_Provincia() { return ID_Provincia; }
        void SetID_Provincia(int val) { ID_Provincia = val; }
        int GetEdad() { return Edad; }
        void SetEdad(int val) { Edad = val; }

    private:
        int DNI;
        char Nombre[25];
        char Apellido[25];
        char Direccion[50];
        int ID_Provincia;
        int Edad;
};

#endif // VOTANTEDTO_H
