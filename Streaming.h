#ifndef STREAMING_H
#define STREAMING_H
#include "Catalogo.h"
class Streaming{
    private:
    string nombre;
    Catalogo c;
    public:
    void mostrar_menu();
    int asegura_int();
    float asegura_float();
    void elegir_filtro();
    void buscar_episodio();
    void opcion_volver();
    void buscar_pelicula();
    void calificar_video();
    float validar_calificacion();
};
#endif