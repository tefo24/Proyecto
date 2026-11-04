#include "FuncionesRegistros.h"
#include "FuncionesMaterias.h"
#include "Validaciones.h"
#include <iostream>
#include <iomanip>
//#include <ctime>
using namespace std;

string diaJornada = "";

void imprimirHora(int minutos){
    cout << setfill('0') << setw(2) << minutos / 60 << ":" << setw(2) << minutos % 60;
}

// int horaReal(){
//     time_t ahora = time(0);
//     tm* t = localtime(&ahora);
//     return t->tm_hour * 60 + t->tm_min;
// }

// string diaReal(){
//     time_t ahora = time(0);
//     tm* t = localtime(&ahora);
//     string dias[7] = {"Domingo", "Lunes", "Martes", "Miercoles", "Jueves", "Viernes", "Sabado"};
//     return dias[t->tm_wday];
// }

void iniciarJornada(){
    cout << "\n INICIAR JORNADA " << endl;
    diaJornada = leerDia();
    // diaJornada = diaReal();
    cout << "Jornada: " << diaJornada << endl;
}

void registrarEntrada(Lista_Doble<Profesor>& profesores, Lista_Doble<Registro>& registros){
    string cedula = leerCedula();
    Nodo<Profesor>* nodoProfesor = profesores.buscar(Profesor(cedula, "", ""));
    if (nodoProfesor == nullptr){
        cout << "Docente no existe" << endl;
        return;
    }
    Profesor& profesor = nodoProfesor->getDato();
    profesor.imprimirDatosPersonales();

    Nodo<Registro>* auxRegistro = registros.getCabeza();
    while (auxRegistro != nullptr){
        Registro& r = auxRegistro->getDato();
        if (r.getCedula() == cedula && r.getHora_Entrada() != -1 && r.getHora_Salida() == -1){
            cout << "Registre la salida del NRC " << r.getNrc() << endl;
            return;
        }
        auxRegistro = auxRegistro->getSiguiente();
    }

    int hora = leerHora("Hora de llegada:");
    // int hora = horaReal();

    int nrcEncontrado = -1;
    int idEncontrado = -1;
    Nodo<Materia>* auxMateria = profesor.getMaterias().getCabeza();
    while (auxMateria != nullptr && nrcEncontrado == -1){
        Materia& materia = auxMateria->getDato();
        Nodo<Horario>* auxHorario = materia.getHorarios().getCabeza();
        while (auxHorario != nullptr){
            Horario& h = auxHorario->getDato();
            if (h.getDia() == diaJornada && hora >= h.getHora_Inicio() - 10 && hora <= h.getHora_Inicio() + 10){
                nrcEncontrado = materia.getNrc();
                idEncontrado = h.getId_Horario();
                break;
            }
            auxHorario = auxHorario->getSiguiente();
        }
        auxMateria = auxMateria->getSiguiente();
    }

    if (nrcEncontrado == -1){
        cout << "No tiene una clase para registrar a esta hora" << endl;
        return;
    }

    Registro nuevo(cedula, nrcEncontrado, idEncontrado, diaJornada);
    if (registros.buscar(nuevo) != nullptr){
        cout << "Ya fue registrado" << endl;
        return;
    }

    nuevo.registrarEntrada(hora);
    registros.insertarFinal(nuevo);
    cout << "Entrada registrada a las ";
    imprimirHora(hora);
    cout << " NRC: " << nrcEncontrado << endl;
}

void registrarSalida(Lista_Doble<Profesor>& profesores, Lista_Doble<Registro>& registros){
    string cedula = leerCedula();
    Nodo<Profesor>* nodoProfesor = profesores.buscar(Profesor(cedula, "", ""));
    if (nodoProfesor == nullptr){
        cout << "Docente no existe" << endl;
        return;
    }
    Profesor& profesor = nodoProfesor->getDato();

    Registro* abierto = nullptr;
    Nodo<Registro>* auxRegistro = registros.getCabeza();
    while (auxRegistro != nullptr){
        Registro& r = auxRegistro->getDato();
        if (r.getCedula() == cedula && r.getHora_Entrada() != -1 && r.getHora_Salida() == -1){
            abierto = &r;
            break;
        }
        auxRegistro = auxRegistro->getSiguiente();
    }
    if (abierto == nullptr){
        cout << "No tiene una entrada pendiente de salida" << endl;
        return;
    }

    int horaFin = -1;
    Nodo<Materia>* nodoMateria = profesor.getMaterias().buscar(Materia(abierto->getNrc(), ""));
    if (nodoMateria != nullptr){
        Nodo<Horario>* nodoHorario = nodoMateria->getDato().getHorarios().buscar(Horario(abierto->getId_Horario(), 0, 0, ""));
        if (nodoHorario != nullptr){
            horaFin = nodoHorario->getDato().getHora_Fin();
        }
    }

    int hora = leerHora("Hora de salida:");
    // int hora = horaReal();
    if (horaFin != -1 && hora < horaFin - 10){
        cout << "Aun no puede registrar la salida, disponible desde las ";
        imprimirHora(horaFin - 10);
        cout << endl;
        return;
    }
    if (horaFin != -1 && hora > horaFin + 10){
        cout << "El plazo para registrar la salida ya vencio (hasta las ";
        imprimirHora(horaFin + 10);
        cout << ")" << endl;
        return;
    }    

    if (abierto->registrarSalida(hora)){
        cout << "Salida registrada a las ";
        imprimirHora(hora);
        cout << " NRC: " << abierto->getNrc() << endl;
    }else{
        cout << "Ya fue registrado" << endl;
    }
}

void imprimirRegistros(Lista_Doble<Registro>& registros){
    if (registros.estaVacia()){
        cout << "No hay registros" << endl;
        return;
    }
    registros.imprimir();
}