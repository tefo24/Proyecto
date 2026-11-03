#ifndef FUNCIONESREGISTROS_H
#define FUNCIONESREGISTROS_H

#include <string>
#include "Profesor.h"
#include "Registro.h"
#include "Lista_Doble.h"

int obtenerHoraActual();
std::string obtenerDiaActual();
std::string obtenerFechaActual();
void imprimirHora(int minutos);
void configurarModoPrueba();

void registrarEntrada(Lista_Doble<Profesor>& profesores, Lista_Doble<Registro>& registros);
void registrarSalida(Lista_Doble<Profesor>& profesores, Lista_Doble<Registro>& registros);
void imprimirRegistros(Lista_Doble<Registro>& registros);

#endif