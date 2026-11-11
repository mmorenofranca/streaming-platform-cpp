#ifndef SERIE_H
#define SERIE_H
#include<iostream>
#include<string>
#include<vector>
#include "Contenido.h"
#include "Episodio.h"
using std::string;
using std::vector;
class Serie:public Contenido{
    private:
    string id;
    string nombre;
    string genero;
    vector<Episodio> episodios;
    public:
    Serie();
    Serie(string id1, string nom, string gen);
    void agregar_epi(Episodio epi);
    bool mostrarVideo(string genero);
    void operator>(float calif);
    bool mostrarEpisodio(string nom);
    bool califVideo(string nom, float calif);
    string darnombre();
};
#endif