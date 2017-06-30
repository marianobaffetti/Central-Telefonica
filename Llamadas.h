#ifndef LLAMADAS_H_INCLUDED
#define LLAMADAS_H_INCLUDED

#include "Enlace.h"
#include "Lista.h"

class Llamadas{

    private:

        unsigned int centralEmisor;
        unsigned int centralReceptor;
        unsigned int numeroDeInternoEmisor;
        unsigned int numeroDeInternoReceptor;
        unsigned int horaInicioDeLlamada;
        unsigned int horaFinDeLlamada;
        unsigned int tiempoTotalHablado;
        unsigned int precio;
        unsigned int distancia;
        unsigned int cantidadDeLlamadas;
        Lista<Enlace*>* listaDeEnlaces;

    public:

        Llamadas(unsigned int centralA,unsigned int internoA,unsigned int centralB,unsigned int internoB,Lista<Enlace*>* listaDeEnlaces);

        /*
        *Post: Devuelve el número de la central del interno que realiza la llamada
        */
        unsigned int obtenerCentralEmisor();
         /*
        *Post: Devuelve el número de la central del interno que recibe la llamada
        */
        unsigned int obtenerCentralReceptor();
        /*
        *Post: Devuelve el interno que realiza la llamada
        */
        unsigned int obtenerInternoEmisor();
        /*
        *Post: Devuelve el interno que recibe la llamada
        */
        unsigned int obtenerInternoReceptor();
        /*
        *Post: Devuelve la hora de fin de la llamada entre los dos internos
        */
        unsigned int obtenerHoraFinDeLlamada();
        /*
        *Post: Devuelve la hora de inicio de la llamada entre los dos internos
        */
        unsigned int obtenerHoraInicioDeLlamada();
        /*
        * Post: Devuelve el precio de las llamadas entre los dos internos.
        */
        unsigned int obtenerPrecio();
        /*
        * Post: Devuelve el gasto de la llamada actual.
        */
        unsigned int obtenerGastoDeLlamada();
        /*
        *Pre: tiempoInicial dato válido.
        *Post: Modifica la hora de inicio de la llamada entre los dos internos.
        */
        void modificarHoraInicioLlamada(unsigned int tiempoInicial);
        /*
        *Pre: tiempoInicial dato válido
        *Post: Modifica la hora de fin de la llamada entre los dos internos.
        */
        void modificarHoraFinLlamada(unsigned int tiempoFinal);
         /*
        *Pre: tiempoInicial dato válido
        *Post: Modifica tiempo total de llamadas entre los dos internos agregandole el tiempo de la llamada.
        */
        void modificarTiempoTotalHablado();
        /*
        *Post: incremente en uno la cantidad de llamadas consumadas entre los dos internos.
        */
        void sumarUnaLlamada();
        /*
        *Post: devuelve la cantidad de llamadas.
        */
        unsigned int obtenerCantidadDeLlamadas();
        /*
        *Post: devuelve tiempo de llamada (tiempo final - tiempo inicial).
        */
        unsigned int obtenerTiempoDeLlamada();
        /*
        *Post: Devuelve tiempo total hablado entre todas las llamadas entre los dos internos.
        */
        unsigned int obtenerTiempoTotalHablado();
        /*
        * post: verifica si hay canales disponibles para la comunicación. Si hay devuelve verdadero.
        * Si no hay devuelve falso.
        */
        bool hayCanalesDisponibles();
        /*
        * post: ocupa los canales necesarios par ala comunicación.
        */
        void ocuparCanales();
        /*
        * post: libera los canales utilizados en la comunicación.
        */
        void liberarCanales();
        /*
        *Post: devuelve la lista de enlaces.
        */
        Lista<Enlace*>* obtenerListaDeEnlaces();
        /*
        *Pre: nuevoPrecio debe ser un dato válido.
        *Post: modifica el precio de las llamadas entre los dos internos.
        */
        void modificarPrecioPor(unsigned int nuevoPrecio);
        /*
        *Pre: nuevoDistancia debe ser un dato válido.
        *Post: modifica la distancia entre los dos internos que intervienen en la llamada.
        */
        void modificarDistanciaPor(unsigned int nuevaDistancia);
        /*
        *Pre: listaDeEnlaces debe ser un dato válido.
        *Post: inserta listaDeEnlaces en el objeto llamadas
        */
        void insertarListaDeEnlaces(Lista<Enlace*>* listadeEnlaces);
        /*
        *Post: Cálcula el precio de la llamada y la distancia entre la central a la que pertenece
        *el interno que llama y la central a la que pertenece el interno que recibe.
        */
        void asignarPrecioYDistancia();
        /*
        *Pre: listaDe Enlaces creada.
        *Post: libera el puntero a lista de enlaces.
        */
        ~Llamadas();

};

#endif // LLAMADAS_H_INCLUDED
