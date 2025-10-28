#include "agenda.h"
#include "normal.h"
#include "tarea.h"
#include "archtxt.h"
#include "repetitivo.h"

#include <fstream>
#include <algorithm>
#include <map>

Agenda::Agenda() {}

void Agenda::addTarea(Tarea *t)
{
    this->tareas.push_back(t);
}

void Agenda::leer()
{
    std::ifstream arch("data.dat", std::ios::binary);

    TareaStr str;
    Tarea* tarea;

    if(!arch.is_open()){
        return;
    }

    while (arch.read((char*)&str, sizeof(TareaStr))){
        switch(str.tipo){
        case 'A':
            tarea = new ArchTxt();
            break;
        case 'R':
            tarea = new Repetitivo(this);
            break;
        default:
            tarea = new Normal();
            break;
        }

        tarea->setStr(str);
        this->tareas.push_back(tarea);
    }

    arch.close();
}

void Agenda::guardar()
{
    std::ofstream arch("data.dat", std::ios::binary | std::ios::trunc); //Borra el contenido
    //std::ofstream arch("data.dat", std::ios::binary | std::); //Sobreescribe
    //Si quisiera leer y agregar (no sobreescribir):
                //std::ofstream arch("data.dat", std::ios::binary | std::ios::ate);
    TareaStr str;

    for (auto tarea : this->tareas){
        str = tarea->getStr(); //Obtener el struct
        arch.write((char*)&str, sizeof(TareaStr));
    }

    arch.close();

}

//Pueden ser varias porque puedo tener 2 o más tareas de igual duración y todas serían la mayor
std::vector<Tarea *> Agenda::mayorDuracion()
{
    std::vector<Tarea *> resultado;
    std::sort(this->tareas.begin(), this->tareas.end(),
    //Función lambda para ordenar por duración
              [](Tarea *a, Tarea *b) -> bool {
                  return a->getDuracion() > b->getDuracion();
              });

    int maxDuracion = this->tareas.front()->getDuracion(); //En el primero va a estar la mayor duración (el vector ya está ordenado

    for (auto tarea : this->tareas){
        if(tarea->getDuracion() == maxDuracion){
            resultado.push_back(tarea);
        }
        else{
            break;
        }
    }

    return resultado;
}

std::string Agenda::diaConMasTareas()
{
    //En un mapa los tipos no pueden ser punteros: acá el día sí o sí debe ser string
    std::map<std::string, int> mapaDias;

    for (auto tarea : this->tareas){
        mapaDias[tarea->getFecha()]++; //Si la key no existe, pone el valor por defecto (en int es 0) y si ya existe lo incrementa
    }

    std::string maxDia;
    int max = 0;

    for (auto par : mapaDias){
        if(par.second > max){ //El primero es la key, el segundo el valor
            max = par.second;
            maxDia = par.first;
        }
    }

    return maxDia;
}
