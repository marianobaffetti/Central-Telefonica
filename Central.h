#ifndef CENTRAL_H_INCLUDED
#define CENTRAL_H_INCLUDED

#ifndef NULL
#define NULL 0
#endif // NULL

#include "Enlace.h"
#include "Interno.h"

class Central {

    private:

        unsigned int  numeroDeCentral;
        Lista<Enlace*>* listaDeEnlaces;
        Lista<Interno*>* listaDeInternos;

    public:
        /*
        * pre: numeroDeCentral dato válido
        * post: crea un objeto de la clase Central
        */
        Central(unsigned int numeroDeCentral);
        /*
        * pre: nuevoEnlace dato válido.
        * post: agrega un nuevo enlace en listaDeEnlaces.
        */
        void agregarEnlace(Enlace* nuevoEnlace);
        /*
        * pre: numeroDeCentral dato válido.
        * post: devuleve un puntero al enlace con la central cuyo numeroDeCentral
        * coincida con el parametro numeroDeCentral. Si no encuentra coincidencia
        * devuelve un puntero que apunta a NULL.
        */
        Enlace* buscarEnlace(unsigned int numeroDeCentral);
        /*
        * pre: numeroDeInterno dato válido.
        * post: Devuelve un puntero al objeto interno a partir de su numeroDeInterno.
        * Si no encuentra el interno lo crea.
        */
        Interno* buscarOAsignarInterno(unsigned int numeroDeInterno);
        /*
        * pre: numero de interno dato valido.
        * post: Devuelve un puntero al objeto interno a partir de su numeroDeInterno.
        */
        Interno* buscarInterno(unsigned int numeroDeInterno);
        /*
        * post: devuelve un puntero a listaDeEnlaces.
        */
        Lista<Enlace*>* obtenerListaDeEnlaces();
        /*
        *Pre: Lista de internos creada.
        *Post: Devuelve la lista de internos de la central.
        */
        Lista<Interno*>*obtenerListaDeInternos();
        /*
        * post: devuelve el numero de central.
        */

        unsigned int obtenerNumero();
        /* pre: lista de enlaces y lista de internos creadas.
        * post: libera recursos asociados a lista de enlaces y lista de internos.
        */
        ~Central();
};

#endif // CENTRAL_H_INCLUDED
