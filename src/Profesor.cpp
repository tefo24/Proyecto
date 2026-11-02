/***********************************************************************
 * Module:  Profesor.cpp
 * Author:  RIZEN 7
 * Modified: sábado, 31 de octubre de 2026 14:30:00
 * Purpose: Implementation of the class Profesor
 ***********************************************************************/

#include "Materia.h"
#include "Profesor.h"

////////////////////////////////////////////////////////////////////////
// Name:       Profesor::getMaterias()
// Purpose:    Implementation of Profesor::getMaterias()
// Return:     Lista_Doble<Materia>&
////////////////////////////////////////////////////////////////////////

Lista_Doble<Materia>& Profesor::getMaterias(void)
{
   return materias;
}

////////////////////////////////////////////////////////////////////////
// Name:       Profesor::Profesor()
// Purpose:    Implementation of Profesor::Profesor()
// Return:     
////////////////////////////////////////////////////////////////////////

Profesor::Profesor()
{
   materia = NULL;
}

////////////////////////////////////////////////////////////////////////
// Name:       Profesor::~Profesor()
// Purpose:    Implementation of Profesor::~Profesor()
// Return:     
////////////////////////////////////////////////////////////////////////

Profesor::~Profesor()
{
   // TODO : implement
}

////////////////////////////////////////////////////////////////////////
// Name:       Profesor::Profesor(std::string cedula, std::string nombre, std::string apellido)
// Purpose:    Implementation of Profesor::Profesor()
// Parameters:
// - cedula
// - nombre
// - apellido
// Return:     
////////////////////////////////////////////////////////////////////////

Profesor::Profesor(std::string cedula, std::string nombre, std::string apellido)
{
   // TODO : implement
}

////////////////////////////////////////////////////////////////////////
// Name:       Profesor::operator==(Profesor otro)
// Purpose:    Implementation of Profesor::operator==()
// Parameters:
// - otro
// Return:     bool
////////////////////////////////////////////////////////////////////////

bool Profesor::operator==(Profesor otro)
{
   // TODO : implement
}

////////////////////////////////////////////////////////////////////////
// Name:       Profesor::imprimir()
// Purpose:    Implementation of Profesor::imprimir()
// Return:     void
////////////////////////////////////////////////////////////////////////

void Profesor::imprimir(void)
{
   // TODO : implement
}