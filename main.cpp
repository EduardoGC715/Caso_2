#include <iostream>
#include "List.h"

using namespace std;
//-----Estructuras-----//
struct TFunciones {
    string nom_funcion;
    List<string> *parametros = new List<string>();
};
struct TDispositivos {
    string nom_dispositivo;
    string id_dispositivo;
    List<TFunciones> *funciones = new List<TFunciones>();
};
struct THabitaciones {
    string nom_habitacion;
    List<TDispositivos> *dispositivos = new List<TDispositivos>();
};
struct TTareas {
    string nom_tarea;
    List<List<string>> *specs = new List<List<string>>();
};
auto *habitaciones = new List<THabitaciones>();
auto *dispositivos = new List<TDispositivos>();
auto *tareas = new List<TTareas>();

//-----Funciones de la estructura-----//
void crear_habitacion(string Phabi){
    auto *habi= new THabitaciones();
    habi->nom_habitacion=Phabi;
    habitaciones->add(habi);
}
void crear_disp(string Pdisp){
    auto *disp = new TDispositivos();
    disp->nom_dispositivo=Pdisp;
    dispositivos->add(disp);
}
void crear_func(string Pfunc , string Pdisp , basic_string<char> *Pparam) {
    for (int disp=0; disp<dispositivos->getSize(); disp++) {
        if (dispositivos->find(disp)->nom_dispositivo == Pdisp) {
            auto *func = new TFunciones();
            func->nom_funcion = Pfunc;
            func->parametros->add(Pparam);
            dispositivos->find(disp)->funciones->add(func);
            break;
        }
    }
}
void add_dispositivo(string Phabi ,string Pdisp ,string Pid){
    for (int habi=0; habi<habitaciones->getSize(); habi++) {
        if (habitaciones->find(habi)->nom_habitacion==Phabi) {
            for (int disp=0; disp<dispositivos->getSize(); disp++){
                if (dispositivos->find(disp)->nom_dispositivo == Pdisp) {
                    dispositivos->find(disp)->id_dispositivo=Pid;
                    habitaciones->find(habi)->dispositivos->add(dispositivos->find(disp));
                    break;
                }
            }break;
        }
    }
}
//-----Creacion de tareas-----//
void crear_tarea(string Ptarea){
    auto *tarea = new TTareas();
    tarea->nom_tarea=Ptarea;
    tareas->add(tarea);
}
void crear_specs(string Ptarea, string Phabi , string Pdisp , string Pid, string Pfunc){
    auto *specs = new List<string>();
    string params;
    for (int habi=0; habi<habitaciones->getSize(); habi++) {
        if (habitaciones->find(habi)->nom_habitacion==Phabi) {
            specs->add(new string(Phabi));
            for (int disp=0; disp<habitaciones->find(habi)->dispositivos->getSize(); disp++){
                if (habitaciones->find(habi)->dispositivos->find(disp)->nom_dispositivo == Pdisp && habitaciones->find(habi)->dispositivos->find(disp)->id_dispositivo== Pid) {
                    specs->add(new string(Pdisp));
                    for (int func=0; func<habitaciones->find(habi)->dispositivos->find(disp)->funciones->getSize(); func++){
                        if (habitaciones->find(habi)->dispositivos->find(disp)->funciones->find(func)->nom_funcion == Pfunc) {
                            specs->add(new string(Pfunc));
                            for(int param =0; param<habitaciones->find(habi)->dispositivos->find(disp)->funciones->find(func)->parametros->getSize(); param++){

                                cout<< "Digite el parametro de ";
                                printf("%s", (string *)habitaciones->find(habi)->dispositivos->find(disp)->funciones->find(func)->parametros->find(param));
                                cout<<" de la funcion "<<habitaciones->find(habi)->dispositivos->find(disp)->funciones->find(func)->nom_funcion<<" del dispositivo "<< habitaciones->find(habi)->dispositivos->find(disp)->nom_dispositivo<<" de ID "<<habitaciones->find(habi)->dispositivos->find(disp)->id_dispositivo<<" de la habitacion " << habitaciones->find(habi)->nom_habitacion<<endl;
                                cin>> params;
                                specs->add(new string(params));
                            }
                            for (int tarea=0; tarea<tareas->getSize();tarea++){
                                if(tareas->find(tarea)->nom_tarea==Ptarea){
                                    tareas->find(tarea)->specs->add(specs);
                                }
                            }break;
                        }
                    }break;
                }
            }break;
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

    auto *uno = new List<string>();
    uno->add((basic_string<char> *) "brillo");
    uno->add((basic_string<char> *) "color");

    auto *dos = new List<string>();
    dos->add((basic_string<char> *) "amperaje");
    dos->add((basic_string<char> *) "voltaje");

    auto *tres = new List<string>();
    tres->add((basic_string<char> *) ("tipo"));
    tres->add((basic_string<char> *) "temperatura");
    tres->add((basic_string<char> *) "cantidad");


    crear_func("encender", "bombillo", reinterpret_cast<basic_string<char> *>(uno));
    crear_func("encender", "enchufe", reinterpret_cast<basic_string<char> *>(dos));
    crear_func("encender", "coffe maker", reinterpret_cast<basic_string<char> *>(tres));

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

    for(int tarea=0; tarea<tareas->getSize();tarea++ ){
        cout<<tareas->find(tarea)->nom_tarea<<endl;
        for(int spec = 0; spec<tareas->find(tarea)->specs->getSize(); spec++){
            for(int str=0; str<tareas->find(tarea)->specs->find(spec)->getSize();str++){
                printf("%s",tareas->find(tarea)->specs->find(spec)->find(str));
                cout<<" ";
            }
            cout<<endl<<"despues"<<endl;
        }
    }
}
