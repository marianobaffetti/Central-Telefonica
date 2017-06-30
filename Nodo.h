#ifndef NODO_H_INCLUDED
#define NODO_H_INCLUDED

#ifndef NULL
#define NULL 0
#endif // NULL

template<class T> class Nodo {

    private:

        T dato;
        Nodo<T>* siguiente;

    public:
        /*
        * pre: dato debe ser un dato válido.
        * post: deja el nodo listo para usar y se guarda el dato
        */
        Nodo(T dato);
        /*
        * pre: nuevoDato debe ser un dato válido
        * post: Cambia el dato almacenado en el nodo.
        */
        void cambiarDato(T nuevoDato);
        /*
        * Post: devuelve el dato almacenado en el nodo.
        */
        T obtenerDato();
        /*
        * Pre: nuevoSiguiente debe ser un dato válido.
        * Post: se cambia el nodo siguiente.
        */
        void cambiarSiguiente(Nodo<T>* nuevoSiguiente);
        /*
        * Post: devuelve el nodo siguiente.
        */
        Nodo<T>* obtenerSiguiente();
};

template<class T> Nodo<T>::Nodo(T dato) {

    this->dato = dato;
    this->siguiente = NULL;
}

template<class T> void Nodo<T>::cambiarDato(T nuevoDato) {

    this->dato = nuevoDato;
}

template<class T> T Nodo<T>::obtenerDato() {

    return (this->dato);
}

template<class T> void Nodo<T>::cambiarSiguiente(Nodo<T>* nuevoSiguiente) {

    this->siguiente = nuevoSiguiente;
}

template<class T> Nodo<T>* Nodo<T>::obtenerSiguiente() {

    return (this->siguiente);
}


#endif // NODO_H_INCLUDED
