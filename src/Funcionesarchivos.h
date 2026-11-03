#ifndef FUNCIONESARCHIVOS_H
#define FUNCIONESARCHIVOS_H

#include "Lista_Doble.h"
#include "Materia.h"
#include "Profesor.h"
#include "Registro.h"

//Guardar (lista -> archivo .txt)
void guardarMaterias(Lista_Doble<Materia>& materias);
void guardarProfesores(Lista_Doble<Profesor>& profesores);
void guardarRegistros(Lista_Doble<Registro>& registros);

// Cargar (archivo .txt -> lista)
void cargarMaterias(Lista_Doble<Materia>& materias);
// Las materias deben cargarse ANTES, porque cada profesor guarda solo los NRC
void cargarProfesores(Lista_Doble<Profesor>& profesores, Lista_Doble<Materia>& materias);
void cargarRegistros(Lista_Doble<Registro>& registros);

//Todo junto 
void guardarTodo(Lista_Doble<Materia>& materias, Lista_Doble<Profesor>& profesores,
                 Lista_Doble<Registro>& registros);
void cargarTodo(Lista_Doble<Materia>& materias, Lista_Doble<Profesor>& profesores,
                Lista_Doble<Registro>& registros);

#endif