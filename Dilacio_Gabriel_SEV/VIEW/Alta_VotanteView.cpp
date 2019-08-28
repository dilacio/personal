#include "Alta_VotanteView.h"
//---------------------------------------------------------------------------
// METODO    : void Alta_VotanteView::Menu ()
// ACCION    : Menu principal de alta de un votante
// PARAMETROS: NADA
// DEVUELVE  : NADA
//---------------------------------------------------------------------------
void Alta_VotanteView::Menu ()
{
    VotanteDAL Obj;
    VotanteDTO Reg;
    ProvinciaDAL Prov;
    AuxiliaresView Aux;

    int DNI, ID_Prov, Edad;
    char Nombre[30], Apellido[30],Direccion[30], Provincia[30];

    system("cls");

    Aux.Menu_Datos_Sistema();
    cout << "                       MENU ALTA VOTANTE" << endl;
    cout << "_______________________________________________________________________________________"<< endl;
    cout << endl;



    cout << "Ingrese el DNI del nuevo votante: " ;
    cin >> DNI;
    cin.ignore();

    if (Obj.Existe_Votante(DNI))
    {
        cout << "El votante ya existe!" << endl;
    }
    else
    {
        Reg.SetDNI(DNI);
        cout << "Ingrese el Nombre: ";
        cin.getline(Nombre,25);

        cout << "Ingrese el Apellido: ";
        cin.getline(Apellido,25);

        cout << "Ingrese el Direccion: ";
        cin.getline(Direccion,50);

        cout << "Ingrese la provincia: ";
        cin.getline(Provincia,50);

        cout << "Ingrese la Edad: ";
        cin >> Edad;
        cin.ignore();

        ID_Prov = Prov.Busco_ID(Provincia);

        Reg.SetNombre(Nombre);
        Reg.SetApellido(Apellido);
        Reg.SetDireccion(Direccion);
        Reg.SetID_Provincia(ID_Prov);
        Reg.SetDNI(DNI);
        Reg.SetEdad(Edad);

        if (Obj.Guardar_EnDisco(Reg))
        {
            cout << endl;
            cout << "El Votante se dio de alta correctamente" << endl ;
            cout << endl;
        }
    }
    system("pause");
}
