#include <iostream>
#include "Lista_Doble.h"
#include "Materia.h"
#include "Profesor.h"
#include "Registro.h"
#include "Validaciones.h"
#include "FuncionesMaterias.h"
#include "FuncionesProfesores.h"
#include "FuncionesRegistros.h"
#include "FuncionesArchivos.h"
using namespace std;

void menuMaterias(Lista_Doble<Materia>& materias){
    int opcion;
    do {
        cout << endl << " MATERIAS " << endl;
        cout << "1. Ingresar materia" << endl;
        cout << "2. Agregar horario a una materia" << endl;
        cout << "3. Consultar materia" << endl;
        cout << "4. Eliminar materia" << endl;
        cout << "5. Imprimir materias" << endl;
        cout << "0. Volver" << endl;
        opcion = leerEnteroRango("Opcion: ", 0, 5);
        switch (opcion){
            case 1: ingresarMateria(materias); break;
            case 2: agregarHorarioMateria(materias); break;
            case 3: consultarMateria(materias); break;
            case 4: eliminarMateria(materias); break;
            case 5: imprimirMaterias(materias); break;
        }
    } while (opcion != 0);
}

void menuProfesores(Lista_Doble<Profesor>& profesores, Lista_Doble<Materia>& materias){
    int opcion;
    do {
        cout << endl << " PROFESORES " << endl;
        cout << "1. Ingresar profesor" << endl;
        cout << "2. Consultar profesor" << endl;
        cout << "3. Eliminar profesor" << endl;
        cout << "4. Imprimir profesores" << endl;
        cout << "5. Asignar materia a un profesor" << endl;
        cout << "0. Volver" << endl;
        opcion = leerEnteroRango("Opcion: ", 0, 5);
        switch (opcion){
            case 1: ingresarProfesor(profesores, materias); break;
            case 2: consultarProfesor(profesores); break;
            case 3: eliminarProfesor(profesores); break;
            case 4: imprimirProfesores(profesores); break;
            case 5: asignarMateria(profesores, materias); break;
        }
    } while (opcion != 0);
}

int main(){
    Lista_Doble<Materia> materias;
    Lista_Doble<Profesor> profesores;
    Lista_Doble<Registro> registros;

    cargarTodo(materias, profesores, registros);
    iniciarJornada();

    int opcion;
    do {
        cout << endl << " REGISTRO DE ASISTENCIA DOCENTE " << endl;
        cout << "1. Materias" << endl;
        cout << "2. Profesores" << endl;
        cout << "3. Registrar entrada" << endl;
        cout << "4. Registrar salida" << endl;
        cout << "5. Ver registros" << endl;
        cout << "6. Cambiar dia de la jornada" << endl;
        cout << "0. Salir" << endl;
        opcion = leerEnteroRango("Opcion: ", 0, 6);
        switch (opcion){
            case 1: menuMaterias(materias); 
            break;
            case 2: menuProfesores(profesores, materias); 
            break;
            case 3: registrarEntrada(profesores, registros); guardarTodo(materias, profesores, registros); 
            break;
            case 4: registrarSalida(profesores, registros); guardarTodo(materias, profesores, registros); 
            break;
            case 5: imprimirRegistros(registros); 
            break;
            case 6: iniciarJornada(); 
            break;
        }
    } while (opcion != 0);

    guardarTodo(materias, profesores, registros);
    cout << "Datos guardados. Hasta luego" << endl;
    return 0;
}