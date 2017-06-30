#ifndef INTERFAZ_H_INCLUDED
#define INTERFAZ_H_INCLUDED

using namespace std;

#include "Consultas.h"
#include "Principal.h"

class Interfaz {

        private:

            MenuDeConsultas* menuConsultasTP2; // Atributo de la clse menu de consultas que almacenara todo el menu utilizado
            Consultas consultaARealizar;

        public:

            Interfaz();
            ~Interfaz();
            /*void aMayusculas (string &a);*/
            void otraConsulta (char &opcionElegida);
            MenuDeConsultas* obtenerMenuDeConsultas();
            void cargarConsultasEnMenu ();
            void imprimirMenu ();
            void interfazMenu ();

};


#endif // INTERFAZ_H_INCLUDED
