#ifndef OPCION_H_INCLUDED
#define OPCION_H_INCLUDED

using namespace std;

#include <string>
#include <cstring>
#include "Lista.h"

class Opcion {
    private:

        char identificador; // Un caracter que identifica posicionalmente la opcion
        string leyenda; // La descripcion de lo que hara la opcion

    public:

        /*Constructor de opcion sin parametros
          Pre: identificador es un char alfabetico y en minusculas
          Post: Se inicia la opcion con el indentificador en 'a' y la descripcion "0"
        */
        Opcion();

        /*Constructor de opcion
          Pre: identificador es un char alfabetico y en minusculas
          Post: Se inicia la opcion con el indentificador y la descripcion de la opcion
        */
        Opcion (char identificador, string leyenda);

        /*Destructor de la opcion
          Pre: Opcion creada
          Post: -
        */
        ~Opcion();

        /*Agrega un char que identifique el numero de opcion
          Pre: Identificador es un caracter alfabetico en minusculas
          Post: le asigna un valor identificatorio a la opcion
        */
        void agregarIdentificador (char identificador);

        /*Obtiene el char identifcador posicional
          Pre: -
          Post: Devuelve el char que identifica la opcion asociada
        */
        char obtenerIdentificador ();

        /*Agrega la descripcion de la opcion del menu
          Pre: La leyenda debe describir lo que la opcion realice
          Post: Le asigna el atributo de descripcion a la opcion
        */
        void agregarLeyenda (string leyenda);

        /*Obtiene la descripcion de la opcion
          Pre: -
          Post: Devuelve un string correspondiente a la opcion y su descripcion
        */
        string obtenerLeyenda ();
};

#endif // OPCION_H_INCLUDED
