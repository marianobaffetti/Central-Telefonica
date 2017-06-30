#include "Enlace.h"

Enlace::Enlace(unsigned int centralA, unsigned int centralB,unsigned int distancia,unsigned int precio, unsigned int canales) {

    this->centralA = centralA;
    this->centralB = centralB;
    this->cantidadDeCanales = canales;
    this->cantidadDeCanalesOcupados=0;
    this->distancia = distancia;
    this->precio = precio;
}

unsigned int Enlace::obtenerCentralA(){

    return this->centralA;
}

unsigned int Enlace::obtenerCentralB(){

    return this->centralB;
}

unsigned int Enlace::obtenerPrecio() {

    return this->precio;
}

unsigned int Enlace::obtenerDistancia() {

    return this->distancia;
}

unsigned int Enlace::obtenerCantidadDeCanales (){

    return this->cantidadDeCanales;

}

 bool Enlace::estaSaturado(){
    return (this->cantidadDeCanales==this->cantidadDeCanalesOcupados);
 }


 void Enlace::sumarCanalOcupado(){

    this->cantidadDeCanalesOcupados++;
 }

 void Enlace::restarCanalOcupado() {

    this->cantidadDeCanalesOcupados--;
}


  Enlace::~Enlace(){


  }

