#include "FuncionesProfesores.h"
#include "Validaciones.h"
#include <iostream>
using namespace std;

void ingresarProfesor(Lista_Doble<Profesor>& profesores){
    string cedula = leerCedula();

    // No se permiten cedulas repetidas
    if (profesores.buscar(Profesor(cedula, "", "")) != nullptr){
        cout << "Ya existe un profesor con esa cedula" << endl;
        return;
    }

    string nombre = leerSoloLetras("Nombre: ");
    string apellido = leerSoloLetras("Apellido: ");

    profesores.insertarFinal(Profesor(cedula, nombre, apellido));
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