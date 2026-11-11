#include<iostream>
#include "Episodio.h"
using std::cout;
using std::string;
using std::endl;
Episodio::Episodio(){
    temporada=0;
    num_episodio=0;
}
Episodio::Episodio(string id1, string nom, int dur, float calif, string fecha, int tempo, int n_epi):Video(id1,nom,dur,calif,fecha){
    temporada=tempo;
    num_episodio=n_epi;
}
void Episodio::mostrarVideo(float calif){
    if(calificacion>calif){
        imprimir();
    }
}
bool Episodio::califVideo(string nom, float calif){
    bool existe=false;
    if(nombre==nom){
        calificacion=(calificacion+calif)/2;
;
        existe=true;
    }
    return existe;
}
void Episodio::imprimir(){
    Video::imprimir();
    cout<<"Temporada: "<<temporada<<"| Numero de episodio: "<<num_episodio<<"|"<<endl;
    cout<<"-----------------------------------------------------"<<endl;    
}