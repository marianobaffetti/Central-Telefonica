bool Llamadas::hayCanalesDisponibles() {

    bool disponible = false;

    if (!(this->listaDeEnlaces->estaVacia())) {

        this->listaDeEnlaces->iniciarCursor();

        if (this->listaDeEnlaces->avanzarCursor()) {

            disponible = !(this->listaDeEnlaces->obtenerCursor()->estaSaturado());

            if (this->listaDeEnlaces->avanzarCursor()) {

                disponible = !(this->listaDeEnlaces->obtenerCursor()->estaSaturado());
            }
        }
    }

    return disponible;
}
