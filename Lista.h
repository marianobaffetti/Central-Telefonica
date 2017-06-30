#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

#ifndef NULL
#define NULL 0
#endif // NULL

#include "Nodo.h"

template<class T> class Lista {

    private:

        Nodo<T>* primero;
        unsigned int tamanio;
        Nodo<T>* cursor;

    public:
        /*
         * post: Lista vacía.
         */
        Lista();
        /*
        * post: Indica si la lista tiene algún elemento.
        */
        bool estaVacia();
        /*
        * post: Inserta un elemento al final de la lista.
        */
        void insertarElemento(T dato);
        /*
        * post: Devuelve el Dato contenido en la posicion indicada de la lista.
        */
        T obtenerElemento(unsigned int posicion);
        /*
        * pre: La lista no debe estar vacía.
        * post: Elimina el último elemento de la lista.
        */
        void borrarElemento();
        /*
        * post: Indica la cantidad de elementos que tiene la lista.
        */
        unsigned int obtenerTamanio();
        /*
         * post: deja el cursor de la Lista preparado para hacer un nuevo
         *       recorrido sobre sus elementos.
         */
        void iniciarCursor();
        /*
         * pre : se ha iniciado un recorrido (invocando el método
         *       iniciarCursor()) y desde entonces no se han agregado o
         *       removido elementos de la Lista.
         * post: mueve el cursor y lo posiciona en el siguiente elemento
         *       del recorrido.
         *       El valor de retorno indica si el cursor quedó posicionado
         *       sobre un elemento o no (en caso de que la Lista esté vacía o
         *       no existan más elementos por recorrer.)
         */
        bool avanzarCursor();
        /*
         * pre : el cursor está posicionado sobre un elemento de la Lista,
         *       (fue invocado el método avanzarCursor() y devolvió true)
         * post: devuelve el elemento en la posición del cursor.
         */
        T obtenerCursor();
        /*
         * post: libera los recursos asociados a la Lista.
         */
        ~Lista ();

    private:
        /*
         * pre : posición pertenece al intervalo: [1, contarElementos()]
         * post: devuelve el nodo en la posición indicada.
         */
        Nodo<T>* obtenerNodo(unsigned int posicion);
};


template<class T> Lista<T>::Lista() {

    this->primero = NULL;
    this->cursor = NULL;
    this->tamanio = 0;
}

template<class T> bool Lista<T>::estaVacia() {

    return (this->tamanio == 0);
}

template<class T> void Lista<T>::insertarElemento(T dato) {

   Nodo<T>* nuevoElemento = new Nodo<T>(dato);

    if (this->estaVacia()) {

        this->primero = nuevoElemento;
    } else {

        Nodo<T>* anteriorUltimo = this->obtenerNodo(this->tamanio);

        nuevoElemento->cambiarSiguiente(anteriorUltimo->obtenerSiguiente());

        anteriorUltimo->cambiarSiguiente(nuevoElemento);
    }

    this->iniciarCursor();
    this->tamanio++;
}

template<class T> T Lista<T>::obtenerElemento(unsigned int posicion) {

    T elemento = 0;

    if ((posicion>0) && (posicion<= this->tamanio)) {

        elemento = this->obtenerNodo(posicion)->obtenerDato();
    }

    return elemento;
}

template<class T> void Lista<T>::borrarElemento() {

    Nodo<T>* aBorrar = this->primero;
    this->primero = this->primero->obtenerSiguiente();
    delete aBorrar;
    tamanio--;
}

template<class T> unsigned int Lista<T>::obtenerTamanio() {

    return (this->tamanio);
}

template<class T> void Lista<T>::iniciarCursor() {

    this->cursor = NULL;
}

template<class T> bool Lista<T>::avanzarCursor() {

    if (this->cursor == NULL) {

        this->cursor = this->primero;

    } else {

        this->cursor = this->cursor->obtenerSiguiente();
    }
    return (this->cursor != NULL);
}

template<class T> T Lista<T>::obtenerCursor() {

    T elemento;
    if (this->cursor != NULL) {

        elemento = this->cursor->obtenerDato();
    }
    return elemento;
}

template<class T> Nodo<T>* Lista<T>::obtenerNodo(unsigned int posicion) {

    Nodo<T>* actual = this->primero;
    for (unsigned int i = 1; i<posicion; i++) {

        actual = actual->obtenerSiguiente();
    }
    return actual;
}

template<class T> Lista<T>::~Lista() {

    while( this->primero != NULL) {

        borrarElemento();
    }
}

#endif // LISTA_H_INCLUDED
