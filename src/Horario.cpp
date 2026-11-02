/***********************************************************************
 * Module:  Horario.cpp
 * Author:  RIZEN 7
 * Modified: lunes, 2 de noviembre de 2026 13:57:50
 * Purpose: Implementation of the class Horario
 ***********************************************************************/

#include "Horario.h"
#include <iostream>
#include <iomanip>
using namespace std;

////////////////////////////////////////////////////////////////////////
// Name:       Horario::getId_Horario()
// Purpose:    Implementation of Horario::getId_Horario()
// Return:     int
////////////////////////////////////////////////////////////////////////

int Horario::getId_Horario(void)
{
   return id_Horario;
}

////////////////////////////////////////////////////////////////////////
// Name:       Horario::setId_Horario(int newId_Horario)
// Purpose:    Implementation of Horario::setId_Horario()
// Parameters:
// - newId_Horario
// Return:     void
////////////////////////////////////////////////////////////////////////

void Horario::setId_Horario(int newId_Horario)
{
   id_Horario = newId_Horario;
}

////////////////////////////////////////////////////////////////////////
// Name:       Horario::getHora_Inicio()
// Purpose:    Implementation of Horario::getHora_Inicio()
// Return:     int
////////////////////////////////////////////////////////////////////////

int Horario::getHora_Inicio(void)
{
   return hora_Inicio;
}

////////////////////////////////////////////////////////////////////////
// Name:       Horario::setHora_Inicio(int newHora_Inicio)
// Purpose:    Implementation of Horario::setHora_Inicio()
// Parameters:
// - newHora_Inicio
// Return:     void
////////////////////////////////////////////////////////////////////////

void Horario::setHora_Inicio(int newHora_Inicio)
{
   hora_Inicio = newHora_Inicio;
}

////////////////////////////////////////////////////////////////////////
// Name:       Horario::getHora_Fin()
// Purpose:    Implementation of Horario::getHora_Fin()
// Return:     int
////////////////////////////////////////////////////////////////////////

int Horario::getHora_Fin(void)
{
   return hora_Fin;
}

////////////////////////////////////////////////////////////////////////
// Name:       Horario::setHora_Fin(int newHora_Fin)
// Purpose:    Implementation of Horario::setHora_Fin()
// Parameters:
// - newHora_Fin
// Return:     void
////////////////////////////////////////////////////////////////////////

void Horario::setHora_Fin(int newHora_Fin)
{
   hora_Fin = newHora_Fin;
}

////////////////////////////////////////////////////////////////////////
// Name:       Horario::getDia()
// Purpose:    Implementation of Horario::getDia()
// Return:     std::string
////////////////////////////////////////////////////////////////////////

std::string Horario::getDia(void)
{
   return dia;
}

////////////////////////////////////////////////////////////////////////
// Name:       Horario::setDia(std::string newDia)
// Purpose:    Implementation of Horario::setDia()
// Parameters:
// - newDia
// Return:     void
////////////////////////////////////////////////////////////////////////

void Horario::setDia(std::string newDia)
{
   dia = newDia;
}

////////////////////////////////////////////////////////////////////////
// Name:       Horario::Horario()
// Purpose:    Implementation of Horario::Horario()
// Return:     
////////////////////////////////////////////////////////////////////////

Horario::Horario(){
   id_Horario = 0;
   hora_Inicio = 0;
   hora_Fin = 0;
   dia = "";
}

////////////////////////////////////////////////////////////////////////
// Name:       Horario::~Horario()
// Purpose:    Implementation of Horario::~Horario()
// Return:     
////////////////////////////////////////////////////////////////////////

Horario::~Horario(){
}

////////////////////////////////////////////////////////////////////////
// Name:       Horario::Horario(int id_Horario, int hora_Inicio, int hora_Fin, std::string dia)
// Purpose:    Implementation of Horario::Horario()
// Parameters:
// - id_Horario
// - hora_Inicio
// - hora_Fin
// - dia
// Return:     
////////////////////////////////////////////////////////////////////////

Horario::Horario(int id_Horario, int hora_Inicio, int hora_Fin, std::string dia){
   this->id_Horario = id_Horario;
   this->hora_Inicio = hora_Inicio;
   this->hora_Fin = hora_Fin;
   this->dia = dia;
}

////////////////////////////////////////////////////////////////////////
// Name:       Horario::operator==(Horario otro)
// Purpose:    Implementation of Horario::operator==()
// Parameters:
// - otro
// Return:     bool
////////////////////////////////////////////////////////////////////////

bool Horario::operator==(Horario otro){
   return id_Horario == otro.id_Horario;
}

////////////////////////////////////////////////////////////////////////
// Name:       Horario::imprimir()
// Purpose:    Implementation of Horario::imprimir()
// Return:     void
////////////////////////////////////////////////////////////////////////

void Horario::imprimir(void){
   cout << dia << " "
        << setfill('0') << setw(2) << hora_Inicio / 60 << ":" << setw(2) << hora_Inicio % 60
        << " - "
        << setw(2) << hora_Fin / 60 << ":" << setw(2) << hora_Fin % 60
        << endl;
}