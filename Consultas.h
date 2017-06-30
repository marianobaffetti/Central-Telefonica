#ifndef CONSULTAS_H_INCLUDED
#define CONSULTAS_H_INCLUDED

using namespace std;

#include "MenuDeConsultas.h"
#include "Principal.h"
#include "LlamadasAnuladas.h"
#include "Enlace.h"
#include <string>
#include <stdlib.h>
#include <iostream>

class Consultas {

    private:

        Principal inicio;

    public:

        /*  Constructor de Consulta sin parametros
            Post: Crea la clase Consulta con un MenuDeConsultas asignado pero sin funciones resolucion de consultas cargadas
        */
        Consultas ();

        /*  Destructor de Consulta
            Pre: Clase Consulta creada con un MenuDeConsultas asignado
            Post: Devuelve la memoria utilizada por MenuDeConsultas
        */
        ~Consultas ();

        /*  Obtener el menu de consulta asociado
            Pre: MenuDeConsultas creado
            Post: Retorna puntero al MenuDeConsultas asignado a la clase consultas
        */
        MenuDeConsultas* obtenerMenuDeConsultas ();

        /*  Limpiar la pantalla
            Post: Limpia la pantalla de la consola respetando el sistema operativo utilizado
        */
        void limpiar_pantalla();

        /*  Dividir interno de central
            Pre: se pasa por parametro un string con el formato (XXXX-YYYY) donde los 4 digitos "XXXX" es el numero
                 de la central y los 4 digitos "YYYY" es el numero del interno y los 2 int uno para el numero de central y el otro de interno
            Post: devuelve por referencia los int con el valor de central e interno pasado por parametro
        */
        void dividirInternoDeCentral (string numeroCompleto, unsigned int &numeroCentral, unsigned int &numeroInterno);

        /*  A Continuacion todas las implementaciones de las opciones disponibles del menu para el TP2 */
        /* --------------------------------------------------------------------------------------------*/


        /*  A)
            Pre: MenuDeConsultas creado y asociado a Consultas
            Post: Imprime el detalle de las llamadas hechas entre X de la central A e Y de la central B con cantidad de llamadas,
                  cantidad de tiempo hablado y cantidad de veces ocupado (suma realizadas y recibidas A y B pueden ser iguales)
        */
        void detalleLlamadasEntreXCentralAYCentralB ();

        /*  B)
            Pre: MenuDeConsultas creado y asociado a Consultas
            Post: Imprime el interno que mas hablo de todos y de cada una de las centrales
        */
        void internoQueMasHabloDeTodosYDeCadaCentral ();

        /*  C)
            Pre: MenuDeConsultas creado y asociado a Consultas
            Post: Imprime el interno que mas veces llamo de todos y de cada una de las centrales
        */
        void internoQueMasLlamoDeTodosYDeCadaCentral ();

        /*  D)
            Pre: MenuDeConsultas creado y asociado a Consultas
            Post: Imprime el interno que mas veces le dio ocupado de todos y de cada una de las centrales
        */
        void internoQueMasLeDioOcupadoDeTodosYDeCadaCentral ();

        /*  E)
            Pre: MenuDeConsultas creado y asociado a Consultas
            Post: Imprime el interno al que mas llamaron de todos y de cada una de las centrales
        */
        void internoAlQueMasLlamaronDeTodosYDeCadaCentral ();

        /*  F)
            Pre: MenuDeConsultas creado y asociado a Consultas
            Post: Imprime el interno que mas gasto tuvo de todos y de cada una de las centrales
        */
        void internoQueMasGastoDeTodosYDeCadaCentral ();

        /*  G)
            Pre: MenuDeConsultas creado y asociado a Consultas
            Post: Imprime el interno al que mas le hablaron de todos y de cada una de las centrales
        */
        void internoAlQueMasLeHablaronDeTodosYDeCadaCentral ();

        /*  H)
            Pre: MenuDeConsultas creado y asociado a Consultas
            Post: Imprime el Interno que genero mas ocupados de todos y de cada una de las centrales
        */
        void internoQueMasDioOcupadoDeTodosYDeCadaCentral ();

        /*  I)
            Pre: MenuDeConsultas creado y asociado a Consultas
            Post: Imprime el detalle de las llamadas emitidas por el interno X de la central A
        */
        void detalleDeLlamadasEmitidasPorXDeCentralA ();

        /*  J)
            Pre: MenuDeConsultas creado y asociado a Consultas
            Post: Imprime el detalle de las llamadas recibidas por X de la central A
        */
        void detalleDeLlamadasRecibidasPorXDeCentralA ();

        /*  K)
            Pre: MenuDeConsultas creado y asociado a Consultas
            Post: Imprime el detalle de las llamadas emitidas por X de la central A y recibidas por Y de la central B
        */
        void detalleDeLlamadasRealizadasDeXDeAAYDeB ();

        /*  L)
            Pre: MenuDeConsultas creado y asociado a Consultas
            Post: Imprime el detalle de las llamadas recibidas por X de la central A y emitidas por Y de la central B
        */
        void detalleDeLlamadasRecibidasPorXDeADeYDeB ();

        /*  M)
            Pre: MenuDeConsultas creado y asociado a Consultas
            Post: Imprime la cantidad de llamadas anuladas, por falta de enlaces por central, ordenado por cantidad descendiente
        */
        void cantidadDeLlamadasAnuladas ();

        /*  N)
            Pre: MenuDeConsultas creado y asociado a Consultas
            Post: Imprime el detalle de todos los enlaces cargados
        */
        void imprimirDetalleDeEnlaces ();

        /*  O)
            Pre: MenuDeConsultas creado y asociado a Consultas
            Post: Imprime el detalle de todos los internos cargados
        */
        void imprimirDetalleDeInternos ();

        /*  P)
            Pre: MenuDeConsultas creado y asociado a Consultas
            Post: Imprime el detalle de todas las centrales cargadas
        */
        void imprimirDetalleDeCentrales ();

};

#endif // CONSULTAS_H_INCLUDED
