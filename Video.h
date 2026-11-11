#ifndef VIDEO_H
#define VIDEO_H
#include<iostream>
#include<string>
using std::string;
class Video{
    protected:
    string id;
    string nombre;
    int duracion;
    float calificacion;
    string fecha_estreno;
    public:
    Video();
    Video(string id1, string nom, int dur, float calif, string fecha);
    void imprimir();
};
#endif