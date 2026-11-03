#include "FuncionesMaterias.h"
#include "Validaciones.h"
#include <iostream>
using namespace std;

void imprimirMaterias(Lista_Doble<Materia>& materias){
    if (materias.estaVacia()) {
        cout << "No hay materias registradas." << endl;
        return;
    }
    materias.imprimir();
}

void consultarMateria(Lista_Doble<Materia>& materias){
    int nrc = leerNRC();
    Nodo<Materia>* nodo = materias.buscar(Materia(nrc, ""));
    if (nodo == nullptr){
        cout << "La materia no existe" << endl;
        return;
    }
    nodo->getDato().imprimir();
}

void eliminarMateria(Lista_Doble<Materia>& materias){
    int nrc = leerNRC();
    if (materias.eliminar(Materia(nrc, ""))){
        cout << "Materia eliminada" << endl;
    }else{
        cout << "La materia no existe" << endl;
    }
}

string leerDia(){
    cout << endl ;
    cout << "1. Lunes" << endl;
    cout << "2. Martes" << endl;
    cout << "3. Miercoles" << endl;
    cout << "4. Jueves" << endl;
    cout << "5. Viernes" << endl;

    int opcion = leerEnteroRango("Escoja el dia (1-5): ", 1, 5);

    switch (opcion){
        case 1:
        return "Lunes";
        case 2:
        return "Martes";
        case 3:
        return "Miercoles";
        case 4:
        return "Jueves";
        case 5:
        return "Viernes";
    }
    return "Lunes";
}

int leerHora(string mensaje){
    cout << mensaje << endl;
    int horas = leerEnteroRango(" Horas (7-21): ", 7, 21);
    int minutos = leerEnteroRango(" Minutos (0-59): ", 0, 59);
    return horas * 60 + minutos;
 }

void ingresarMateria(Lista_Doble<Materia>& materias){
    int nrc = leerNRC();
    Nodo<Materia>* nodo = materias.buscar(Materia(nrc, ""));
    if (nodo != nullptr){
        cout << "La materia ya existe" << endl;
        return;
    }
    string nombre = leerTexto("Nombre de la Materia: ");

    Materia materia(nrc, nombre);
    int cantidad = leerEnteroRango("Cuantos dias a la semana dicta clases (1-5): ", 1, 5);
    for (int i = 1; i <= cantidad; i++){
        cout << "--- Horario " << i << " ---" << endl;
        int id = nrc * 10 + i;
        string dia = leerDia();
        int inicio, fin;
        leerFranja(inicio, fin);
        materia.agregarHorario(Horario(id, inicio, fin, dia));
    }
    materias.insertarFinal(materia);
    cout << "Materia registrada correctamente." << endl;
}

void agregarHorarioMateria(Lista_Doble<Materia>& materias){
    int nrc = leerNRC();
    Nodo<Materia>* nodo = materias.buscar(Materia(nrc, ""));
    if (nodo == nullptr){
        cout << "La materia no existe" << endl;
        return;
    }
    Materia& materia = nodo->getDato();

    int id = nrc * 10 + 1;
    while (materia.getHorarios().buscar(Horario(id, 0, 0, "")) != nullptr){
        id++;
    }

    string dia = leerDia();
    int inicio, fin;
    leerFranja(inicio, fin);
    materia.agregarHorario(Horario(id, inicio, fin, dia));
    cout << "Horario agregado correctamente." << endl;
}

void leerFranja(int& inicio, int& fin){
    cout << endl;
    cout << "1. 07:00 - 09:00" << endl;
    cout << "2. 09:00 - 11:00" << endl;
    cout << "3. 11:00 - 13:00" << endl;
    cout << "4. 13:00 - 15:00" << endl;
    cout << "5. 15:00 - 17:00" << endl;
    cout << "6. 17:00 - 19:00" << endl;
    cout << "7. 19:00 - 21:00" << endl;
    int opcion = leerEnteroRango("Escoja la franja: ", 1, 7);
    inicio = 420 + (opcion - 1) * 120;
    fin = inicio + 120;

}

