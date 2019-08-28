#ifndef PROVINCIADTO_H
#define PROVINCIADTO_H
#include <cstring>

class ProvinciaDTO
{
    public:
        ProvinciaDTO();

        int GetID_Provincia() { return ID_Provincia; }
        void SetID_Provincia(int val) { ID_Provincia = val; }
        char* GetNombre() { return Nombre; }
        void SetNombre(char* val) { strcpy(Nombre,val); }

    private:
        int ID_Provincia;
        char Nombre[40];
};

#endif // PROVINCIADTO_H
