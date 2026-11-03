#include "FuncionesProfesores.h"
#include "Validaciones.h"
#include <iostream>
using namespace std;

void ingresarProfesor(Lista_Doble<Profesor>& profesores, Lista_Doble<Materia>& materias){
    string cedula = leerCedula();
    if (profesores.buscar(Profesor(cedula, "", "")) != nullptr){
        cout << "Ya existe un profesor con esa cedula" << endl;
        return;
    }
    string nombre = leerSoloLetras("Nombre: ");
    string apellido = leerSoloLetras("Apellido: ");
    Profesor profesor(cedula, nombre, apellido);

    if (materias.estaVacia()){
        cout << "Primero registre materias" << endl;
        return;
    }

    int cantidad = leerEnteroRango("Cuantas materias dicta (1-5): ", 1, 5);
    for (int i = 1; i <= cantidad; i++){
        int nrc = leerNRC();
        Nodo<Materia>* encontrada = materias.buscar(Materia(nrc, ""));
        if (encontrada == nullptr){
            cout << "La materia no existe" << endl;
            int opcion = leerEnteroRango("1. Intentar otro NRC 2. Omitir: ", 1, 2);
            if (opcion == 1){
                i--;
            }
        }else{
            profesor.getMaterias().insertarFinal(encontrada->getDato());
        }
    }

    profesores.insertarFinal(profesor);
    cout << "Profesor ingresado correctamente" << endl;
}

void consultarProfesor(Lista_Doble<Profesor>& profesores){
    string cedula = leerCedula();
    Nodo<Profesor>* nodo = profesores.buscar(Profesor(cedula, "", ""));
    if (nodo == nullptr){
        cout << "El profesor no existe" << endl;
        return;
    }
    nodo->getDato().imprimir();
}

void eliminarProfesor(Lista_Doble<Profesor>& profesores){
    string cedula = leerCedula();
    if (profesores.eliminar(Profesor(cedula, "", ""))){
        cout << "Profesor eliminado" << endl;
    }else{
        cout << "El profesor no existe" << endl;
    }
}

void imprimirProfesores(Lista_Doble<Profesor>& profesores){
    if (profesores.estaVacia()){
        cout << "No hay profesores registrados." << endl;
        return;
    }
    profesores.imprimir();
}