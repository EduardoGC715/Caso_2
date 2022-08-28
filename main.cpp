#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//-----Estructura-----//
struct TFunciones {
    string nom_funcion;
    vector<string> parametros;
};
struct TDispositivos {
    string nom_dispositivo;
    string id_dispositivo;
    vector<TFunciones> funciones;
};
struct THabitaciones {
    string nom_habitacion;
    vector<TDispositivos> dispositivos;
};
struct TTareas {
    string nom_tarea;
    vector<vector<string>> specs;
};
vector<THabitaciones> habitaciones;
vector<TDispositivos> dispositivos;
vector<TTareas> tareas;

//-----Funciones de la estructura-----//
void crear_habitacion(string Phabi){
    THabitaciones habi;
    habi.nom_habitacion=Phabi;
    habitaciones.push_back(habi);
}
void crear_disp(string Pdisp){
    TDispositivos disp;
    disp.nom_dispositivo=Pdisp;
    dispositivos.push_back(disp);
}
void crear_func(string Pfunc ,string Pdisp ,vector<string> Pparam) {
    for (auto & dispositivo : dispositivos) {
        if (dispositivo.nom_dispositivo == Pdisp) {
            TFunciones func;
            func.nom_funcion = Pfunc;
            func.parametros = Pparam;
            dispositivo.funciones.push_back(func);
            break;
        }
    }
}
void add_dispositivo(string Phabi ,string Pdisp ,string Pid){
    for (auto & habitacion : habitaciones) {
        if (habitacion.nom_habitacion==Phabi) {
            for (auto & dispositivo : dispositivos){
                if (dispositivo.nom_dispositivo == Pdisp) {
                    dispositivo.id_dispositivo=Pid;
                    habitacion.dispositivos.push_back(dispositivo);
                    break;
                }
            }
            break;
        }
    }
}
//-----Creacion de tareas-----//
void crear_tarea(string Ptarea){
    TTareas tarea;
    tarea.nom_tarea=Ptarea;
    tareas.push_back(tarea);
}
void crear_specs(string Ptarea, string Phabi , string Pdisp ,string Pid, string Pfunc){
    vector <string>specs;
    string params;
    for (auto & habitacion : habitaciones) {
        if (habitacion.nom_habitacion==Phabi) {
            specs.push_back(Phabi);
            for (auto & dispositivo : habitacion.dispositivos){
                if (dispositivo.nom_dispositivo == Pdisp && dispositivo.id_dispositivo== Pid) {
                    specs.push_back(Pdisp);
                    for (auto & funcion : dispositivo.funciones){
                        if (funcion.nom_funcion == Pfunc) {
                            specs.push_back(Pfunc);
                            for(auto & parametro : funcion.parametros){
                                cout<< "Digite el parametro de "<<parametro<<" de la funcion "<<funcion.nom_funcion<<" del dispositivo "<< dispositivo.nom_dispositivo<<" de ID "<<dispositivo.id_dispositivo<<" de la habitacion " << habitacion.nom_habitacion<<endl;
                                cin>> params;
                                specs.push_back(params);
                            }
                            for (auto & tarea : tareas){
                                if(tarea.nom_tarea==Ptarea){
                                    tarea.specs.push_back(specs);
                                }
                            }
                            break;
                        }
                    }
                    break;
                }
            }
            break;
        }
    }
}

int main() {
    crear_habitacion("cuarto");
    crear_habitacion("cocina");
    crear_habitacion("comedor");

    crear_disp("bombillo");
    crear_disp("enchufe");
    crear_disp("coffe maker");

    crear_func("encender","bombillo",vector<string>{"brillo","color"});
    crear_func("encender","enchufe",vector<string>{"amperaje","voltaje"});
    crear_func("encender","coffe maker",vector<string>{"tipo","temperatura","cantidad"});

    add_dispositivo("cuarto","bombillo","1");
    add_dispositivo("cuarto","bombillo","2");
    add_dispositivo("cuarto","enchufe","1");
    add_dispositivo("cocina","bombillo","1");
    add_dispositivo("cocina","coffe maker","1");
    add_dispositivo("comedor","bombillo","1");
    add_dispositivo("comedor","bombillo","2");

    crear_tarea("buenos dias");
    crear_specs("buenos dias","cuarto","bombillo","1","encender");
    crear_specs("buenos dias","cuarto","bombillo","2","encender");
    crear_specs("buenos dias","cuarto","enchufe","1","encender");
    crear_specs("buenos dias","cocina","bombillo","1","encender");
    crear_specs("buenos dias","cocina","coffe maker","1","encender");
    crear_specs("buenos dias","comedor","bombillo","1","encender");
    crear_specs("buenos dias","comedor","bombillo","2","encender");

    for(auto & tarea : tareas){
        cout<<tarea.nom_tarea<<endl;
        for(auto & spec : tarea.specs){
            for(auto & str : spec){
                cout<<str<<" ";
            }
            cout<<endl<<"despues"<<endl;
        }
    }
}
