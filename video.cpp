#include<iostream>
#include<string>
#include "Video.h"
using std::string;
using std::cout;
using std::endl;
Video::Video(){
    id="";
    nombre="";
    duracion=0;
    calificacion=0;
    fecha_estreno="";
}
Video::Video(string id1, string nom, int dur, float calif, string fecha){
    id=id1;
    nombre=nom;
    duracion=dur;
    calificacion=calif;
    fecha_estreno=fecha;
}
void Video::imprimir(){
    cout<<"ID: "<<id<<"| Nombre: "<<nombre<<"| Duracion: "<<duracion<<"|"<<endl;
    cout<<"Calificacion: "<<calificacion<<"| Fecha de estreno: "<<fecha_estreno<<"|"<<endl;
}