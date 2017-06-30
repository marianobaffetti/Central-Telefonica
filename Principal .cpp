#include "Enlace.h"
#include "Principal.h"
#include <iostream>
using namespace std;

Principal::Principal(){

    cout << "SELECCIONE UN CRITERIO PARA ESTABLECER LAS LLAMADAS" << endl;
    cout << endl;
    cout << "P) MINIMIZAR PRECIO DE LLAMADA" << endl;
    cout << "D) MINIMIZAR DISTANCIA DE LLAMADA" << endl;

    //Se guarda la opción elegida.
    cin >> this-> precioODistancia;

    this->listaDeCentrales = new Lista<Central*>;

}

void Principal::abrirArchivo() {

    string ruta = " ";

    cout << "Ingrese la ruta del archivo:" << endl;

    //Lee la ruta del archivo ingresada por teclado.
    cin >> ruta;

    //Abre el archivo que se encuentra en la ruta ingresada.
    this->archivo.open(ruta.c_str());

}

void Principal::guardarInformacionDeArchivo() {

    string evento;

    while (!archivo.eof()) {

        evento="A";

        // Se lee la primer palabra de cada l�nea para identificar el evento.
        this->archivo >> evento;

        if (evento=="Enlace") {

            this->guardarEnlace();

        } else if (evento == "Inicio") {

            this->iniciarLlamada();

        } else {

            if(evento=="Fin")

            this->finalizarLlamada();
        }
    }

}

void Principal::mostrarResultadosGuardados(){}

void Principal::guardarEnlace() {

    unsigned int numeroDeCentralA, numeroDeCentralB, canales, distancia, precio;

    // Se lee cada "palabra" de la l�nea de texto del archivo en la variable correspondiente.
    this->archivo >> numeroDeCentralA;
    this->archivo >> numeroDeCentralB;
    this->archivo >> distancia;
    this->archivo >> precio;
    this->archivo >> canales;

    // Se solicita memoria din�mica para guardar el nuevo objeto enlace.
    Enlace* nuevoEnlace = new Enlace(numeroDeCentralA, numeroDeCentralB, distancia, precio, canales);

    // Búsqueda de la central A en la lista de centrales, si no las encuentra la crea.
    Central* centralA = buscarOAsignarCentral(numeroDeCentralA);

    // Búsqueda de la central B en la lista de centrales, si no las encuentra la crea.
    Central* centralB = buscarOAsignarCentral(numeroDeCentralB);

    //Se agrega puntero a enlace creado en ambas centrales.
    centralA->agregarEnlace(nuevoEnlace);
    centralB->agregarEnlace(nuevoEnlace);

}

void Principal::iniciarLlamada(){

    unsigned int codigoCentralA, codigoInternoA, codigoCentralB, codigoInternoB, tiempoInicial;
    // Se lee cada "palabra" de la linea de texto del archivo en la variable correspondiente.
    this->archivo >> codigoCentralA;
    this->archivo >> codigoInternoA;
    this->archivo >> codigoCentralB;
    this->archivo >> codigoInternoB;
    this->archivo >> tiempoInicial;

    //Búsqueda de central A, tiene que existir ya que se cargo previamente.
    Central* centralA=this->buscarCentral(codigoCentralA);
    //Búsqueda de central B, tiene que existir ya que se cargo previamente.
    Central* centralB=this->buscarCentral(codigoCentralB);
    //Busqueda de interno de la central A, si no exite lo crea.
    Interno* internoA=centralA->buscarOAsignarInterno(codigoInternoA);
    //Busqueda de interno de la central B, si no exite lo crea.
    Interno* internoB=centralB->buscarOAsignarInterno(codigoInternoB);
    //Busqueda de llamadas realizadas por internoA a internoB,si no existe devuelve NULL.
    Llamadas* llamadas=internoA->buscarLlamadas(codigoCentralB,codigoInternoB);

    if (llamadas==NULL){ //Si no encontro las llamadas que realiza internoA a interno

        Lista<Enlace*>* listaDeConexiones=new Lista<Enlace*>;

        if (!internoB->estaOcupado() && this->seEstableceConexion(centralA,centralB,listaDeConexiones)){

            llamadas=new Llamadas(codigoCentralA,codigoInternoA,codigoCentralB,codigoInternoB,listaDeConexiones);
            Lista<Llamadas*>* listaDeLlamadasRealizadasInternoA=internoA->obtenerConjuntoLlamadasRealizadas();
            Lista<Llamadas*>* listaDeLlamadasRecibidasInternoB=internoB->obtenerConjuntoLlamadasRecibidas();
            listaDeLlamadasRealizadasInternoA->insertarElemento(llamadas);
            listaDeLlamadasRecibidasInternoB->insertarElemento(llamadas);
            internoA->cambiarEstadoEnLinea(true);
            internoB->cambiarEstadoEnLinea(true);
            internoA->cambiarEstadoOcupado(true);
            internoB->cambiarEstadoOcupado(true);
            internoA->sumarUnaLlamadaRealizada();
            internoB->sumarUnaLlamadaRecibida();
            llamadas->modificarHoraInicioLlamada(tiempoInicial);
            llamadas->sumarUnaLlamada();
            llamadas->asignarPrecioYDistancia();
            llamadas->ocuparCanales();
        }
        else{
            if (internoB->estaOcupado()){

                internoA->cambiarEstadoOcupado(true);
                internoA->sumarUnOcupadoSaliente();
                internoB->sumarUnOcupadoEntrante();
                delete listaDeConexiones;
            }
        }
    }
    else{ // si la llamada existe es porque anteriormente hubo conexión

        if ((internoB->estaOcupado()) || (!llamadas->hayCanalesDisponibles())){

            internoA->cambiarEstadoOcupado(true);
            internoA->sumarUnOcupadoSaliente();
            internoB->sumarUnOcupadoEntrante();
        }
        else{
            if ((!internoB->estaOcupado())&&(llamadas->hayCanalesDisponibles())){

                internoA->cambiarEstadoEnLinea(true);
                internoB->cambiarEstadoEnLinea(true);
                internoA->cambiarEstadoOcupado(true);
                internoB->cambiarEstadoOcupado(true);
                internoA->sumarUnaLlamadaRealizada();
                internoB->sumarUnaLlamadaRecibida();
                llamadas->modificarHoraInicioLlamada(tiempoInicial);
                llamadas->sumarUnaLlamada();
                llamadas->ocuparCanales();
                llamadas->asignarPrecioYDistancia();
            }
        }
    }
}

void Principal::finalizarLlamada(){

    unsigned int centralA,internoX,centralB,internoY,tiempoFinal;

    // Se lee cada "palabra" de la linea de texto del archivo en la variable correspondiente.
    this->archivo >> centralA;
    this->archivo >> internoX;
    this->archivo >> centralB;
    this->archivo >> internoY;
    this->archivo >> tiempoFinal;

    //Búsqueda de central A, tiene que existir ya que se cargo previamente.
    Central* centralDelEmisor=this->buscarCentral(centralA);

    //Búsqueda de central B, tiene que existir ya que se cargo previamente.
    Central* centralDelReceptor=this->buscarCentral(centralB);

    //Búsqueda de interno A, tiene que existir ya que se cargo previamente.
    Interno* actualInternoEmisor=centralDelEmisor->buscarInterno(internoX);

    //Búsqueda de interno B, tiene que existir ya que se cargo previamente.
    Interno* actualInternoReceptor=centralDelReceptor->buscarInterno(internoY);

    //Busqueda de llamadas realizadas por internoA a internoB, tiene que existir ya se cargo previamente
    Llamadas* actualLlamada=actualInternoEmisor->buscarLlamadas(centralB,internoY);

    /*Verifica si ambos internos estaban en linea, de ser as� significa que se estableci� la comunicaci�n. Por ende,
    al finalizar la llamada, se cambian sus estados de enLinea y ocupado y pasan a estar disponibles nuevamente para
    una nueva llamada.*/
    if ((actualInternoEmisor->estaEnLinea())&&(actualInternoReceptor->estaEnLinea())){

            actualLlamada->modificarHoraFinLlamada(tiempoFinal);
            actualLlamada->modificarTiempoTotalHablado();
            actualInternoEmisor->cambiarEstadoEnLinea(false);
            actualInternoReceptor->cambiarEstadoEnLinea(false);
            actualInternoEmisor->cambiarEstadoOcupado(false);
            actualInternoReceptor->cambiarEstadoOcupado(false);
            unsigned int tiempo=actualLlamada->obtenerTiempoDeLlamada();
            actualInternoEmisor->sumarTiempoALlamadasRealizadas(tiempo);
            actualInternoReceptor->sumarTiempoALlamadasRecibidas(tiempo);
            actualLlamada->liberarCanales();
            actualInternoEmisor->sumarGastos(actualLlamada->obtenerGastoDeLlamada());
    }else
            if((!actualInternoEmisor->estaEnLinea())&& (actualInternoReceptor->estaEnLinea())){

                actualInternoEmisor->cambiarEstadoOcupado(false);

            }
}


Central* Principal::buscarCentral(unsigned int numeroDeCentral) {

    this->listaDeCentrales->iniciarCursor();
    bool encontrado = false;
    Central* centralBuscada= NULL;

    while ((this->listaDeCentrales->avanzarCursor()) && (!encontrado)) {

        Central* centralActual = this->listaDeCentrales->obtenerCursor();

        if ( centralActual->obtenerNumero() == numeroDeCentral) {

            encontrado = true;
            centralBuscada=centralActual;
        }
    }

    return centralBuscada;
}

Central* Principal::buscarOAsignarCentral(unsigned int numeroDeCentral){

    Central* centralBuscada=NULL;
    centralBuscada = this->buscarCentral(numeroDeCentral);

    if (centralBuscada == NULL) {

        Central* nuevaCentral = new Central(numeroDeCentral);
        this->listaDeCentrales->insertarElemento(nuevaCentral);
        centralBuscada = nuevaCentral;

    }
    return centralBuscada;
}

Lista<Central*>* Principal::obtenerListaCentrales(){

    return this->listaDeCentrales;
}

bool Principal::seEstableceConexion(Central* centralEmisor, Central* centralReceptor, Lista<Enlace*>* &listaDeConexiones) {

    bool hayConexion = false;
    /* Si los internos pertenecen a la misma central, no hay una mejor conexión que la interna */
    if (centralEmisor->obtenerNumero() == centralReceptor->obtenerNumero()) {

        hayConexion = true;
    } else {

        Enlace* enlaceDirecto = NULL;
        Enlace* primerEnlace = NULL;
        Enlace* segundoEnlace = NULL;
        /*
        * Se evalua si existe una conexión directa entre la central del interno emisor
        * y la central del interno receptor.
        */
        if (centralEmisor->buscarEnlace(centralReceptor->obtenerNumero()) != NULL){
            /*
            * Si existe el enlace directo se guarda en la variable primerEnlace. Además se guardan
            * los valores de precio y distancia para ese enlace, para poder ser comparadas posteriormente
            * con otras posibles conexiones.
            */
            enlaceDirecto = centralEmisor->buscarEnlace(centralReceptor->obtenerNumero());
            primerEnlace = enlaceDirecto;
        }
        /*
        * La segunda parte del algoritmo, verifica si existe otra conexión entre las centrales que no sea
        * directa. Para ello debe verificarse la lista de enlaces de cada central que aparezca en la lista
        * de enlaces de la central del interno emisor.
        */
        Lista<Enlace*>* listaDeEnlaces = centralEmisor->obtenerListaDeEnlaces();
        listaDeEnlaces->iniciarCursor();

        while (listaDeEnlaces->avanzarCursor()) {

            Enlace* primerEnlaceActual = listaDeEnlaces->obtenerCursor();
            Central* centralActual = NULL;
            /* Se debe excluír el enlace directo de la siguiente búsqueda. */
            if (primerEnlaceActual != enlaceDirecto){
                /*
                * Cada objeto Enlace tiene atributos centralA y centralB que guardan los numeros de central emisora y
                * central receptora sin ningún orden específico. Es decir, no siempre centralA es quien llama y no
                * siempre centralB es quien recibe la llamada. El siguiente bloque condicional
                * se encarga de verificar cuál es la central del interno receptor.
                */
                if (primerEnlaceActual->obtenerCentralA() != centralEmisor->obtenerNumero()) {

                    centralActual = buscarCentral(primerEnlaceActual->obtenerCentralA());
                } else {
                    centralActual = buscarCentral(primerEnlaceActual->obtenerCentralB());
                }

                Lista<Enlace*>* listaDeEnlacesActual = centralActual->obtenerListaDeEnlaces();
                listaDeEnlacesActual->iniciarCursor();

                while(listaDeEnlacesActual->avanzarCursor()) {

                    Enlace* segundoEnlaceActual = listaDeEnlacesActual->obtenerCursor();
                    /*
                    * Si se encuentra una conexión indirecta (de dos enlaces) entonces se compara el precio
                    * o la distancia (según lo que haya establecido el usuario) con los mínimos actuales
                    * guardados para establecer si la conexión es más conveniente.
                    */
                    if((segundoEnlaceActual->obtenerCentralA() == centralReceptor->obtenerNumero()) ||
                    (segundoEnlaceActual->obtenerCentralB() == centralReceptor->obtenerNumero())) {

                        if (this->precioODistancia == 'P'){

                            optimizarPrecio(primerEnlace, segundoEnlace,primerEnlaceActual,segundoEnlaceActual);
                        }else {

                            optimizarDistancia(primerEnlace, segundoEnlace, primerEnlaceActual,segundoEnlaceActual);
                        }
                    }
                }
            }
        }

        listaDeConexiones->insertarElemento(primerEnlace);
        if (segundoEnlace != NULL) {

            listaDeConexiones->insertarElemento(segundoEnlace);
        }
        hayConexion =(primerEnlace != NULL);
    }
    return hayConexion;
}

void Principal::optimizarPrecio (Enlace* &primerEnlace, Enlace* &segundoEnlace, Enlace* actualPrimerEnlace, Enlace* actualSegundoEnlace){

    unsigned int precioMinimo = 9999;
    unsigned int precioActual = actualPrimerEnlace->obtenerPrecio() + actualSegundoEnlace->obtenerPrecio();

    if (primerEnlace != NULL){

        precioMinimo = primerEnlace->obtenerPrecio();
        if (segundoEnlace != NULL) {

            precioMinimo = precioMinimo + segundoEnlace->obtenerPrecio();
        }
    }

    if (precioActual < precioMinimo) {

        primerEnlace = actualPrimerEnlace;
        segundoEnlace = actualSegundoEnlace;
    }
}

void Principal::optimizarDistancia (Enlace* &primerEnlace, Enlace* &segundoEnlace, Enlace* actualPrimerEnlace, Enlace* actualSegundoEnlace){

    unsigned int distanciaMinima = 9999;
    unsigned int distanciaActual = actualPrimerEnlace->obtenerDistancia() + actualSegundoEnlace->obtenerDistancia();

    if (primerEnlace != NULL){

        distanciaMinima = primerEnlace->obtenerDistancia();
        if (segundoEnlace != NULL) {

            distanciaMinima = distanciaMinima + segundoEnlace->obtenerDistancia();
        }
    }

    if (distanciaActual<distanciaMinima) {

        primerEnlace = actualPrimerEnlace;
        segundoEnlace = actualSegundoEnlace;
    }
}

Principal::~Principal(){

    delete listaDeCentrales;
 }

