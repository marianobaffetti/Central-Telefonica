#include "Interno.h"

Interno::Interno(unsigned int numeroDeInterno, unsigned int numeroDeCentral){

        this->numeroDeInterno=numeroDeInterno;
        this->numeroDeCentral=numeroDeCentral;
        this->ocupadosSalientes=0;
        this->ocupadosEntrantes=0;
        this->tiempoTotalHablado=0;
        this->listaDeLlamadasRealizadas=new Lista<Llamadas*>;
        this->listaDeLlamadasRecibidas=new Lista<Llamadas*>;
        this->totalDeLlamadasRealizadas=0;
        this->totalDeLlamadasRecibidas=0;
        this->ocupado=false;
        this->enLinea=false;
        gastoTotalDelInterno=0;
}

unsigned int Interno::obtenerInterno(){

    return this->numeroDeInterno;
}

unsigned int Interno::obtenerCentralPertenecienteAInterno(){

    return this->numeroDeCentral;
}

unsigned int Interno::obtenerOcupadosSalientes(){

    return this->ocupadosSalientes;
}

unsigned int Interno::obtenerOcupadosEntrantes(){

    return this->ocupadosSalientes;
}

unsigned int Interno::obtenerTotalDeLlamadasRealizadas(){

    return this->totalDeLlamadasRealizadas;
 }

unsigned int Interno::obtenerTotalDeLlamadasRecibidas(){

    return this->totalDeLlamadasRecibidas;
}

 unsigned int Interno::obtenerTiempoTotalHablado(){
    return this->tiempoTotalHablado;
 }

 void Interno::modificarTiempoTotalHablado(unsigned int tiempoHabladoTotal){
    this->tiempoTotalHablado=this->tiempoTotalHablado+tiempoHabladoTotal;

 }

 Lista<Llamadas*>* Interno::obtenerConjuntoLlamadasRealizadas(){
    return this->listaDeLlamadasRealizadas;
}

Lista<Llamadas*>* Interno::obtenerConjuntoLlamadasRecibidas(){

    return this->listaDeLlamadasRecibidas;
}

void Interno::cambiarEstadoEnLinea(bool estado){
    this->enLinea=estado;
}

void Interno::cambiarEstadoOcupado(bool ocupado){
    this->ocupado=ocupado;
}

void Interno::sumarUnOcupadoSaliente(){
    this->ocupadosSalientes++;
}

void Interno::sumarUnOcupadoEntrante(){
    this->ocupadosEntrantes++;

}

 unsigned int Interno::obtenerTiempoDeLlamadasRecibidas(){
        return this->totalTiempoDeLlamadasRecibidas;
 }

unsigned int Interno::obtenerTiempoDeLlamadasRealizadas(){

        return this->totalTiempoDeLlamadasRealizadas;

}

void Interno::sumarTiempoALlamadasRealizadas(unsigned int tiempo){
        this->totalTiempoDeLlamadasRealizadas=this->totalTiempoDeLlamadasRealizadas+tiempo;
}


void Interno::sumarTiempoALlamadasRecibidas(unsigned int tiempo){

    this->totalTiempoDeLlamadasRecibidas=this->totalTiempoDeLlamadasRecibidas+tiempo;

}

bool Interno::estaOcupado(){

    return this->ocupado;
}

void Interno::sumarGastos(unsigned int gasto){

    gastoTotalDelInterno+=gasto;
}

unsigned int Interno::obtenerGastoTotal(){

    return this->gastoTotalDelInterno;
}

bool Interno::estaEnLinea(){

    return this->enLinea;
}

void Interno::sumarUnaLlamadaRealizada(){

    totalDeLlamadasRealizadas++;
}

void Interno::sumarUnaLlamadaRecibida(){

    totalDeLlamadasRecibidas++;
}

Llamadas* Interno::buscarLlamadas(unsigned int centralB,unsigned int internoB){

    Lista<Llamadas*>* listaDeLlamadas=this->obtenerConjuntoLlamadasRealizadas();

    listaDeLlamadas->iniciarCursor();

    Llamadas* llamadas=NULL;

    bool seEncontroLlamadas=false;

    while ((listaDeLlamadas->avanzarCursor()) && (!seEncontroLlamadas)){

        Llamadas* llamadasActual=listaDeLlamadas->obtenerCursor();

        if ((llamadasActual->obtenerCentralReceptor()==centralB)&&(llamadasActual->obtenerInternoReceptor()==internoB)){

            llamadas=llamadasActual;
            seEncontroLlamadas=true;
        }
    }
    return llamadas;
}

Interno::~Interno(){
    delete listaDeLlamadasRealizadas;
    delete listaDeLlamadasRecibidas;
}
