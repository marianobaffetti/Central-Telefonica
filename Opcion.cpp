#include "Opcion.h"


//Constructor de opcion sin parametros
Opcion::Opcion()
{
    this->identificador = 'a';
    this->leyenda = "0";
}

//Constructor de opcion con parametros
Opcion::Opcion (char identificador, string leyenda)
{
    this->identificador = identificador;
    this->leyenda = leyenda;
}

//Agrega un char que identifique el numero de opcion
void Opcion::agregarIdentificador (char identificador){
    this->identificador = identificador;
}

//Agrega la descripcion de la opcion del menu
void Opcion::agregarLeyenda (string leyenda){
    this->leyenda = leyenda;
}

//Obtiene el char identifcador posicional
char Opcion::obtenerIdentificador (){
    return this->identificador;
}

//Obtiene la descripcion de la opcion
string Opcion::obtenerLeyenda (){
    return this->leyenda;
}

//Destructor de la opcion
Opcion::~Opcion()
{
}
