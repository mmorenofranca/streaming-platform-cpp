#include<sstream>
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include "Serie.h"
using std::string;
using std::vector;
using std::cout;
using std::endl;
using std::stringstream;
Serie::Serie(){
    id="";
    nombre="";
    genero="";
}
Serie::Serie(string id1, string nom, string gen){
    id=id1;
    nombre=nom;
    genero=gen;
}
void Serie::agregar_epi(Episodio epi){
    episodios.push_back(epi);
}
bool Serie::mostrarVideo(string gen){
    string generos;
    stringstream token(genero);
    bool existe=false;

    while(getline(token, generos, ';')){
        if(generos == gen){
            cout<<"De la serie: "<<nombre<<" con genero "<<genero<<endl;
            for(int i=0; i<episodios.size(); i++){
                episodios[i].imprimir();
            }
            existe=true;
        }
    }
    return existe;
}
void Serie::operator>(float calif){
    for(int i=0;i<episodios.size();i++){
        episodios[i].mostrarVideo(calif);
        }
}
bool Serie::mostrarEpisodio(string nom){
    bool existe=false;
    if(nombre==nom){
        cout<<"De la serie "<<nom<<" existen estos episodios:"<<endl;
        for(int i=0;i<episodios.size();i++){
            episodios[i].imprimir();
        }
        existe=true;
    }
    return existe;
}
bool Serie::califVideo(string nom, float calif){
    bool coincidencia=false;
    for(int i=0;i<episodios.size();i++){
        if(episodios[i].califVideo(nom,calif)==true){
            coincidencia=true;
        }
    }
    return coincidencia;
}
string Serie::darnombre(){
    return nombre;
}