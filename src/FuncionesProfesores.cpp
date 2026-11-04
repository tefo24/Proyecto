#include "FuncionesProfesores.h"
#include "Validaciones.h"
#include <iostream>
using namespace std;

void ingresarProfesor(Lista_Doble<Profesor>& profesores, Lista_Doble<Materia>& materias){
    if (materias.estaVacia()){
        cout << "Primero registre materias" << endl;
        return;
    }

    string cedula = leerCedula();
    if (profesores.buscar(Profesor(cedula, "", "")) != nullptr){
        cout << "Ya existe un profesor con esa cedula" << endl;
        return;
    }
    string primerNombre = leerSoloLetras("Primer nombre: ");
    string segundoNombre = leerSoloLetrasOpcional("Segundo nombre: ");
    string primerApellido = leerSoloLetras("Primer apellido: ");
    string segundoApellido = leerSoloLetras("Segundo apellido: ");

    string nombre = primerNombre;
    if (segundoNombre != ""){
        nombre = nombre + " " + segundoNombre;
    }
    nombre = formatoNombre(nombre);
    string apellido = formatoNombre(primerApellido + " " + segundoApellido);
    Profesor profesor(cedula, nombre, apellido);
    
    profesor.setCorreo(generarCorreo(primerNombre, segundoNombre, primerApellido, profesores));
    cout << "Correo asignado: " << profesor.getCorreo() << endl;

    int cantidad = leerEnteroRango("Cuantas materias dicta (1-5): ", 1, 5);
    for (int i = 1; i <= cantidad; i++){
        int nrc = leerNRC();
        Nodo<Materia>* encontrada = materias.buscar(Materia(nrc, ""));
        if (encontrada == nullptr){
            cout << "La materia no existe" << endl;
            int opcion = leerEnteroRango("1. Intentar otro NRC  2. Omitir: ", 1, 2);
            if (opcion == 1){
                i--;
            }
        }else if (profesor.getMaterias().buscar(encontrada->getDato()) != nullptr){
            cout << "Esa materia ya esta asignada a este profesor" << endl;
            i--;
    }else{
        int nrcChoque = choqueHorario(profesor, encontrada->getDato());
        if (nrcChoque != -1){
            cout << "Choque de horario con la materia NRC " << nrcChoque << ", escoja otra" << endl;
            i--;
        }else{
            profesor.getMaterias().insertarFinal(encontrada->getDato());
        }
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

int choqueHorario(Profesor& profesor, Materia& nueva){
    Nodo<Materia>* auxMateria = profesor.getMaterias().getCabeza();
    while (auxMateria != nullptr){
        Materia& asignada = auxMateria->getDato();
        Nodo<Horario>* h1 = asignada.getHorarios().getCabeza();
        while (h1 != nullptr){
            Nodo<Horario>* h2 = nueva.getHorarios().getCabeza();
            while (h2 != nullptr){
                if (h1->getDato().getDia() == h2->getDato().getDia() &&
                    h1->getDato().getHora_Inicio() == h2->getDato().getHora_Inicio()){
                    return asignada.getNrc();
                }
                h2 = h2->getSiguiente();
            }
            h1 = h1->getSiguiente();
        }
        auxMateria = auxMateria->getSiguiente();
    }
    return -1;
}
bool existeCorreo(Lista_Doble<Profesor>& profesores, string correo){
    Nodo<Profesor>* aux = profesores.getCabeza();
    while (aux != nullptr){
        if (aux->getDato().getCorreo() == correo){
            return true;
        }
        aux = aux->getSiguiente();
    }
    return false;
}

string generarCorreo(string primerNombre, string segundoNombre, string primerApellido, Lista_Doble<Profesor>& profesores){
    string base = "";
    base += primerNombre[0];
    if (segundoNombre != ""){
        base += segundoNombre[0];
    }
    for (size_t i = 0; i < primerApellido.size(); i++){
        if (primerApellido[i] != ' '){
            base += primerApellido[i];
        }
    }
    for (size_t i = 0; i < base.size(); i++){
        if (base[i] >= 'A' && base[i] <= 'Z'){
            base[i] = base[i] + 32;
        }
    }
    string correo = base + "@espe.edu.ec";
    int numero = 1;
    while (existeCorreo(profesores, correo)){
        correo = base + to_string(numero) + "@espe.edu.ec";
        numero++;
    }
    return correo;
}

void asignarMateria(Lista_Doble<Profesor>& profesores, Lista_Doble<Materia>& materias){
    string cedula = leerCedula();
    Nodo<Profesor>* nodoProfesor = profesores.buscar(Profesor(cedula, "", ""));
    if (nodoProfesor == nullptr){
        cout << "El profesor no existe" << endl;
        return;
    }
    Profesor& profesor = nodoProfesor->getDato();
    int nrc = leerNRC();
    Nodo<Materia>* encontrada = materias.buscar(Materia(nrc, ""));
    if (encontrada == nullptr){
        cout << "La materia no existe" << endl;
        return;
    }
    if (profesor.getMaterias().buscar(encontrada->getDato()) != nullptr){
        cout << "Esa materia ya esta asignada a este profesor" << endl;
        return;
    }
    int nrcChoque = choqueHorario(profesor, encontrada->getDato());
    if (nrcChoque != -1){
        cout << "Choque de horario con la materia NRC " << nrcChoque << endl;
        return;
    }
    profesor.getMaterias().insertarFinal(encontrada->getDato());
    cout << "Materia asignada correctamente" << endl;
}