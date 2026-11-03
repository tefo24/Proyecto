#ifndef FUNCIONESMATERIAS_H
#define FUNCIONESMATERIAS_H

#include <string>
#include "Materia.h"
#include "Lista_Doble.h"

std::string leerDia();                      
int leerHora(std::string mensaje);          

void ingresarMateria(Lista_Doble<Materia>& materias);
void agregarHorarioMateria(Lista_Doble<Materia>& materias);
void eliminarMateria(Lista_Doble<Materia>& materias);
void consultarMateria(Lista_Doble<Materia>& materias);
void imprimirMaterias(Lista_Doble<Materia>& materias);
void leerFranja(int& inicio, int& fin);

#endif