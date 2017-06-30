#ifndef MANEJODEARCHIVOS_H_INCLUDED
#define MANEJODEARCHIVOS_H_INCLUDED

#include <fstream>
#include "Lista.h"
#include "Central.h"
#include "Llamadas.h"

#ifndef NULL
#define NULL 0
#endif // NULL

class Principal {

    private:

        std::ifstream archivo;
        char precioODistancia;
        Lista<Central*>* listaDeCentrales;

    public:

        /*CONSTRUCTOR
        *Post: Queda establecido criterio de establecimiento de llamadas, se crea lista de centrales.
        */
        Principal();
        /*
        * post: Dado un archivo de texto lo abre y lo deja listo para leer.
        */
        void abrirArchivo();
        /*
        *pre: archivo abierto, debe estar bien formado.
        * post: organiza y almacena la información del archivo en diferentes listas.
        */
        void guardarInformacionDeArchivo();
        /*
        * pre: debe haber información guardada en las listas que previamente fue leída
        * de un archivo de texto.
        */
        void mostrarResultadosGuardados();
        /*
        * pre: debe haber un archivo abierto en proceso de lectura.
        * post: guarda la información de un enlace en la lista correspondiente.
        */
        void guardarEnlace();
        /*
        * pre: debe haber un archivo abierto en procedo de lectura.
        * post: guarda información sobre el inicio de una llamada entre dos internos
        * en la lista correspondiente.
        */
        void iniciarLlamada();
        /*
        * pre: debe haber una llamada en proceso.
        * post: guarda la información sobre el fin de una llamada entre dos internos
        * en la lista correspondiente.
        */
        void finalizarLlamada();
        /*
        *Pre: numeroDeCentral debe ser un dato válido.
        * post: devuelve un puntero a la central correspondiente, si no exite, devuelve un puntero a NULL
        */
        Central* buscarCentral(unsigned int numeroDeCentral);
        /*
        *Pre: numeroDeCentral debe ser un dato válido.
        * post: busca la central en la lista de centrales y devuelve un puntero a la misma.
        * Si la central no existe, la crea y devuelve un puntero a la misma.
        */
        Central* buscarOAsignarCentral(unsigned int numeroDeCentral);
         /*
        *Pre:Lista de centrales creada.
        *Post:Devuelve la lista de centrales.
        */
        Lista<Central*>*obtenerListaCentrales();
        /*
        * post: Informa si es posible realizar una conexión entre dos centrales. Además carga en el parámetro
        * listaDeConexiones los enlaces que permiten la conexión.
        */
        bool seEstableceConexion(Central* centralA,Central* centralB, Lista<Enlace*>* &listaDeConexiones);
        /*
        * pre: primer actualPrimerEnlace y actualSegundoEnlace deben ser ambos distintos de NULL.
        * post: entre dos caminos posibles, compuestos por dos enlaces, para realizar una conexión, elije el
        * que minimiza el precio de la llamada.
        */
        void optimizarPrecio (Enlace* &primerEnlace, Enlace* &segundoEnlace, Enlace* actualPrimerEnlace, Enlace* actualSegundoEnlace);
        /*
        * pre: primer actualPrimerEnlace y actualSegundoEnlace deben ser ambos distintos de NULL.
        * post: entre dos caminos posibles, compuestos por dos enlaces, para realizar una conexión, elije el
        * que minimiza la distancia de la llamada.
        */
        void optimizarDistancia (Enlace* &primerEnlace, Enlace* &segundoEnlace, Enlace* actualPrimerEnlace, Enlace* actualSegundoEnlace);

        ~Principal();
};

#endif // MANEJODEARCHIVOS_H_INCLUDED
