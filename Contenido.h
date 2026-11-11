#ifndef CONTENIDO_H
#define CONTENIDO_H
#include<iostream>
#include<string>
using std::string;
class Contenido{
    public:
    virtual void operator>(float calif) = 0;
    virtual bool mostrarVideo(string genero) = 0;
    virtual bool califVideo(string nom, float calif) = 0;
    virtual ~Contenido(){};
};
#endif