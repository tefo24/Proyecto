#include "FuncionesArchivos.h"
#include "Validaciones.h"
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

// Los archivos se crean en la misma carpeta desde donde se ejecuta el programa
const string ARCHIVO_MATERIAS   = "materias.txt";
const string ARCHIVO_PROFESORES = "profesores.txt";
const string ARCHIVO_REGISTROS  = "registros.txt";

/*
  FORMATO DE CADA ARCHIVO (una linea por dato, campos separados por ;)

  materias.txt   ->  nrc;nombre;cantidadHorarios;id,inicio,fin,dia;id,inicio,fin,dia
                     Ejemplo: 11111;Calculo;2;1,7,9,Lunes;2,9,11,Martes

  profesores.txt ->  cedula;nombre;apellido;nrc1,nrc2,nrc3
                     Ejemplo: 1710034065;Ana;Lopez;11111,22222

  registros.txt  ->  cedula;nrc;id_Horario;fecha;hora_Entrada;hora_Salida
                     Ejemplo: 1710034065;11111;1;2026-11-02;425;540
*/

// ------------------------------------------------------------
//  Convierte texto a numero. Devuelve false si el texto no es un
//  numero valido (acepta el signo - por si hora_Salida vale -1).
// ------------------------------------------------------------
static bool aEntero(string texto, int& resultado){
    bool negativo = false;
    if (!texto.empty() && texto[0] == '-'){
        negativo = true;
        texto = texto.substr(1);
    }
    if (!soloNumeros(texto) || texto.size() > 9){
        return false;
    }
    resultado = stoi(texto);
    if (negativo) resultado = -resultado;
    return true;
}
static string horaATexto(int minutos){
    string texto = "";
    if (minutos / 60 < 10) texto += "0";
    texto += to_string(minutos / 60) + ":";
    if (minutos % 60 < 10) texto += "0";
    texto += to_string(minutos % 60);
    return texto;
}

static bool textoAHora(string texto, int& minutos){
    size_t pos = texto.find(':');
    if (pos == string::npos) return false;
    int h, m;
    if (!aEntero(texto.substr(0, pos), h) || !aEntero(texto.substr(pos + 1), m)) return false;
    if (h > 23 || m > 59) return false;
    minutos = h * 60 + m;
    return true;
}

// ============================================================
//  MATERIAS
// ============================================================
void guardarMaterias(Lista_Doble<Materia>& materias){
    ofstream archivo(ARCHIVO_MATERIAS);
    if (!archivo.is_open()){
        cout << "No se pudo crear " << ARCHIVO_MATERIAS << endl;
        return;
    }
    int cantidad = 0;
    for (Nodo<Materia>* nodo = materias.getCabeza(); nodo != nullptr; nodo = nodo->getSiguiente()){
        Materia& m = nodo->getDato();
        int total = 0;
        for (Nodo<Horario>* h = m.getHorarios().getCabeza(); h != nullptr; h = h->getSiguiente()){
            total++;
        }
        archivo << m.getNrc() << ";" << m.getNombre() << ";" << total;
        for (Nodo<Horario>* h = m.getHorarios().getCabeza(); h != nullptr; h = h->getSiguiente()){
            Horario& ho = h->getDato();
            archivo << ";" << ho.getId_Horario() << "," << horaATexto(ho.getHora_Inicio()) << ","
                    << horaATexto(ho.getHora_Fin()) << "," << ho.getDia();
        }
        archivo << endl;
        cantidad++;
    }
    archivo.close();
    cout << "Materias guardadas: " << cantidad << endl;
}

void cargarMaterias(Lista_Doble<Materia>& materias){
    ifstream archivo(ARCHIVO_MATERIAS);
    if (!archivo.is_open()){
        cout << "No existe " << ARCHIVO_MATERIAS << " (se empieza con la lista vacia)" << endl;
        return;
    }

    materias = Lista_Doble<Materia>();   // vacia la lista para no duplicar datos

    string linea;
    int cantidad = 0;
    while (getline(archivo, linea)){
        if (linea.empty()) continue;

        stringstream ss(linea);
        string nrcTxt, nombre, totalTxt;
        getline(ss, nrcTxt, ';');
        getline(ss, nombre, ';');
        getline(ss, totalTxt, ';');

        int nrc, total;
        if (!aEntero(nrcTxt, nrc) || !aEntero(totalTxt, total) || nombre.empty()){
            cout << "Linea invalida en " << ARCHIVO_MATERIAS << " (se ignora)" << endl;
            continue;
        }

        Materia materia(nrc, nombre);
        for (int i = 0; i < total; i++){
            string bloque;
            if (!getline(ss, bloque, ';')) break;

            stringstream sh(bloque);
            string idTxt, iniTxt, finTxt, dia;
            getline(sh, idTxt, ',');
            getline(sh, iniTxt, ',');
            getline(sh, finTxt, ',');
            getline(sh, dia, ',');

            int id, ini, fin;
            if (aEntero(idTxt, id) && textoAHora(iniTxt, ini) && textoAHora(finTxt, fin)){
                materia.agregarHorario(Horario(id, ini, fin, dia));
            }
        }
        materias.insertarFinal(materia);
        cantidad++;
    }
    archivo.close();
    cout << "Materias cargadas: " << cantidad << endl;
}

// ============================================================
//  PROFESORES  (de cada materia solo se guarda el NRC)
// ============================================================
void guardarProfesores(Lista_Doble<Profesor>& profesores){
    ofstream archivo(ARCHIVO_PROFESORES);
    if (!archivo.is_open()){
        cout << "No se pudo crear " << ARCHIVO_PROFESORES << endl;
        return;
    }

    int cantidad = 0;
    for (Nodo<Profesor>* nodo = profesores.getCabeza(); nodo != nullptr; nodo = nodo->getSiguiente()){
        Profesor& p = nodo->getDato();
        archivo << p.getCedula() << ";" << p.getNombre() << ";" << p.getApellido() << ";";

        bool primera = true;
        for (Nodo<Materia>* m = p.getMaterias().getCabeza(); m != nullptr; m = m->getSiguiente()){
            if (!primera) archivo << ",";
            archivo << m->getDato().getNrc();
            primera = false;
        }
        archivo << endl;
        cantidad++;
    }
    archivo.close();
    cout << "Profesores guardados: " << cantidad << endl;
}

void cargarProfesores(Lista_Doble<Profesor>& profesores, Lista_Doble<Materia>& materias){
    ifstream archivo(ARCHIVO_PROFESORES);
    if (!archivo.is_open()){
        cout << "No existe " << ARCHIVO_PROFESORES << " (se empieza con la lista vacia)" << endl;
        return;
    }

    profesores = Lista_Doble<Profesor>();

    string linea;
    int cantidad = 0;
    while (getline(archivo, linea)){
        if (linea.empty()) continue;

        stringstream ss(linea);
        string cedula, nombre, apellido, nrcs;
        getline(ss, cedula, ';');
        getline(ss, nombre, ';');
        getline(ss, apellido, ';');
        getline(ss, nrcs, ';');

        if (!validarCedula(cedula) || !soloLetras(nombre) || !soloLetras(apellido)){
            cout << "Linea invalida en " << ARCHIVO_PROFESORES << " (se ignora)" << endl;
            continue;
        }

        Profesor profesor(cedula, nombre, apellido);

        // buscar cada NRC en la lista de materias y agregarla al profesor
        stringstream sn(nrcs);
        string nrcTxt;
        while (getline(sn, nrcTxt, ',')){
            int nrc;
            if (!aEntero(nrcTxt, nrc)) continue;
            Nodo<Materia>* encontrada = materias.buscar(Materia(nrc, ""));
            if (encontrada != nullptr){
                profesor.getMaterias().insertarFinal(encontrada->getDato());
            }
        }
        profesores.insertarFinal(profesor);
        cantidad++;
    }
    archivo.close();
    cout << "Profesores cargados: " << cantidad << endl;
}

// ============================================================
//  REGISTROS
// ============================================================
void guardarRegistros(Lista_Doble<Registro>& registros){
    ofstream archivo(ARCHIVO_REGISTROS);
    if (!archivo.is_open()){
        cout << "No se pudo crear " << ARCHIVO_REGISTROS << endl;
        return;
    }

    int cantidad = 0;
    for (Nodo<Registro>* nodo = registros.getCabeza(); nodo != nullptr; nodo = nodo->getSiguiente()){
        Registro& r = nodo->getDato();
        archivo << r.getCedula() << ";" << r.getNrc() << ";" << r.getId_Horario() << ";"
                << r.getFecha() << ";" << r.getHora_Entrada() << ";" << r.getHora_Salida() << endl;
        cantidad++;
    }
    archivo.close();
    cout << "Registros guardados: " << cantidad << endl;
}

void cargarRegistros(Lista_Doble<Registro>& registros){
    ifstream archivo(ARCHIVO_REGISTROS);
    if (!archivo.is_open()){
        cout << "No existe " << ARCHIVO_REGISTROS << " (se empieza con la lista vacia)" << endl;
        return;
    }

    registros = Lista_Doble<Registro>();

    string linea;
    int cantidad = 0;
    while (getline(archivo, linea)){
        if (linea.empty()) continue;

        stringstream ss(linea);
        string cedula, nrcTxt, idTxt, fecha, entradaTxt, salidaTxt;
        getline(ss, cedula, ';');
        getline(ss, nrcTxt, ';');
        getline(ss, idTxt, ';');
        getline(ss, fecha, ';');
        getline(ss, entradaTxt, ';');
        getline(ss, salidaTxt, ';');

        int nrc, id, entrada, salida;
        if (!validarCedula(cedula) || !aEntero(nrcTxt, nrc) || !aEntero(idTxt, id) ||
            !aEntero(entradaTxt, entrada) || !aEntero(salidaTxt, salida)){
            cout << "Linea invalida en " << ARCHIVO_REGISTROS << " (se ignora)" << endl;
            continue;
        }

        Registro registro(cedula, nrc, id, fecha);
        registro.setHora_Entrada(entrada);
        registro.setHora_Salida(salida);
        registros.insertarFinal(registro);
        cantidad++;
    }
    archivo.close();
    cout << "Registros cargados: " << cantidad << endl;
}


void guardarTodo(Lista_Doble<Materia>& materias, Lista_Doble<Profesor>& profesores,
                 Lista_Doble<Registro>& registros){
    guardarMaterias(materias);
    guardarProfesores(profesores);
    guardarRegistros(registros);
}

void cargarTodo(Lista_Doble<Materia>& materias, Lista_Doble<Profesor>& profesores,
                Lista_Doble<Registro>& registros){
    cargarMaterias(materias);                // primero las materias
    cargarProfesores(profesores, materias);  // luego los profesores (usan los NRC)
    cargarRegistros(registros);
}