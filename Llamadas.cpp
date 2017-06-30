#include "Llamadas.h"

Llamadas::Llamadas(unsigned int centralA,unsigned int internoA,unsigned int centralB,unsigned int internoB,Lista<Enlace*>* listaDeEnlaces){

    this->centralEmisor=centralA;
    this->centralReceptor=centralB;
    this->numeroDeInternoEmisor=internoA;
    this->numeroDeInternoReceptor=internoB;
    this->horaInicioDeLlamada=0;
    this->horaFinDeLlamada=0;
    this->tiempoTotalHablado=0;
    this->precio=0;
    this->distancia=0;
    this->cantidadDeLlamadas=0;
    this->listaDeEnlaces=listaDeEnlaces;
}

unsigned int Llamadas::obtenerCentralEmisor(){

    return this->centralEmisor;
}

unsigned int Llamadas::obtenerCentralReceptor(){

    return this->centralReceptor;
}

unsigned int Llamadas::obtenerInternoEmisor(){

    return this->numeroDeInternoEmisor;
}

unsigned int Llamadas::obtenerInternoReceptor(){

    return this->numeroDeInternoReceptor;
}

unsigned int Llamadas::obtenerHoraFinDeLlamada(){

    return this->horaFinDeLlamada;
}

unsigned int Llamadas::obtenerHoraInicioDeLlamada(){

    return this->horaInicioDeLlamada;
}

void Llamadas::modificarHoraInicioLlamada(unsigned int tiempoInicial){

    this->horaInicioDeLlamada=tiempoInicial;
}

void Llamadas::modificarHoraFinLlamada(unsigned int tiempoFinal){

    this->horaFinDeLlamada=tiempoFinal;
}

void Llamadas::sumarUnaLlamada(){

    this->cantidadDeLlamadas++;
}

unsigned int Llamadas::obtenerTiempoTotalHablado(){

    return tiempoTotalHablado;
}

void Llamadas::modificarTiempoTotalHablado(){

    tiempoTotalHablado+=obtenerTiempoDeLlamada();
}

unsigned int Llamadas::obtenerTiempoDeLlamada(){

    unsigned int tiempoDeLlamada=obtenerHoraFinDeLlamada()-obtenerHoraInicioDeLlamada();

    return tiempoDeLlamada;
}

unsigned int Llamadas::obtenerPrecio(){

    return precio;
}

unsigned int Llamadas::obtenerGastoDeLlamada(){

    unsigned int gastoActual=obtenerTiempoDeLlamada()*obtenerPrecio();
    return gastoActual;
}

bool Llamadas::hayCanalesDisponibles() {

    bool disponible = false;

    this->listaDeEnlaces->iniciarCursor();
    this->listaDeEnlaces->avanzarCursor();

    Enlace* enlaceActual= this->listaDeEnlaces->obtenerCursor();

    if (this->listaDeEnlaces->obtenerTamanio() == 2) {

        bool hayEnlacesEnPrimerCentral =!(enlaceActual->estaSaturado());
        this->listaDeEnlaces->avanzarCursor();
        enlaceActual = this->listaDeEnlaces->obtenerCursor();

        disponible = ((hayEnlacesEnPrimerCentral) && !(enlaceActual->estaSaturado()));

    } else {

        disponible = !(enlaceActual->estaSaturado());
    }

    return disponible;
}

void Llamadas::ocuparCanales() {

    this->listaDeEnlaces->iniciarCursor();

    Enlace* enlaceActual=NULL;

    if (this->listaDeEnlaces->obtenerTamanio()==1){

        enlaceActual=this->listaDeEnlaces->obtenerCursor();

        enlaceActual->sumarCanalOcupado();
    }

    if (this->listaDeEnlaces->obtenerTamanio() == 2) {

        this->listaDeEnlaces->avanzarCursor();
        enlaceActual = this->listaDeEnlaces->obtenerCursor();
        enlaceActual->sumarCanalOcupado();
    }

    this->listaDeEnlaces->iniciarCursor();
}

void Llamadas::liberarCanales(){

    this->listaDeEnlaces->iniciarCursor();
    this->listaDeEnlaces->avanzarCursor();

    Enlace* enlaceActual= this->listaDeEnlaces->obtenerCursor();
    enlaceActual->restarCanalOcupado();

    if (this->listaDeEnlaces->obtenerTamanio() == 2) {

        this->listaDeEnlaces->avanzarCursor();
        enlaceActual = this->listaDeEnlaces->obtenerCursor();
        enlaceActual->restarCanalOcupado();
    }
    this->listaDeEnlaces->iniciarCursor();
}

Lista<Enlace*>* Llamadas::obtenerListaDeEnlaces() {

    return this->listaDeEnlaces;
}

void Llamadas::insertarListaDeEnlaces(Lista<Enlace*>* listadeEnlaces){


    this->listaDeEnlaces=listaDeEnlaces;
}

void Llamadas::asignarPrecioYDistancia() {

    Lista<Enlace*>* enlacesDeConexion = this->obtenerListaDeEnlaces();
    unsigned int precio = 10;
    unsigned int distancia = 0;
    enlacesDeConexion->iniciarCursor();

    if(enlacesDeConexion->avanzarCursor()) {
        Enlace* enlaceActual = enlacesDeConexion->obtenerCursor();
        precio = enlaceActual->obtenerPrecio();
        distancia = enlaceActual->obtenerDistancia();

        if (enlacesDeConexion->avanzarCursor()) {

            enlaceActual = enlacesDeConexion->obtenerCursor();
            precio = precio + enlaceActual->obtenerPrecio();
            distancia = distancia + enlaceActual->obtenerDistancia();
        }
    }
    this->modificarDistanciaPor(distancia);

    this->modificarPrecioPor(precio);
}

void Llamadas::modificarPrecioPor(unsigned int nuevoPrecio){

    this->precio=nuevoPrecio;
}

void Llamadas::modificarDistanciaPor(unsigned int nuevaDistancia){

    this->distancia=nuevaDistancia;
}

unsigned int Llamadas::obtenerCantidadDeLlamadas(){

    return cantidadDeLlamadas;
}

Llamadas::~Llamadas(){

    delete listaDeEnlaces;
}
