#ifndef CATALOGO_H
#define CATALOGO_H
#include<iostream>
#include<string>
#include<vector>
#include "Contenido.h"
using std::string;
using std::vector;
class Catalogo{
    private:
    vector<Contenido*> contenidos;
    public:
    void cargar_archivo();
    void mostrarVideo(string genero);
    void mostrarVideo(float calif);
    void mostrarEpisodio(string nom);
    void mostrarPeli(float calif);
    void califVideo(string nom, float calif);
    ~Catalogo();
};
#endif