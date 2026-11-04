#ifndef FUNCIONESPROFESORES_H
#define FUNCIONESPROFESORES_H

#include "Profesor.h"
#include "Lista_Doble.h"


void ingresarProfesor(Lista_Doble<Profesor>& profesores, Lista_Doble<Materia>& materias);
void consultarProfesor(Lista_Doble<Profesor>& profesores);
void eliminarProfesor(Lista_Doble<Profesor>& profesores);
void imprimirProfesores(Lista_Doble<Profesor>& profesores);
int choqueHorario(Profesor& profesor, Materia& nueva);
bool existeCorreo(Lista_Doble<Profesor>& profesores, std::string correo);
std::string generarCorreo(std::string primerNombre, std::string segundoNombre, std::string primerApellido, Lista_Doble<Profesor>& profesores);

#endif