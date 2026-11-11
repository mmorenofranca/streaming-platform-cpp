#include<sstream>
#include<iostream>
#include<fstream>
#include<string>
#include "Catalogo.h"
#include "Serie.h"
#include "Pelicula.h"
using std::string;
using std::cout;
using std::endl;
void Catalogo::cargar_archivo(){
    std::ifstream arch;
    arch.open("Basepeliculas.csv");
    string linea,ID,Nombre,Duracion,Genero,Calificacion,Fecha_estreno,Nombre_Episodio,Temporada,Num_Episodio,ID_Episodio;
    getline(arch, linea);
    while(getline(arch,linea)){
        std::stringstream token(linea);
        getline(token,ID,',');
        getline(token,Nombre,',');
        getline(token,Duracion,',');
        getline(token,Genero,',');
        getline(token,Calificacion,',');
        getline(token,Fecha_estreno,',');
        getline(token,Nombre_Episodio,',');
        getline(token,Temporada,',');
        getline(token,Num_Episodio,',');
        getline(token,ID_Episodio,',');
        int dur = std::stoi(Duracion);
        float calif = std::stof(Calificacion);
        if(Nombre_Episodio == "") {
            Pelicula* new_pelicula = new Pelicula(ID,Nombre,dur,calif,Fecha_estreno,Genero);
            contenidos.push_back(new_pelicula);
        } else{
    
            int tempo = std::stoi(Temporada);
            int n_epi = std::stoi(Num_Episodio);
            Episodio e(ID_Episodio,Nombre_Episodio,dur,calif,Fecha_estreno,tempo,n_epi);
            bool existe = false;
            for(int i=0; i<contenidos.size(); i++) {
                Serie* ser = dynamic_cast<Serie*>(contenidos[i]);
                if(ser != 0) {
                    if(ser->darnombre() == Nombre) {
                        existe = true;
                        ser->agregar_epi(e);
                    }
                }
            }
            if(existe == false) {
                Serie* new_serie = new Serie(ID, Nombre, Genero);
                new_serie->agregar_epi(e);
                contenidos.push_back(new_serie);
            }
        }
    }
    arch.close();
}
void Catalogo::mostrarVideo(string genero){
    bool coincidencias = false; 
    for(int i = 0; i < contenidos.size(); i++) {
        if (contenidos[i]->mostrarVideo(genero) == true) {
            coincidencias = true; 
        }
    } if (coincidencias == false) {
        string s = "Intente de nuevo. El genero " + genero + " no existe";
        throw(s); 
    }
}
void Catalogo::mostrarVideo(float calif){
    for(int i=0; i<contenidos.size(); i++) {
        (*contenidos[i])>calif;
    }
}
void Catalogo::mostrarEpisodio(string nom){
    bool coincidencias=false;
    for(int i=0; i<contenidos.size(); i++) {
        Serie* ser=dynamic_cast <Serie*> (contenidos[i]);
        if(ser!=0){
            if(ser->mostrarEpisodio(nom)==true){
                coincidencias=true;
            }
        }
    }
    if(coincidencias==false){
        string s="No contamos con ningun episodio de la serie "+nom;
        throw(s);
    }
}
void Catalogo::mostrarPeli(float calif){
    cout<<"Con una calificacion mayor a "<<calif<<" se tienen las siguientes peliculas"<<endl<<endl;
    for(int i=0;i<contenidos.size();i++){
        Pelicula* peli=dynamic_cast <Pelicula*>(contenidos[i]);
        if(peli!=0){
            peli->mostrarPeli(calif);
        }
    }
}
void Catalogo::califVideo(string nom, float calif){
    bool encuentros=false;
    for(int i=0;i<contenidos.size();i++){
        if(contenidos[i]->califVideo(nom,calif)==true){
            encuentros=true;}
    }
    if (encuentros==false){
        string s = "Intente de nuevo. El video " + nom + " no existe";
        throw(s);}
}
Catalogo::~Catalogo(){
    for(int i = 0; i < contenidos.size(); i++){
        delete contenidos[i];
    }
}