#include "Consulta_PadronView.h"
//---------------------------------------------------------------------------
// METODO    : void Consulta_PadronView::Consulta_Padron()
// ACCION    : vista de consulta de padrones
// PARAMETROS: NADA
// DEVUELVE  : NADA
//---------------------------------------------------------------------------
void Consulta_PadronView::Consulta_Padron()
{
    int DNI, Pos=0;
    VotanteDAL VotDal;
    VotanteDTO VotDto;
    AuxiliaresView Aux;

    system("cls");
    Aux.Menu_Datos_Sistema();

    cout << "                       MENU CONSULTA PADRONES" << endl;
    cout << "_______________________________________________________________________________________"<< endl;

    cout << "Ingrese el DNI: ";
    cin >> DNI;

    if (VotDal.Existe_Votante(DNI))
    {
        Pos = VotDal.Busco_Posicion(DNI);
        VotDal.Leer_DeDisco(Pos,VotDto);

        if (VotDto.GetEdad() > 15)
        {
            cout << endl;
            cout << "El votante se encuentra en los padrones y es apto para votar" << endl;
        }
        else
        {
            cout << "El votante no cumple los requisitos para votar" << endl;
        }
    }
    else
    {
        cout << "El votante no se encuentra dado de alta por favor ingrese al modulo de alta y genere la misma." << endl;
    }
    cout << endl;
    system("pause");
}
