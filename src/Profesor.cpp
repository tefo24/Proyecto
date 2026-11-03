/***********************************************************************
 * Module:  Profesor.cpp
 * Author:  RIZEN 7
 * Modified: s�bado, 31 de octubre de 2026 14:30:00
 * Purpose: Implementation of the class Profesor
 ***********************************************************************/
#include "Profesor.h"
#include <iostream>

using namespace std;

// Constructor vacio: llama al constructor vacio de Persona
Profesor::Profesor() : Persona() {
}

// Constructor con parametros: le pasa los datos a Persona
Profesor::Profesor(string cedula, string nombre, string apellido)
    : Persona(cedula, nombre, apellido) {
}

Profesor::~Profesor() {
}

// Devuelve la lista por referencia (&) para poder agregar materias a la lista real
Lista_Doble<Materia>& Profesor::getMaterias() {
    return this->materias;
}

// Dos profesores son iguales si tienen la misma cedula
bool Profesor::operator==(const Profesor& otro) const {
    return this->cedula == otro.cedula;
}

// Imprime datos personales y las materias del horario
void Profesor::imprimir() {
    imprimirDatosPersonales();      // metodo heredado de Persona
    cout << "   Materias:" << endl;

    if (materias.estaVacia()) {
        cout << "      (sin materias asignadas)" << endl;
    } else {
        for (Nodo<Materia>* actual = materias.getCabeza();
             actual != nullptr;
             actual = actual->getSiguiente()) {
            cout << "      NRC " << actual->getDato().getNrc()
                 << " - " << actual->getDato().getNombre() << endl;
        }
    }
    cout << "   ------------------------------" << endl;
}