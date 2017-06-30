/*
    Programa: Central Telefónica 2.0
    Autores:


    Año:
*/
#include <iostream>
#include <fstream>
#include <string>
#include "Interfaz.h"

using namespace std;


int main() {

    Interfaz interfazTP2;

    interfazTP2.cargarConsultasEnMenu();
    interfazTP2.interfazMenu();

    return 0;
}
