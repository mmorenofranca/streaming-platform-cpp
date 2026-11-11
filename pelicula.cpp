#include<sstream>
#include<iostream>
#include<fstream>
#include "Pelicula.h"
using std::cout;
using std::endl;
using std::stringstream;
Pelicula::Pelicula(){
    genero="";
}
Pelicula::Pelicula(string id1, string nom, int dur, float calif, string fecha, string gen):Video(id1,nom,dur,calif,fecha){
    genero=gen;
}
void Pelicula::mostrarPeli(float calif){
    if(calificacion>calif){
        imprimir();
    }
}
bool Pelicula::mostrarVideo(string gen){
    string generos;
    stringstream token(genero);
    bool existe=false;

    while(getline(token, generos, ';')){
        if(generos == gen){
            imprimir();
            existe=true;
        }
    }
    return existe;
}
void Pelicula::operator>(float calif){
    if(calificacion>calif){
        imprimir();
    }
}
bool Pelicula::califVideo(string nom, float calif){
    bool existe=false;
    if(nombre==nom){
        calificacion=(calificacion+calif)/2;
        existe=true;
    }
    return existe;
}
void Pelicula::imprimir(){
    Video::imprimir();
    cout<<"Genero: "<<genero<<endl;
    cout<<"-----------------------------------------------------"<<endl;
}