#include "FuncionesRegistros.h"
#include "FuncionesMaterias.h"
#include "Validaciones.h"
#include <iostream>
#include <iomanip>
#include <ctime>
using namespace std;

bool modoPrueba = false;
int horaPrueba = 0;
string diaPrueba = "";

void imprimirHora(int minutos){
    cout << setfill('0') << setw(2) << minutos / 60 << ":" << setw(2) << minutos % 60;
}

void configurarModoPrueba(){
    int opcion = leerEnteroRango("1. Activar modo prueba  2. Usar hora real: ", 1, 2);
    if (opcion == 1){
        diaPrueba = leerDia();
        horaPrueba = leerHora("Hora simulada:");
        modoPrueba = true;
        cout << "Modo prueba activo: " << diaPrueba << " ";
        imprimirHora(horaPrueba);
        cout << endl;
    }else{
        modoPrueba = false;
        cout << "Se usara la hora real del sistema" << endl;
    }
}

int obtenerHoraActual(){
    if (modoPrueba){
        return horaPrueba;
    }
    time_t ahora = time(nullptr);
    tm* local = localtime(&ahora);
    return local->tm_hour * 60 + local->tm_min;
}

string obtenerDiaActual(){
    if (modoPrueba){
        return diaPrueba;
    }
    string dias[7] = {"Domingo", "Lunes", "Martes", "Miercoles", "Jueves", "Viernes", "Sabado"};
    time_t ahora = time(nullptr);
    tm* local = localtime(&ahora);
    return dias[local->tm_wday];
}

string obtenerFechaActual(){
    time_t ahora = time(nullptr);
    tm* local = localtime(&ahora);
    char texto[11];
    strftime(texto, sizeof(texto), "%Y-%m-%d", local);
    return string(texto);
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

    int hora = obtenerHoraActual();
    string dia = obtenerDiaActual();
    string fecha = obtenerFechaActual();

    Nodo<Registro>* auxRegistro = registros.getCabeza();
    while (auxRegistro != nullptr){
        Registro& r = auxRegistro->getDato();
        if (r.getCedula() == cedula && r.getHora_Entrada() != -1 && r.getHora_Salida() == -1){
            cout << "Registre la salida del NRC " << r.getNrc() << endl;
            return;
        }
        auxRegistro = auxRegistro->getSiguiente();
    }

    int nrcEncontrado = -1;
    int idEncontrado = -1;
    Nodo<Materia>* auxMateria = profesor.getMaterias().getCabeza();
    while (auxMateria != nullptr && nrcEncontrado == -1){
        Materia& materia = auxMateria->getDato();
        Nodo<Horario>* auxHorario = materia.getHorarios().getCabeza();
        while (auxHorario != nullptr){
            Horario& h = auxHorario->getDato();
            if (h.getDia() == dia && hora >= h.getHora_Inicio() - 10 && hora <= h.getHora_Inicio() + 10){
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

    Registro nuevo(cedula, nrcEncontrado, idEncontrado, fecha);
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

    int hora = obtenerHoraActual();
    if (horaFin != -1 && hora < horaFin - 10){
        cout << "Aun no puede registrar la salida, disponible desde las ";
        imprimirHora(horaFin - 10);
        cout << endl;
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