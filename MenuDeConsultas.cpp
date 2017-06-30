#include "MenuDeConsultas.h"
#include <iostream>

using namespace std;

//Constructor del Menu que contiene opciones
MenuDeConsultas::MenuDeConsultas ()
{
    this->opcionesDisponibles = new Lista <Opcion*>;
}

//Agrega una nueva opcion a la lista
void MenuDeConsultas::agregarUnaOpcion (string leyenda)
{
    char identificador = 'A';
    identificador += opcionesDisponibles->obtenerTamanio();
    Opcion* nuevaOpcion = new Opcion(identificador, leyenda);
    opcionesDisponibles->insertarElemento (nuevaOpcion);
}

//Devuelve todas las opciones que se insertaron
Lista <Opcion*>* MenuDeConsultas::obtenerOpcionesDisponibles (){

    return this->opcionesDisponibles;
}

//Destructor del menu de consultas
MenuDeConsultas::~MenuDeConsultas()
{
    delete opcionesDisponibles;
}

