#ifndef PUESTODTO_H
#define PUESTODTO_H
#include <cstring>

class PuestoDTO
{
    public:

        int GetID_Puesto() { return ID_Puesto; }
        int SetID_Puesto(int val) { ID_Puesto = val; }

        char* GetDescripcion() { return Descripcion; }
        void SetDescripcion(char* val) { strcpy(Descripcion,val); }

    private:
        int ID_Puesto;
        char Descripcion[25];
};

#endif // PUESTODTO_H
