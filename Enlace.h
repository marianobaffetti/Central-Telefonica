#ifndef ENLACE_H_INCLUDED
#define ENLACE_H_INCLUDED

class Enlace{

    private:

        unsigned int centralA,centralB;
        unsigned int distancia,precio;
        unsigned int cantidadDeCanalesOcupados,cantidadDeCanales;

    public:

        /*  pre: centralA,centralB: codigo de central de tipo cadena
                distancia,precio,cantDeCanales enteros mayores a 0
            post: Inicializa los atributos asignándoles los argumentos ingresados,
                salvo a cantidadDeCanalesOcupados que se le asigna 0
        */
        Enlace(unsigned int centralA, unsigned int centralB,unsigned int distancia,unsigned int precio, unsigned int cantDeCanales);

        /*  Pre: No tiene
            Post: Devuelve el codigo de la centralA
        */
        unsigned int obtenerCentralA();

        /*  Pre: No tiene
            Post: Devuelve el codigo de la centralB
        */
        unsigned int obtenerCentralB();

        /*  pre: No tiene
            post: Devuelve un valor entero que representa la distancia en kilometros entre centralA y centralB
        */
        unsigned int obtenerDistancia ();

        /*  pre: No tiene
            post: Devuelve un valor entero que representa el precio de utilizar el enlace entre centralA y centralB por minuto
        */
        unsigned int obtenerPrecio ();

        /*  pre: No tiene
            post: Devuelve un valor entero que representa la cantidad de canales de comunicacion que posee el enlace entre centralA y centralB
        */
        unsigned int obtenerCantidadDeCanales ();

        /*  pre: No tiene
            post: Dice si todos los canales del enlace estan ocupados
        */
        bool estaSaturado();

        /*  pre: Debe haber al menos un canal libre
            post: Incrementa en uno la cantidad de canales ocupados
        */
        void sumarCanalOcupado();
        /*
            post: decrementa en uno la cantidad de canales ocupados
        */
        void restarCanalOcupado();
        /*post: No hace nada
        */
        ~Enlace();

};

#endif // ENLACE_H_INCLUDED
