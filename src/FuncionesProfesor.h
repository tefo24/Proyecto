#ifndef FUNCIONESPROFESORES_H
#define FUNCIONESPROFESORES_H

#include "Profesor.h"
#include "Lista_Doble.h"

void ingresarProfesor(Lista_Doble<Profesor>& profesores);
void consultarProfesor(Lista_Doble<Profesor>& profesores);
void eliminarProfesor(Lista_Doble<Profesor>& profesores);
void imprimirProfesores(Lista_Doble<Profesor>& profesores);

#endif