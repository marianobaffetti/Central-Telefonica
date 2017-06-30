#ifndef INTERNO_H_INCLUDED
#define INTERNO_H_INCLUDED

#include "Lista.h"
#include "Llamadas.h"

class Interno {

    private:

        unsigned int numeroDeInterno;
        unsigned int numeroDeCentral;
        unsigned int ocupadosSalientes;
        unsigned int ocupadosEntrantes;
        unsigned int tiempoTotalHablado;
        Lista<Llamadas*>* listaDeLlamadasRealizadas;
        Lista<Llamadas*>* listaDeLlamadasRecibidas;
        unsigned int totalDeLlamadasRealizadas;
        unsigned int totalDeLlamadasRecibidas;
        unsigned int gastoTotalDelInterno;
        unsigned int totalTiempoDeLlamadasRecibidas;
        unsigned int totalTiempoDeLlamadasRealizadas;
        bool ocupado;
        bool enLinea;

    public:
        /*
        *CONSTRUCTOR
        *Pre: numeroDeInterno y numeroDeCentral deben ser datos válidos
        *Post: Crea listaDeLlamadasRealizadas y listaDeLlamadasRecibidas,
        */
        Interno(unsigned int numeroDeInterno, unsigned int numeroDeCentral);
        /*
        *Post: Devuelve el numero de interno
        */
        unsigned int obtenerInterno();
        /*
        *Post:Devuelve la central a la que pertenece el Interno
        */
        unsigned int obtenerCentralPertenecienteAInterno();
        /*
        *Post:Devuelve la cantidad de ocupados salientes
        */
        unsigned int obtenerOcupadosSalientes();
        /*
        *Post: Devuelve la cantidad de ocupados entrantes
        */
        unsigned int obtenerOcupadosEntrantes();
         /*
        *Post: Devuelve la cantidad de llamadas realizadas por el interno.
        */
        unsigned int obtenerTotalDeLlamadasRealizadas();

         /*
        *Post: Devuelve la cantidad de llamadas recibidas por el interno.
        */
        unsigned int obtenerTotalDeLlamadasRecibidas();
        /*
        *Post: Devuelve los minutos totales hablados
        */
        unsigned int obtenerTiempoTotalHablado();
        /*
        *Pre: tiempoHablado debe ser un dato válido
        *Post:modifica el tiempo total hablado por el interno sumandole un tiempo hablado parcial
        */
        void modificarTiempoTotalHablado(unsigned int tiempoHablado);
        /*
        *Post: Devuelve un puntero a la lista de llamadas realizadas por un interno determinado
        */
        Lista<Llamadas*>* obtenerConjuntoLlamadasRealizadas();
        /*
        *Post: Devuelve un puntero a la lista de llamadas recibidas por un interno determinado
        */
        Lista<Llamadas*>* obtenerConjuntoLlamadasRecibidas();
        /*
        *Pre: estado debe ser un dato válido
        *Post: Modifica el estado del interno que dice si esta hablando con otro interno o no
        */
        void cambiarEstadoEnLinea(bool estado);
        /*
        *Pre: ocupado debe ser un dato válido
        *Post: Modifica el estado del interno que dice si está ocupado o no
        */
        void cambiarEstadoOcupado(bool ocupado);
        /*
        *Post: Incrementa en uno el total de ocupados que le dan otros internos cuando intenta comunicarse con ellos
        */
        void sumarUnOcupadoSaliente();
         /*
        *Post: Incrementa en uno el total de veces que el interno da ocupado a otros internos
        */
        void sumarUnOcupadoEntrante();
        /*
        *Post:Devuelve los minutos hablados por el interno en las llamadas que recibió de los demaás internos.
        */
        unsigned int obtenerTiempoDeLlamadasRecibidas();
        /*
        * Post:Devuelve los minutos hablados por el interno en las llamadas que recibió de los demaás internos.
        */
        unsigned int obtenerTiempoDeLlamadasRealizadas();
        /*
        *Pre: tiempo debe ser un dato válido
        *Post:Suma el tiempo hablado en una llamada realizada por el interno.
        */
        void sumarTiempoALlamadasRealizadas(unsigned int tiempo);
        /*
        *Pre: tiempo debe ser un dato válido
        *Post:Suma el tiempo hablado en una llamada recibida por el interno.
        */
        void sumarTiempoALlamadasRecibidas(unsigned int tiempo);
        /*
        *Pre: gastoActual debe ser un dato válido.
        *Post: Suma el gasto de una llamada al gasto total.
        */
        void sumarGastos(unsigned int gastoactual);
        /*
        *Post: Devuelve el gasto del interno entre todas las llamadas que realizó
        */
        unsigned int obtenerGastoTotal();
        /*
        *Post: Informa si el interno está ocupado o no
        */
        bool estaOcupado();
        /*
        *Post: Informa si el interno está hablando con otro interno
        */
        bool estaEnLinea();
        /*
        *Post: Incrementa en uno el total de llamadas realizadas por el interno
        */
        void sumarUnaLlamadaRealizada();
        /*
        *Post: Incrementa en uno el total de llamadas recibidas por el interno
        */
        void sumarUnaLlamadaRecibida();
        /*
        *Pre: centralB es la central del interno que recibe la llamada y debe existir,
        *internoB es el interno que recibe la llamada, debe existir
        *Post: Busca en la lista de llamadas realizadas por el interno el elemento llamadas entre ambos internos,
        *si lo encuentra devuelve su puntero, sino devuelve NULL
        */
        Llamadas* buscarLlamadas(unsigned int centralB,unsigned int internoB);
        /*
        *Post: Destructor de las listas utilizadas, libera los recursos asociados a la clase Interno
        */
        ~Interno();
};

#endif // INTERNO_H_INCLUDED
