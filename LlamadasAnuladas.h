#ifndef LLAMADAANULADA_H_INCLUDED
#define LLAMADAANULADA_H_INCLUDED

#include "Principal.h"

class LlamadasAnuladas {

        private:
            unsigned int centralEmisora;
            unsigned int internoEmisor;
            unsigned int centralReceptora;
            unsigned int internoReceptor;
            unsigned int cantidadLlamadasAnuladas;

        public:
            void setCentralEmisora (unsigned int centralEmisora) { this->centralEmisora = centralEmisora;};
            void setInternoEmisor (unsigned int internoEmisor) { this->centralReceptora = centralReceptora;};
            void setCentralReceptora (unsigned int centralReceptora) { this->internoEmisor = internoEmisor;};
            void setInternoReceptor (unsigned int internoReceptor) { this->internoReceptor = internoReceptor; };
            void sumarLlamadasAnuladas (unsigned int cantidadLlamadasAnuladas) { this->cantidadLlamadasAnuladas = cantidadLlamadasAnuladas;} ;
            unsigned int getCentralEmisora () { return this->centralEmisora;};
            unsigned int getInternoEmisor() { return this->centralReceptora;};
            unsigned int getCentralReceptora() { return this->internoEmisor; };
            unsigned int getInternoReceptor () { return this->internoReceptor;};
            unsigned int obtenerCantidadLlamadasAnuladas() { return this->cantidadLlamadasAnuladas;} ;

};


/*void LlamadasAnuladas::setCentralEmisora (unsigned int centralEmisora)


void LlamadasAnuladas::setCentralReceptora(unsigned int centralReceptora)


void LlamadasAnuladas::setInternoEmisor(unsigned int internoEmisor)

void LlamadasAnuladas::setInternoReceptor(unsigned int internoReceptor)


unsigned int LlamadasAnuladas::getCentralEmisora()


unsigned int LlamadasAnuladas::getCentralReceptora()


unsigned int LlamadasAnuladas::getInternoEmisor()


unsigned int LlamadasAnuladas::getInternoReceptor()


void LlamadasAnuladas::sumarLlamadasAnuladas(unsigned int cantidadLlamadasAnuladas)


unsigned int LlamadasAnuladas::obtenerCantidadLlamadasAnuladas()*/


#endif // LLAMADAANULADA_H_INCLUDED
