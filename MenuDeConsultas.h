#ifndef MENUDECONSULTAS_H_INCLUDED
#define MENUDECONSULTAS_H_INCLUDED


#include <string>
#include "Opcion.h"


class MenuDeConsultas {

    private:

        Lista <Opcion*>* opcionesDisponibles; // La lista completa de opciones que se agregan con identificador y descripcion

    public:
        /*Constructor del menu
          Pre: -
          Post: Inicia la lista de opciones en vacio
        */
        MenuDeConsultas ();

        /*Destructor del menu
          Pre: Menu debe haber sido creado
          Post: Elimna el menu y libera la memoria utilizada
        */
        ~MenuDeConsultas();

        /*Agrega una nueva opcion a la lista
          Pre: El string debe indicar lo que realizara la opcion
          Post: Inserta una nueva opcion en la lista de opciones
        */
        void agregarUnaOpcion (string leyenda);

        /*Devuelve la lista completa con identificador y descripcion completa
          Pre: Lista creada
          Post: Devuelve la lista con todos los nodos opcion que tenga
        */
        Lista <Opcion*>* obtenerOpcionesDisponibles ();
};




#endif // MENUDECONSULTAS_H_INCLUDED
