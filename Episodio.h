#ifndef EPISODIO_H
#define EPISODIO_H
#include<iostream>
#include<string>
#include "Video.h"
using std::string;
class Episodio:public Video{
    private:
    int temporada;
    int num_episodio;
    public:
    Episodio();
    Episodio(string id1, string nom, int dur, float calif, string fecha, int tempo, int n_epi);
    void mostrarVideo(float calif);
    bool califVideo(string nom, float calif);
    void imprimir();
};
#endif