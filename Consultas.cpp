#include "Consultas.h"

Consultas::Consultas ()
{
    this->inicio.abrirArchivo();
    this->inicio.guardarInformacionDeArchivo();
    this->inicio.mostrarResultadosGuardados();
}

Consultas::~Consultas ()
{
}

void Consultas::limpiar_pantalla(){
    #ifdef _WIN32
    system("cls");
    #else
    system("clear");
    #endif
}


void Consultas::dividirInternoDeCentral(string numeroCompleto, unsigned int &numeroCentral, unsigned int &numeroInterno)
{
    char* numeroChar = new char[10];
    strcpy(numeroChar, numeroCompleto.c_str());
    numeroCentral = (unsigned int)(numeroChar[0]-48)*1000 + (unsigned int)(numeroChar[1]-48)*100 + (unsigned int)(numeroChar[2]-48)*10 + (unsigned int)(numeroChar[3]-48);
    numeroInterno = (unsigned int)(numeroChar[5]-48)*1000 + (unsigned int)(numeroChar[6]-48)*100 + (unsigned int)(numeroChar[7]-48)*10 + (unsigned int)(numeroChar[8]-48);
}

// Consulta A)
void Consultas::detalleLlamadasEntreXCentralAYCentralB ()
{
    limpiar_pantalla();
    string numeroX;
    unsigned int centralX;
    unsigned int internoX;
    string numeroY;
    unsigned int centralY;
    unsigned int internoY;
    cout << "Ingrese interno X: ";
    cin >> numeroX;
    dividirInternoDeCentral(numeroX, centralX, internoX);
    cout << endl << "Ingrese interno Y: ";
    cin >> numeroY;
    dividirInternoDeCentral(numeroY, centralY, internoY);
    Llamadas* llamadasEntreXY = inicio.buscarCentral(centralX)->buscarInterno(internoX)->buscarLlamadas(centralY, internoY);
    unsigned int cantidadDeLlamadas = llamadasEntreXY->obtenerCantidadDeLlamadas();
    unsigned int tiempoTotalHablado = llamadasEntreXY->obtenerTiempoTotalHablado();
    // unsigned int cantidadDeVecesOcupado = (este es el que falta por el metodo);
    limpiar_pantalla();
    cout << "Detalle de llamadas entre X de la central A e Y de la central B ------------" << endl << endl
         << "X - Central: " << centralX << " Interno: " << internoX << endl
         << "Y - Central: " << centralY << " Interno: " << internoY << endl << endl
         << "Tiempo total hablado: " << tiempoTotalHablado << endl
         << "Cantidad de llamadas: " << cantidadDeLlamadas << endl
         << "Cantidad de veces ocupado: " << /*cantidadDeVecesOcupado <<*/ endl << endl;

}

//Consulta B)
void Consultas::internoQueMasHabloDeTodosYDeCadaCentral ()
{
    limpiar_pantalla();

    unsigned int centralQueMasHabloDeTodas = 0;
    unsigned int internoQueMasHabloDeTodos = 0;
    unsigned int cantidadQueMasSeHabloCentrales = 0;
    Lista <Central*>* centrales = inicio.obtenerListaCentrales();
    centrales->iniciarCursor();
    cout << "Interno que mas hablo de cada central ---------------------"<< endl << endl;
    while (centrales->avanzarCursor())
    {
        unsigned int internoQueMasHabloDeEstaCentral = 0;
        unsigned int cantidadMasHablada = 0;
        Central* unaCentral = centrales->obtenerCursor();
        Lista <Interno*>* internos = unaCentral->obtenerListaDeInternos();
        internos->iniciarCursor();
        while (internos->avanzarCursor())
        {
            Interno* unInterno = internos->obtenerCursor();
            if ( cantidadMasHablada < (unInterno->obtenerTiempoDeLlamadasRealizadas()) )
            {
                cantidadMasHablada = (unInterno->obtenerTiempoDeLlamadasRealizadas());
                internoQueMasHabloDeEstaCentral = unInterno->obtenerInterno();
            }
        }
        cout << endl << endl
             << "Central: " << unaCentral->obtenerNumero() << endl
             << "Interno que mas hablo: int-" << internoQueMasHabloDeEstaCentral << endl
             << "Tiempo hablado: " << cantidadMasHablada << endl << endl
             << "-----------------------------------------------------------";
        if (cantidadQueMasSeHabloCentrales < cantidadMasHablada)
        {
            cantidadQueMasSeHabloCentrales = cantidadMasHablada;
            centralQueMasHabloDeTodas = unaCentral->obtenerNumero();
            internoQueMasHabloDeTodos = internoQueMasHabloDeEstaCentral;
        }
    }
    cout << endl << "-----------------------------------------------------------" << endl << endl
         << "Interno que mas hablo de todos:  " << centralQueMasHabloDeTodas << "-" << internoQueMasHabloDeTodos << endl << endl
         << "-----------------------------------------------------------" << endl
         << "-----------------------------------------------------------" << endl;
}

//Consulta C)
void Consultas::internoQueMasLlamoDeTodosYDeCadaCentral ()
{
    limpiar_pantalla();
    unsigned int centralQueMasLlamoDeTodas = 0;
    unsigned int internoQueMasLlamoDeTodos = 0;
    unsigned int cantidadQueMasSeLlamoCentrales = 0;
    Lista <Central*>* centrales = inicio.obtenerListaCentrales();
    centrales->iniciarCursor();
    cout << "Interno que mas llamo de cada central ---------------------"<< endl << endl;
    while (centrales->avanzarCursor())
    {
        unsigned int internoQueMasLlamoDeEstaCentral = 0;
        unsigned int cantidadMasLlamada = 0;
        Central* unaCentral = centrales->obtenerCursor();
        Lista <Interno*>* internos = unaCentral->obtenerListaDeInternos();
        internos->iniciarCursor();
        while (internos->avanzarCursor())
        {
            Interno* unInterno = internos->obtenerCursor();
            if ( cantidadMasLlamada < (unInterno->obtenerConjuntoLlamadasRealizadas()->obtenerTamanio()) )
            {
                cantidadMasLlamada = (unInterno->obtenerConjuntoLlamadasRealizadas()->obtenerTamanio());
                internoQueMasLlamoDeEstaCentral = unInterno->obtenerInterno();
            }
        }
        cout << endl << endl
             << "Central: " << unaCentral->obtenerNumero() << endl
             << "Interno que mas llamo: int-" << internoQueMasLlamoDeEstaCentral << endl
             << "Cantidad de llamadas: " << cantidadMasLlamada << endl << endl
             << "-----------------------------------------------------------";
        if (cantidadQueMasSeLlamoCentrales < cantidadMasLlamada)
        {
            cantidadQueMasSeLlamoCentrales = cantidadMasLlamada;
            centralQueMasLlamoDeTodas = unaCentral->obtenerNumero();
            internoQueMasLlamoDeTodos = internoQueMasLlamoDeEstaCentral;
        }
    }
    cout << endl << "-----------------------------------------------------------" << endl << endl
         << "Interno que mas llamo de todos:  " << centralQueMasLlamoDeTodas << "-" << internoQueMasLlamoDeTodos << endl << endl
         << "-----------------------------------------------------------" << endl
         << "-----------------------------------------------------------" << endl;
}

//Consulta D)
void Consultas::internoQueMasLeDioOcupadoDeTodosYDeCadaCentral ()
{
    limpiar_pantalla();
    unsigned int centralQueMasLeDioOcupadoDeTodas = 0;
    unsigned int internoQueMasLeDioOcupadoDeTodos = 0;
    unsigned int cantidadQueMasEstuvoOcupadoCentrales = 0;
    Lista <Central*>* centrales = inicio.obtenerListaCentrales();
    centrales->iniciarCursor();
    cout << "Interno que mas le dio ocupado de cada central ---------------------"<< endl << endl;
    while (centrales->avanzarCursor())
    {
        unsigned int internoQueMasLeDioOcupadoDeEstaCentral = 0;
        unsigned int cantidadMasOcupada = 0;
        Central* unaCentral = centrales->obtenerCursor();
        Lista <Interno*>* internos = unaCentral->obtenerListaDeInternos();
        internos->iniciarCursor();
        while (internos->avanzarCursor())
        {
            Interno* unInterno = internos->obtenerCursor();
            if ( cantidadMasOcupada < unInterno->obtenerOcupadosSalientes() )
            {
                cantidadMasOcupada = unInterno->obtenerOcupadosSalientes();
                internoQueMasLeDioOcupadoDeEstaCentral = unInterno->obtenerInterno();
            }
        }
        cout << endl << endl
             << "Central: " << unaCentral->obtenerNumero() << endl
             << "Interno que le dio mas ocupado: int-" << internoQueMasLeDioOcupadoDeEstaCentral << endl
             << "Cantidad de veces que le dio ocupado: " << cantidadMasOcupada << endl << endl
             << "-----------------------------------------------------------";
        if (cantidadQueMasEstuvoOcupadoCentrales < cantidadMasOcupada)
        {
            cantidadQueMasEstuvoOcupadoCentrales = cantidadMasOcupada;
            centralQueMasLeDioOcupadoDeTodas = unaCentral->obtenerNumero();
            internoQueMasLeDioOcupadoDeTodos = internoQueMasLeDioOcupadoDeEstaCentral;
        }
    }
    cout << endl << "-----------------------------------------------------------" << endl << endl
         << "Interno que mas le dio ocupado de todos:  " << centralQueMasLeDioOcupadoDeTodas << "-" << internoQueMasLeDioOcupadoDeTodos << endl << endl
         << "-----------------------------------------------------------" << endl
         << "-----------------------------------------------------------" << endl;
}

//Consulta E)
void Consultas::internoAlQueMasLlamaronDeTodosYDeCadaCentral ()
{
    limpiar_pantalla();
    unsigned int centralAlQueMasLlamaronDeTodas = 0;
    unsigned int internoAlQueMasLlamaronDeTodos = 0;
    unsigned int cantidadAlQueMasLlamaronCentrales = 0;
    Lista <Central*>* centrales = inicio.obtenerListaCentrales();
    centrales->iniciarCursor();
    cout << "Interno al que mas llamaron de cada central ---------------------"<< endl << endl;
    while (centrales->avanzarCursor())
    {
        unsigned int internoAlQueMasLlamaronDeEstaCentral = 0;
        unsigned int cantidadMasLlamada = 0;
        Central* unaCentral = centrales->obtenerCursor();
        Lista <Interno*>* internos = unaCentral->obtenerListaDeInternos();
        internos->iniciarCursor();
        while (internos->avanzarCursor())
        {
            Interno* unInterno = internos->obtenerCursor();
            if ( cantidadMasLlamada < (unInterno->obtenerConjuntoLlamadasRecibidas()->obtenerTamanio()) )
            {
                cantidadMasLlamada = (unInterno->obtenerConjuntoLlamadasRecibidas()->obtenerTamanio());
                internoAlQueMasLlamaronDeEstaCentral = unInterno->obtenerInterno();
            }
        }
        cout << endl << endl
             << "Central: " << unaCentral->obtenerNumero() << endl
             << "Interno al que mas llamaron: int-" << internoAlQueMasLlamaronDeEstaCentral << endl
             << "Cantidad de llamadas: " << cantidadMasLlamada << endl << endl
             << "-----------------------------------------------------------";
        if (cantidadAlQueMasLlamaronCentrales < cantidadMasLlamada)
        {
            cantidadAlQueMasLlamaronCentrales = cantidadMasLlamada;
            centralAlQueMasLlamaronDeTodas = unaCentral->obtenerNumero();
            internoAlQueMasLlamaronDeTodos = internoAlQueMasLlamaronDeEstaCentral;
        }
    }
    cout << endl << "-----------------------------------------------------------" << endl << endl
         << "Interno al que mas llamaron de todos:  " << centralAlQueMasLlamaronDeTodas << "-" << internoAlQueMasLlamaronDeTodos << endl << endl
         << "-----------------------------------------------------------" << endl
         << "-----------------------------------------------------------" << endl;

}

//Consulta F)
void Consultas::internoQueMasGastoDeTodosYDeCadaCentral ()
{
    limpiar_pantalla();
    unsigned int centralQueMasGastoDeTodas = 0;
    unsigned int internoQueMasGastoDeTodos = 0;
    unsigned int cantidadQueMasGastoCentrales = 0;
    Lista <Central*>* centrales = inicio.obtenerListaCentrales();
    centrales->iniciarCursor();
    cout << "Interno que mas gasto de cada central ---------------------"<< endl << endl;
    while (centrales->avanzarCursor())
    {
        unsigned int internoQueMasGastoDeEstaCentral = 0;
        unsigned int cantidadMasGastada = 0;
        Central* unaCentral = centrales->obtenerCursor();
        Lista <Interno*>* internos = unaCentral->obtenerListaDeInternos();
        internos->iniciarCursor();
        while (internos->avanzarCursor())
        {
            Interno* unInterno = internos->obtenerCursor();
            if ( cantidadMasGastada < (unInterno->obtenerGastoTotal()) )
            {
                cantidadMasGastada = (unInterno->obtenerGastoTotal());
                internoQueMasGastoDeEstaCentral = unInterno->obtenerInterno();
            }
        }
        cout << endl << endl
             << "Central: " << unaCentral->obtenerNumero() << endl
             << "Interno que mas gasto: int-" << internoQueMasGastoDeEstaCentral << endl
             << "Gasto: " << cantidadMasGastada << endl << endl
             << "-----------------------------------------------------------";
        if (cantidadQueMasGastoCentrales < cantidadMasGastada)
        {
            cantidadQueMasGastoCentrales = cantidadMasGastada;
            centralQueMasGastoDeTodas = unaCentral->obtenerNumero();
            internoQueMasGastoDeTodos = internoQueMasGastoDeEstaCentral;
        }
    }
    cout << endl << "-----------------------------------------------------------" << endl << endl
         << "Interno que mas gasto de todos:  " << centralQueMasGastoDeTodas << "-" << internoQueMasGastoDeTodos << endl << endl
         << "-----------------------------------------------------------" << endl
         << "-----------------------------------------------------------" << endl;
}

//Consulta G)
void Consultas::internoAlQueMasLeHablaronDeTodosYDeCadaCentral ()
{
    limpiar_pantalla();
    unsigned int centralAlQueMasLeHablaronDeTodas = 0;
    unsigned int internoAlQueMasLeHablaronDeTodos = 0;
    unsigned int cantidadQueMasLeHablaronCentrales = 0;
    Lista <Central*>* centrales = inicio.obtenerListaCentrales();
    centrales->iniciarCursor();
    cout << "Interno al que mas le hablaron de cada central ---------------------"<< endl << endl;
    while (centrales->avanzarCursor())
    {
        unsigned int internoAlQueMasLeHablaronDeEstaCentral = 0;
        unsigned int cantidadMasHablada = 0;
        Central* unaCentral = centrales->obtenerCursor();
        Lista <Interno*>* internos = unaCentral->obtenerListaDeInternos();
        internos->iniciarCursor();
        while (internos->avanzarCursor())
        {
            Interno* unInterno = internos->obtenerCursor();
            if ( cantidadMasHablada < (unInterno->obtenerTiempoDeLlamadasRecibidas()) )
            {
                cantidadMasHablada = (unInterno->obtenerTiempoDeLlamadasRecibidas());
                internoAlQueMasLeHablaronDeEstaCentral = unInterno->obtenerInterno();
            }
        }
        cout << endl << endl
             << "Central: " << unaCentral->obtenerNumero() << endl
             << "Interno al que mas le hablaron: int-" << internoAlQueMasLeHablaronDeEstaCentral << endl
             << "Tiempo hablado: " << cantidadMasHablada << endl << endl
             << "-----------------------------------------------------------";
        if (cantidadQueMasLeHablaronCentrales < cantidadMasHablada)
        {
            cantidadQueMasLeHablaronCentrales = cantidadMasHablada;
            centralAlQueMasLeHablaronDeTodas = unaCentral->obtenerNumero();
            internoAlQueMasLeHablaronDeTodos = internoAlQueMasLeHablaronDeEstaCentral;
        }
    }
    cout << endl << "-----------------------------------------------------------" << endl << endl
         << "Interno al que mas le hablaron de todos:  " << centralAlQueMasLeHablaronDeTodas << "-" << internoAlQueMasLeHablaronDeTodos << endl << endl
         << "-----------------------------------------------------------" << endl
         << "-----------------------------------------------------------" << endl;

}

//Consulta H)
void Consultas::internoQueMasDioOcupadoDeTodosYDeCadaCentral ()
{
    limpiar_pantalla();
    unsigned int centralQueMasDioOcupadoDeTodas = 0;
    unsigned int internoQueMasDioOcupadoDeTodos = 0;
    unsigned int cantidadQueMasEstuvoOcupadoCentrales = 0;
    Lista <Central*>* centrales = inicio.obtenerListaCentrales();
    centrales->iniciarCursor();
    cout << "Interno que mas le dio ocupado de cada central ---------------------"<< endl << endl;
    while (centrales->avanzarCursor())
    {
        unsigned int internoQueMasDioOcupadoDeEstaCentral = 0;
        unsigned int cantidadMasOcupada = 0;
        Central* unaCentral = centrales->obtenerCursor();
        Lista <Interno*>* internos = unaCentral->obtenerListaDeInternos();
        internos->iniciarCursor();
        while (internos->avanzarCursor())
        {
            Interno* unInterno = internos->obtenerCursor();
            if ( cantidadMasOcupada < unInterno->obtenerOcupadosEntrantes() )
            {
                cantidadMasOcupada = unInterno->obtenerOcupadosEntrantes();
                internoQueMasDioOcupadoDeEstaCentral = unInterno->obtenerInterno();
            }
        }
        cout << endl << endl
             << "Central: " << unaCentral->obtenerNumero() << endl
             << "Interno que dio mas veces ocupado: int-" << internoQueMasDioOcupadoDeEstaCentral << endl
             << "Cantidad de veces que dio ocupado: " << cantidadMasOcupada << endl << endl
             << "-----------------------------------------------------------";
        if (cantidadQueMasEstuvoOcupadoCentrales < cantidadMasOcupada)
        {
            cantidadQueMasEstuvoOcupadoCentrales = cantidadMasOcupada;
            centralQueMasDioOcupadoDeTodas = unaCentral->obtenerNumero();
            internoQueMasDioOcupadoDeTodos = internoQueMasDioOcupadoDeEstaCentral;
        }
    }
    cout << endl << "-----------------------------------------------------------" << endl << endl
         << "Interno que mas dio ocupado de todos:  " << centralQueMasDioOcupadoDeTodas << "-" << internoQueMasDioOcupadoDeTodos << endl << endl
         << "-----------------------------------------------------------" << endl
         << "-----------------------------------------------------------" << endl;
}

//Consulta I)
void Consultas::detalleDeLlamadasEmitidasPorXDeCentralA ()
{
    limpiar_pantalla();
    string numeroX;
    unsigned int centralX;
    unsigned int internoX;
    cout << "Ingrese numero completo de X (central-interno): ";
    cin >> numeroX;
    dividirInternoDeCentral (numeroX, centralX, internoX);
    Interno* llamadasDeX = inicio.buscarCentral(centralX)->buscarInterno(internoX);
    limpiar_pantalla();
    cout << "Detalle de llamadas emitidas por X ----------------------------" << endl << endl
         << "Cantidad de llamadas emitidas: " << llamadasDeX->obtenerConjuntoLlamadasRealizadas()->obtenerTamanio() << endl
         << "Cantidad de tiempo hablado en esas llamadas: " << llamadasDeX->obtenerTiempoDeLlamadasRealizadas() << endl
         << "Cantidad de veces que le dio ocupado: " << llamadasDeX->obtenerOcupadosSalientes() << endl << endl;
}

//Consulta J)
void Consultas::detalleDeLlamadasRecibidasPorXDeCentralA ()
{
    limpiar_pantalla();
    string numeroX;
    unsigned int centralX;
    unsigned int internoX;
    cout << "Ingrese numero completo de X (central-interno): ";
    cin >> numeroX;
    dividirInternoDeCentral (numeroX, centralX, internoX);
    Interno* llamadasDeX = inicio.buscarCentral(centralX)->buscarInterno(internoX);
    limpiar_pantalla();
    cout << "Detalle de llamadas recibidas por X ----------------------------" << endl << endl
         << "Cantidad de llamadas recibidas: " << llamadasDeX->obtenerConjuntoLlamadasRecibidas()->obtenerTamanio() << endl
         << "Cantidad de tiempo hablado en esas llamadas: " << llamadasDeX->obtenerTiempoDeLlamadasRecibidas() << endl
         << "Cantidad de veces que dio ocupado: " << llamadasDeX->obtenerOcupadosEntrantes() << endl << endl;
}

//Consulta K)
void Consultas::detalleDeLlamadasRealizadasDeXDeAAYDeB ()
{
    limpiar_pantalla();
    string numeroX;
    unsigned int centralX;
    unsigned int internoX;
    string numeroY;
    unsigned int centralY;
    unsigned int internoY;
    cout << "Ingrese interno X: ";
    cin >> numeroX;
    dividirInternoDeCentral(numeroX, centralX, internoX);
    cout << endl << "Ingrese interno Y: ";
    cin >> numeroY;
    dividirInternoDeCentral(numeroY, centralY, internoY);
    Llamadas* llamadasEntreXY = inicio.buscarCentral(centralX)->buscarInterno(internoX)->buscarLlamadas(centralY, internoY);
    unsigned int cantidadDeLlamadas = (llamadasEntreXY->obtenerCantidadDeLlamadas())/2;
    unsigned int tiempoTotalHablado = (llamadasEntreXY->obtenerTiempoTotalHablado())/2;
    //unsigned int cantidadDeVecesOcupado = (este es el que falta por el metodo);
    limpiar_pantalla();
    cout << "Detalle de llamadas emitidas por X de la central A y recibidas por Y de la central B ------------" << endl << endl
         << "X - Central: " << centralX << " Interno: " << internoX << endl
         << "Y - Central: " << centralY << " Interno: " << internoY << endl << endl
         << "Tiempo total hablado: " << tiempoTotalHablado << endl
         << "Cantidad de llamadas: " << cantidadDeLlamadas << endl
         << "Cantidad de veces ocupado: " << /*cantidadDeVecesOcupado <<*/ endl << endl;

}

//Consulta L)
void Consultas::detalleDeLlamadasRecibidasPorXDeADeYDeB ()
{
    limpiar_pantalla();
    string numeroX;
    unsigned int centralX;
    unsigned int internoX;
    string numeroY;
    unsigned int centralY;
    unsigned int internoY;
    cout << "Ingrese interno X: ";
    cin >> numeroX;
    dividirInternoDeCentral(numeroX, centralX, internoX);
    cout << endl << "Ingrese interno Y: ";
    cin >> numeroY;
    dividirInternoDeCentral(numeroY, centralY, internoY);
    Llamadas* llamadasEntreXY = inicio.buscarCentral(centralX)->buscarInterno(internoX)->buscarLlamadas(centralY, internoY);
    unsigned int cantidadDeLlamadas = (llamadasEntreXY->obtenerCantidadDeLlamadas())/2;
    unsigned int tiempoTotalHablado = (llamadasEntreXY->obtenerTiempoTotalHablado());
    //unsigned int cantidadDeVecesOcupado = (este es el que falta por el metodo);
    limpiar_pantalla();
    cout << "Detalle de llamadas emitidas por Y de la central B y recibidas por X de la central A ------------" << endl << endl
         << "X - Central: " << centralX << " Interno: " << internoX << endl
         << "Y - Central: " << centralY << " Interno: " << internoY << endl << endl
         << "Tiempo total hablado: " << tiempoTotalHablado << endl
         << "Cantidad de llamadas: " << cantidadDeLlamadas << endl
         << "Cantidad de veces ocupado: " << /*cantidadDeVecesOcupado <<*/ endl << endl;

}

//Consulta M)
void Consultas::cantidadDeLlamadasAnuladas ()
{
/*    Lista <Enlace*>* listaDeEnlacesDeUnaCentral;
    Lista <LlamadasAnuladas*>* listaDeLlamadasAnuladas;
    Lista <Central*>* centrales = inicio.obtenerListaCentrales();
    centrales->iniciarCursor();
    cout << "Lista de llamadas anuladas por falta de conexion o canal saturado --------------- " << endl << endl;
    while (centrales->avanzarCursor())
    {
        Central* unaCentral;
        Lista <Interno*>* internos = unaCentral->obtenerListaDeInternos();
        internos->iniciarCursor();
        while (internos->avanzarCursor())
        {
            Interno* unInterno = internos->obtenerCursor();
            Lista <Llamadas*>* llamadasDeUnInterno = unInterno->obtenerConjuntoLlamadasRealizadas();
            llamadasDeUnInterno->iniciarCursor();
            while (llamadasDeUnInterno->avanzarCursor())
            {
                LlamadasAnuladas* llamadasAnuladasEntreInternos;
                Llamadas* unaLlamadaDeUnInterno = llamadasDeUnInterno->obtenerCursor();
                if (!(inicio.existeConexion(unaLlamadaDeUnInterno->obtenerCentralEmisor(), unaLlamadaDeUnInterno->obtenerCentralReceptor(), listaDeEnlacesDeUnaCentral)))
                {
                    llamadasAnuladasEntreInternos->setCentralEmisora (unaLlamadaDeUnInterno->obtenerCentralEmisor());
                    llamadasAnuladasEntreInternos->setCentralReceptora (unaLlamadaDeUnInterno->obtenerCentralReceptor());
                    llamadasAnuladasEntreInternos->setInternoEmisor (unaLlamadaDeUnInterno->obtenerInternoEmisor());
                    llamadasAnuladasEntreInternos->setInternoReceptor (unaLlamadaDeUnInterno->obtenerInternoReceptor());
                    // a esta linea le falta el metodo de obtener llamadas anuladas llamadasAnuladasEntreInternos->sumarLlamadasAnuladas (unaLlamadaDeUnInterno->)
                    listaDeLlamadasAnuladas->insertarElemento (llamadasAnuladasEntreInternos);
                }
            }
        }
    }
    while (!(listaDeLlamadasAnuladas->estaVacia()))
        {
            listaDeLlamadasAnuladas->iniciarCursor();
            unsigned int mayorCantidadDeAnuladasParcial = -1;
            while (listaDeLlamadasAnuladas->avanzarCursor())
                {
                    LlamadasAnuladas* unasLlamadasAnuladas = listaDeLlamadasAnuladas->obtenerCursor();
                    if ((unasLlamadasAnuladas->obtenerCantidadLlamadasAnuladas() < mayorCantidadDeAnuladasParcial) || (mayorCantidadDeAnuladasParcial = -1))
                        {
                        cout << "Interno emisor: " << unasLlamadasAnuladas->getCentralEmisora() << "-" << unasLlamadasAnuladas->getInternoEmisor() << endl
                             << "Interno Receptor: " << unasLlamadasAnuladas->getCentralReceptora() << "-" << unasLlamadasAnuladas->getInternoReceptor() << endl
                             << "Cantidad de llamadas anuladas: " << unasLlamadasAnuladas->obtenerCantidadLlamadasAnuladas()<<endl
                             << "-----------------------------------------------------" << endl;
                        mayorCantidadDeAnuladasParcial = unasLlamadasAnuladas->obtenerCantidadLlamadasAnuladas();
                        listaDeLlamadasAnuladas->borrarCursor();
                        }
                }

        }*/
}

//Consulta N)
void Consultas::imprimirDetalleDeEnlaces ()
{
    limpiar_pantalla();
    cout << "Detalle de enlaces ------------------------------" << endl << endl;
    Lista <Central*>* centrales = inicio.obtenerListaCentrales();
    centrales->iniciarCursor();
    int numeral = 1;
    while (centrales->avanzarCursor())
        {
            Central* unaCentral = centrales->obtenerCursor();
            Lista <Enlace*>* enlaces = unaCentral->obtenerListaDeEnlaces();
            enlaces->iniciarCursor();
            while (enlaces->avanzarCursor())
                {
                    cout << endl << "Enlace " << numeral << endl;
                    Enlace* unEnlace = enlaces->obtenerCursor();
                    cout << "Origen: " << unEnlace->obtenerCentralA() << endl
                         << "Destino: "<< unEnlace->obtenerCentralB() << endl
                         << "Canales: "<< unEnlace->obtenerCantidadDeCanales() << endl << endl
                         << "----------------------------------------------------------" << endl;
                };
            numeral++;
        };
}

//Consulta O)
void Consultas::imprimirDetalleDeInternos ()
{
    limpiar_pantalla();
    cout << "Detalle de Internos ------------------------------" << endl << endl;
    Lista <Central*>* centrales = inicio.obtenerListaCentrales();
    centrales->iniciarCursor();
    while (centrales->avanzarCursor())
        {
            Central* unaCentral = centrales->obtenerCursor();
            Lista <Interno*>* internos = unaCentral->obtenerListaDeInternos();
            internos->iniciarCursor();
            if ((!internos->estaVacia()))
            {
            cout << "Central numero: " << unaCentral->obtenerNumero() << endl;
            while (internos->avanzarCursor())
                {
                    Interno* unInterno = internos->obtenerCursor();
                    cout << "Int- " << unInterno->obtenerInterno() << endl;
                };

            cout << endl << "---------------------------------------------------" << endl;
            };
        };
}

//Consulta P)
void Consultas::imprimirDetalleDeCentrales ()
{
    limpiar_pantalla();
    cout << "Detalle de Centrales ------------------------------" << endl << endl;
    Lista <Central*>* centrales = inicio.obtenerListaCentrales();
    centrales->iniciarCursor();
    while (centrales->avanzarCursor())
        {
            Central* unaCentral = centrales->obtenerCursor();
            Lista <Interno*>* internos = unaCentral->obtenerListaDeInternos();
            internos->iniciarCursor();
            cout << "Central numero: " << unaCentral->obtenerNumero() << endl
                 << "Cantidad de enlaces: " << unaCentral->obtenerListaDeEnlaces()->obtenerTamanio() << endl
                 << "Cantidad de internos: " << unaCentral->obtenerListaDeInternos()->obtenerTamanio() << endl
                 << endl << "---------------------------------------------------" << endl;
        };
}
