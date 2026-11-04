/***********************************************************************
 * Module:  Persona.cpp
 * Author:  RIZEN 7
 * Modified: s�bado, 31 de octubre de 2026 14:30:00
 * Purpose: Implementation of the class Persona
 ***********************************************************************/

#include "Persona.h"
#include <iostream>

using namespace std;

// Constructor vacio
Persona::Persona() {
    this->cedula = "";
    this->nombre = "";
    this->apellido = "";
    this->correo = "";   
}

// Constructor con parametros (se llaman igual que los atributos, por eso se usa this->)
Persona::Persona(string cedula, string nombre, string apellido) {
    this->cedula = cedula;
    this->nombre = nombre;
    this->apellido = apellido;
    this->correo = "";       
}

Persona::~Persona() {
}

// ---------- Getters y setters ----------
string Persona::getCedula() {
    return this->cedula;
}

void Persona::setCedula(string cedula) {
    this->cedula = cedula;
}

string Persona::getNombre() {
    return this->nombre;
}

void Persona::setNombre(string nombre) {
    this->nombre = nombre;
}

string Persona::getApellido() {
    return this->apellido;
}

void Persona::setApellido(string apellido) {
    this->apellido = apellido;
}

string Persona::getCorreo() {
    return this->correo;
}

void Persona::setCorreo(string correo) {
    this->correo = correo;
}

// ---------- Imprimir ----------
void Persona::imprimirDatosPersonales() {
    cout << "   Cedula  : " << this->cedula << endl;
    cout << "   Nombre  : " << this->nombre << endl;
    cout << "   Apellido: " << this->apellido << endl;
    cout << "   Correo  : " << this->correo << endl;
}