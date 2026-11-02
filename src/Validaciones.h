#ifndef VALIDACIONES_H
#define VALIDACIONES_H

#include <string>

//comprobacion TRUE O FLASE 
bool soloNumeros(std::string texto);     // solo digitos 0-9 (no vacio)
bool soloLetras(std::string texto);      // solo letras y espacios (al menos una letra)
bool validarCedula(std::string cedula);  // cedula ecuatoriana completa

//Funcion bucle de repetcion hasta que este correcro
int         leerEntero(std::string mensaje);                          // solo numeros
int         leerEnteroRango(std::string mensaje, int min, int max);   // numero entre min y max
std::string leerTexto(std::string mensaje);                           // texto no vacio
std::string leerSoloLetras(std::string mensaje);                      // solo letras y espacios
std::string leerCedula();                                             // pide cedula valida
int         leerNRC();                                                // pide NRC de 5 digitos

#endif