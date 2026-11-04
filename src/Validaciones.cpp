#include "Validaciones.h"
#include <iostream>
#include <cctype>
#include <cstdlib>

using namespace std;

// solo digitos 
bool soloNumeros(string texto) {
    if (texto.empty()) return false;
    for (size_t i = 0; i < texto.size(); i++) {
        if (!isdigit((unsigned char)texto[i])) return false;
    }
    return true;
}

//solo letras con espacios 
bool soloLetras(string texto) {
    bool hayLetra = false;
    for (size_t i = 0; i < texto.size(); i++) {
        unsigned char c = texto[i];
        if (isalpha(c)) {
            hayLetra = true;
        } else if (c != ' ') {
            return false;   // un numero o simbolo
        }
    }
    return hayLetra;        // evita que sea solo espacios o vacio
}


bool validarCedula(string cedula) {
    if (cedula.size() != 10 || !soloNumeros(cedula)) return false;

    int provincia = (cedula[0] - '0') * 10 + (cedula[1] - '0');
    if (provincia < 1 || provincia > 24) return false;

    if (cedula[2] - '0' >= 6) return false;

    int suma = 0;
    for (int i = 0; i < 9; i++) {
        int digito = cedula[i] - '0';
        int multiplicador = (i % 2 == 0) ? 2 : 1;   // posiciones 1,3,5,7,9 x2
        int producto = digito * multiplicador;
        if (producto > 9) producto -= 9;
        suma += producto;
    }

    int verificador = (10 - (suma % 10)) % 10;
    return verificador == (cedula[9] - '0');
}

//lectura de datos hasta que este correcto
int leerEntero(string mensaje) {
    string entrada;
    while (true) {
        cout << mensaje;
        if (!getline(cin, entrada)){
    cin.clear();
    cout << "\n  Error: entrada no valida.\n";
    continue;
}
        // maximo 9 digitos para que el numero quepa en un int
        if (soloNumeros(entrada) && entrada.size() <= 9) {
            return atoi(entrada.c_str());
        }
        cout << "  Error: ingrese solo numeros (sin letras ni simbolos).\n";
    }
}

int leerEnteroRango(string mensaje, int min, int max) {
    while (true) {
        int n = leerEntero(mensaje);
        if (n >= min && n <= max) return n;
        cout << "  Error: el numero debe estar entre " << min << " y " << max << ".\n";
    }
}

string leerTexto(string mensaje) {
    string entrada;
    while (true) {
        cout << mensaje;
        if (!getline(cin, entrada)){
        cin.clear();
        cout << "\n  Error: entrada no valida.\n";
        continue;
}
        // no vacio y no solo espacios
        bool hayAlgo = false;
        for (size_t i = 0; i < entrada.size(); i++) {
            if (entrada[i] != ' ') hayAlgo = true;
        }
        if (hayAlgo) return entrada;
        cout << "  Error: el texto no puede estar vacio.\n";
    }
}

string leerSoloLetras(string mensaje) {
    string entrada;
    while (true) {
        cout << mensaje;
        if (!getline(cin, entrada)){
        cin.clear();
        cout << "\n  Error: entrada no valida.\n";
        continue;
}
        if (soloLetras(entrada)) return entrada;
        cout << "  Error: solo se permiten letras (sin numeros ni simbolos).\n";
    }
}

string leerCedula() {
    string entrada;
    while (true) {
        cout << "Cedula (10 digitos): ";
        if (!getline(cin, entrada)){
        cin.clear();
        cout << "\n  Error: entrada no valida.\n";
        continue;
}
        if (validarCedula(entrada)) return entrada;
        cout << "  Error: cedula ecuatoriana no valida.\n";
    }
}

int leerNRC() {
    string entrada;
    while (true) {
        cout << "NRC (3 a 5 digitos): ";
        if (!getline(cin, entrada)){
            cin.clear();
            cout << "\n  Error: entrada no valida.\n";
            continue;
        }
        if (entrada.size() >= 3 && entrada.size() <= 5 && soloNumeros(entrada)) return atoi(entrada.c_str());
        cout << "  Error: el NRC debe tener entre 3 y 5 numeros.\n";
    }
}

string formatoNombre(string texto){
    bool inicioPalabra = true;
    for (size_t i = 0; i < texto.size(); i++){
        if (texto[i] == ' '){
            inicioPalabra = true;
        }else if (inicioPalabra){
            if (texto[i] >= 'a' && texto[i] <= 'z'){
                texto[i] = texto[i] - 32;
            }
            inicioPalabra = false;
        }else{
            if (texto[i] >= 'A' && texto[i] <= 'Z'){
                texto[i] = texto[i] + 32;
            }
        }
    }
    return texto;
}

string leerSoloLetrasOpcional(string mensaje) {
    string entrada;
    while (true) {
        cout << mensaje;
        if (!getline(cin, entrada)){
            cin.clear();
            cout << "\n  Error: entrada no valida.\n";
            continue;
        }
        bool vacio = true;
        for (size_t i = 0; i < entrada.size(); i++){
            if (entrada[i] != ' ') vacio = false;
        }
        if (vacio) return "";
        if (soloLetras(entrada)) return entrada;
        cout << "  Error: solo se permiten letras (sin numeros ni simbolos).\n";
    }
}