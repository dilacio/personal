#ifndef VOTODTO_H
#define VOTODTO_H


class VotoDTO
{
    public:
        VotoDTO();

        int GetID_Voto() { return ID_Voto; }
        void SetID_Voto(int val) { ID_Voto = val; }
        int GetDNI() { return DNI; }
        void SetDNI(int val) { DNI = val; }
        int GetID_VicePresidente() { return ID_VicePresidente; }
        void SetID_VicePresidente(int val) { ID_VicePresidente = val; }
        int GetID_Presidente() { return ID_Presidente; }
        void SetID_Presidente(int val) { ID_Presidente = val; }
        int GetID_Gobernador() { return ID_Gobernador; }
        void SetID_Gobernador(int val) { ID_Gobernador = val; }


    private:
        int ID_Voto;
        int DNI;
        int ID_Presidente;
        int ID_VicePresidente;
        int ID_Gobernador;
};

#endif // VOTODTO_H
