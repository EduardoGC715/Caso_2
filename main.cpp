#include <iostream>
#include <vector>
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
        else {
            cout << "Dispositivo no encontrado.";
        }
    }
}
void add_dispositivo(string Phabi ,string Pdisp ,string Pid){
    for (auto & habitacione : habitaciones) {
        if (habitacione.nom_habitacion==Phabi) {
            for (auto & dispositivo : dispositivos){
                if (dispositivo.nom_dispositivo == Pdisp) {
                    dispositivo.id_dispositivo=Pid;
                    habitacione.dispositivos.push_back(dispositivo);
                    break;
                }
            }
            break;
        }
    }
}
//-----Creacion de tareas-----//
void crear_specs(string Ptarea, string Phabi , string Pdisp ,string Pid, string Pfunc){
    vector <string>specs;
    string params;
    for (auto & habitacione : habitaciones) {
        if (habitacione.nom_habitacion==Phabi) {
            specs.push_back(Phabi);
            for (auto & dispositivo : habitacione.dispositivos){
                if (dispositivo.nom_dispositivo == Pdisp && dispositivo.id_dispositivo== Pid) {
                    specs.push_back(Pdisp);
                    for (auto & funcione : dispositivo.funciones){
                        if (funcione.nom_funcion == Pfunc) {
                            specs.push_back(Pfunc);
                            for(auto & parametro : funcione.parametros){
                                cout<< "Digite el parámetro de "<<parametro<<endl;
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
    cout<<"hola pp";
}
