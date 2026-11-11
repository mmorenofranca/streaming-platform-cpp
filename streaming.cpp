#include<iostream>
#include "Streaming.h"
using std::cout;
using std::cin;
using std::endl;
using std::getline;
void Streaming::mostrar_menu(){
    while(true)
    {
        try{
        cout<<"-------------------------- MENU PRINCIPAL --------------------------"<<endl;
        cout<<"1. Cargar archivo de datos"<<endl;
        cout<<"2. Mostrar los videos en general con:"<<endl;
        cout<<"     - Una calificacion mayor a cierto parametro"<<endl;
        cout<<"     - Un cierto genero"<<endl;
        cout<<"3.  Mostrar los episodios de una determinada serie"<<endl;
        cout<<"4. Mostrar las peliculas con una calificacion mayor a cierto numero"<<endl;
        cout<<"5. Calificar un video"<<endl;
        cout<<"6. Salir"<<endl;
        cout<<"--------------------------------------------------------------------"<<endl;
        cout<<"Selecciona opcion: ";
        int opcion=asegura_int();
        if(opcion==1){
            c.cargar_archivo();
            cout<<"Se ha cargado correctamente el archivo"<<endl;
            opcion_volver();
        } else if(opcion==2){
            elegir_filtro();
        } else if(opcion==3){
            buscar_episodio();
        } else if(opcion==4){
            buscar_pelicula();
        } else if(opcion==5){
            calificar_video();
        } else if(opcion==6){
            return;
        } else{
            string s = "Intenta de nuevo. No es una opcion valida";
            throw(s);}}
        catch(string &e){
            cout<<e<<endl;
        }
}
}
int Streaming::asegura_int()
{
    string opcion;
    cin>>opcion;
    string e="Error: Debes ingresar un numero entero valido";
    try{
        return std::stoi(opcion);
    }
    catch (...){
        throw(e);
    }
}
float Streaming::asegura_float()
{
    string opcion;
    cin>>opcion;
    string e="Error: Debes ingresar un numero flotante valido";
    try{
        return std::stof(opcion);
    }
    catch (...){
        throw(e);
    }
}
void Streaming::elegir_filtro(){
    try{
        cout<<"1.  Una calificacion mayor a cierto parametro"<<endl;
        cout<<"2.  Un cierto genero"<<endl;
        cout<<"Selecciona el parametro a usar: ";
        int filtro=asegura_int();
        if(filtro==1){
            cout<<"Escribe la calificacion para filtrar: ";
            float calif=validar_calificacion();
            c.mostrarVideo(calif);
        } if(filtro==2){
            string gen;
            cout<<"Algunas opciones son:\n- Action\n- Adventure\n- Drama\n- Fantasy\n- Romance\n- Animation\n- Family\n- Musical\n- War\n- Comedy\n- Crime\n- Thriller"<<endl;
            cout<<"Escribe el genero para filtrar: ";
            cin.ignore();
            getline(cin,gen);
            c.mostrarVideo(gen);
        }
        }
        catch(string &e)
        { 
            cout<<e<<endl;
        }
    opcion_volver();
}
float Streaming::validar_calificacion(){
    float calif=asegura_float();
    if (calif < 0.0 || calif > 10.0) {
        string s = "La calificacion no es valida. Solo se permiten numeros de 0.0 a 10.0";
        throw(s);
    }
    return calif;
}
void Streaming::buscar_episodio(){
    string ser;
    cout<<"Algunas opciones son:\n- Game Of Thrones\n- Modern Family\n- The 100\n- The Simpsons\n- The Big Bang Theory\n- Death Note\n- Black Mirror\n- Stranger Things"<<endl;
    cout<<"Escribe la serie de tu interes: ";
    cin.ignore();
    getline(cin,ser);
    try{
    c.mostrarEpisodio(ser);
    }
    catch(string &e){
    cout<<e<<endl;}
    opcion_volver();
}
void Streaming::buscar_pelicula(){
    try{
    cout<<"Escribe la calificacion para filtrar: ";
    float calif=validar_calificacion();
        c.mostrarPeli(calif);
    }
    catch(string &e){
        cout<<e<<endl;
    }
    opcion_volver();
}
void Streaming::calificar_video(){
    try{
    string nom;
    cout<<"Escribe el video a calificar: ";
    cin.ignore();
    getline(cin,nom);
    cout<<"Escribe la calificacion con las que quieres puntuarlo: ";
    float calif=validar_calificacion();
    c.califVideo(nom,calif);
    }
    catch(string &e){
    cout<<e<<endl;}
    opcion_volver();
}
void Streaming::opcion_volver()
{
    int opcion=0;
    string e="Error: Debes ingresar un numero entero valido";
    while(opcion!=1)
    {    
        try {
            cout << "Presiona 1 Para Volver Al Menu: ";
            opcion = asegura_int(); 
            if (opcion != 1) {
                cout << "Opcion invalida. Debes presionar exactamente el numero 1." << endl;
            }
        }
        catch(...) {
            cout << e << endl;
    }
}
    return;
}