#ifndef FUNCIONESREGISTROS_H
#define FUNCIONESREGISTROS_H

#include <string>
#include "Profesor.h"
#include "Registro.h"
#include "Lista_Doble.h"

void iniciarJornada();
void imprimirHora(int minutos);

void registrarEntrada(Lista_Doble<Profesor>& profesores, Lista_Doble<Registro>& registros);
void registrarSalida(Lista_Doble<Profesor>& profesores, Lista_Doble<Registro>& registros);
void imprimirRegistros(Lista_Doble<Registro>& registros);

#endif