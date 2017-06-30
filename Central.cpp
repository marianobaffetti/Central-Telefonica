#include "Central.h"
#include "Enlace.h"

Central::Central(unsigned int numeroDeCentral) {

    this->numeroDeCentral = numeroDeCentral;
    this->listaDeEnlaces = new Lista<Enlace*>;
    this->listaDeInternos = new Lista<Interno*>;
}

void Central::agregarEnlace(Enlace* nuevoEnlace) {

   this->listaDeEnlaces->insertarElemento(nuevoEnlace);
}

 Enlace* Central::buscarEnlace(unsigned int numeroDeCentral) {

    Enlace* enlaceBuscado = NULL;
    Enlace* enlaceActual;
    bool encontrado = false;

    this->listaDeEnlaces->iniciarCursor();

    while((this->listaDeEnlaces->avanzarCursor()) && (!encontrado)) {

        enlaceActual = this->listaDeEnlaces->obtenerCursor();

        if((enlaceActual->obtenerCentralA() == numeroDeCentral) || (enlaceActual->obtenerCentralB() == numeroDeCentral)){

            encontrado = true;
            enlaceBuscado = enlaceActual;
        }
    }

    return enlaceBuscado;
 }

Interno* Central::buscarOAsignarInterno(unsigned int numeroDeInterno) {

   Interno* internoBuscado = this->buscarInterno(numeroDeInterno);

   if (internoBuscado == NULL) {

        Interno* nuevoInterno = new Interno(numeroDeInterno, this->numeroDeCentral);
        this->listaDeInternos->insertarElemento(nuevoInterno);
        internoBuscado = nuevoInterno;
    }
    return internoBuscado;
}


Interno* Central::buscarInterno(unsigned int numeroDeInterno) {

    Interno* internoBuscado = NULL;
    Interno* internoActual;
    bool encontrado = false;

    this->listaDeInternos->iniciarCursor();

    while((this->listaDeInternos->avanzarCursor()) && (!encontrado)) {

        internoActual = this->listaDeInternos->obtenerCursor();

        if (internoActual->obtenerInterno() == numeroDeInterno) {

            encontrado = true;
            internoBuscado = internoActual;
        }
    }

    return internoBuscado;

 }

 unsigned int Central::obtenerNumero() {

    return this->numeroDeCentral;
 }

 Lista<Enlace*>* Central::obtenerListaDeEnlaces() {

    return this->listaDeEnlaces;
 }

 Lista<Interno*>* Central::obtenerListaDeInternos(){

    return this->listaDeInternos;

 }

 Central::~Central(){

    delete listaDeEnlaces;
    delete listaDeInternos;

 }
