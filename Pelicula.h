#ifndef PELICULA_H
#define PELICULA_H
#include<iostream>
#include<string>
#include "Video.h"
#include "Contenido.h"
using std::string;
class Pelicula:public Video,public Contenido{
    private:
    string genero;
    public:
    Pelicula();
    Pelicula(string id1, string nom, int dur, float calif, string fecha, string gen);
    void mostrarPeli(float calif);
    bool mostrarVideo(string gen);
    void operator>(float calif);
    bool califVideo(string nom, float calif);
    void imprimir();
};
#endif