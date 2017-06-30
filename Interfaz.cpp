#include <iostream>
#include <stdlib.h>
#include <cctype>
#include "Interfaz.h"

Interfaz::Interfaz()
{
this->menuConsultasTP2 = new MenuDeConsultas;
}

Interfaz::~Interfaz()
{
delete menuConsultasTP2;
}


void Interfaz::otraConsulta (char &opcionElegida)
{
        cout << endl << endl << "Desea realizar otra consulta? (s/n): ";
        char otraConsulta;
        cin >> otraConsulta;
        if ((otraConsulta == 's') || (otraConsulta == 'S'))
        { opcionElegida = 's'; };
        if ((otraConsulta == 'n') || (otraConsulta == 'N'))
        { opcionElegida = 'Q'; };
}


MenuDeConsultas* Interfaz::obtenerMenuDeConsultas()
{
return this->menuConsultasTP2;
}

void Interfaz::cargarConsultasEnMenu()
{
    this->menuConsultasTP2->agregarUnaOpcion ("Detalle de llamadas entre el interno X de la central A al interno Y de la central B");
    this->menuConsultasTP2->agregarUnaOpcion ("Interno que mas hablo de todos y de cada una de las centrales");
    this->menuConsultasTP2->agregarUnaOpcion ("Interno que mas veces llamo de todos y de cada una de las centrales");
    this->menuConsultasTP2->agregarUnaOpcion ("Interno que mas veces le dio ocupado de todos y de cada una de las centrales");
    this->menuConsultasTP2->agregarUnaOpcion ("Interno al que mas llamaron de todos y de cada una de las centrales");
    this->menuConsultasTP2->agregarUnaOpcion ("Interno que mas gasto tuvo de todos y de cada una de las centrales");
    this->menuConsultasTP2->agregarUnaOpcion ("Interno al que mas le hablaron de todos y de cada una de las centrales");
    this->menuConsultasTP2->agregarUnaOpcion ("Interno que genero mas ocupados de todos y de cada una de las centrales");
    this->menuConsultasTP2->agregarUnaOpcion ("Detalle de las llamadas emitidas por el interno X de la central A");
    this->menuConsultasTP2->agregarUnaOpcion ("Detalle de las llamadas recibidas por el interno X de la central A");
    this->menuConsultasTP2->agregarUnaOpcion ("Detalle de las llamadas emitidas por X de la central A y recibidas por Y de la central B");
    this->menuConsultasTP2->agregarUnaOpcion ("Detalle de las llamadas recibidas por X de la central A y emitidas por Y de la central B");
    this->menuConsultasTP2->agregarUnaOpcion ("Cantidad de llamadas anuladas, por falta de enlaces por central");
    this->menuConsultasTP2->agregarUnaOpcion ("Detalle de enlaces");
    this->menuConsultasTP2->agregarUnaOpcion ("Detalle de internos");
    this->menuConsultasTP2->agregarUnaOpcion ("Detalle de centrales");
    this->menuConsultasTP2->agregarUnaOpcion ("Salir");

}

void Interfaz::imprimirMenu()
{
    Lista<Opcion*>* listaOpciones = menuConsultasTP2->obtenerOpcionesDisponibles();
    listaOpciones->iniciarCursor();
    listaOpciones->avanzarCursor();
    cout << "Menu De Consultas -----------------------------------------" << endl << endl;
    for (unsigned int i=0 ; i<listaOpciones->obtenerTamanio(); i++)
    {
    Opcion* unaOpcion = listaOpciones->obtenerCursor();
    cout << unaOpcion->obtenerIdentificador() << ") ";
    cout << unaOpcion->obtenerLeyenda() << endl;
    listaOpciones->avanzarCursor();
    }
}

void Interfaz::interfazMenu ()
{
    char opcionElegida = 's';
    while (opcionElegida != 'Q')
    {
        consultaARealizar.limpiar_pantalla();
        this->imprimirMenu();
        cout << endl << endl << "Elija una opcion: ";
        cin >> opcionElegida;
        toupper(opcionElegida);

        switch (opcionElegida)

        {
                case 'A': consultaARealizar.detalleLlamadasEntreXCentralAYCentralB(); break;
                case 'B': consultaARealizar.internoQueMasHabloDeTodosYDeCadaCentral(); break;
                case 'C': consultaARealizar.internoQueMasLlamoDeTodosYDeCadaCentral(); break;
                case 'D': consultaARealizar.internoQueMasLeDioOcupadoDeTodosYDeCadaCentral(); break;
                case 'E': consultaARealizar.internoAlQueMasLlamaronDeTodosYDeCadaCentral(); break;
                case 'F': consultaARealizar.internoQueMasGastoDeTodosYDeCadaCentral(); break;
                case 'G': consultaARealizar.internoAlQueMasLeHablaronDeTodosYDeCadaCentral(); break;
                case 'H': consultaARealizar.internoQueMasDioOcupadoDeTodosYDeCadaCentral(); break;
                case 'I': consultaARealizar.detalleDeLlamadasEmitidasPorXDeCentralA(); break;
                case 'J': consultaARealizar.detalleDeLlamadasRecibidasPorXDeCentralA(); break;
                case 'K': consultaARealizar.detalleDeLlamadasRecibidasPorXDeADeYDeB(); break;
                case 'L': consultaARealizar.detalleDeLlamadasRealizadasDeXDeAAYDeB();break;
                case 'M': consultaARealizar.cantidadDeLlamadasAnuladas();break;
                case 'N': consultaARealizar.imprimirDetalleDeEnlaces(); break;
                case 'O': consultaARealizar.imprimirDetalleDeInternos(); break;
                case 'P': consultaARealizar.imprimirDetalleDeCentrales(); break;
                case 'Q': opcionElegida = 'Q'; break;


        };
        if (opcionElegida!='Q'){otraConsulta(opcionElegida);};

    };
    consultaARealizar.limpiar_pantalla();
    cout << endl << "---------------------------------------------"
         << endl << "-------------PROGRAMA TERMINADO--------------"
         << endl << "---------------------------------------------" << endl;

}

