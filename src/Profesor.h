/***********************************************************************
 * Module:  Profesor.h
 * Author:  RIZEN 7
 * Modified: s�bado, 31 de octubre de 2026 14:30:00
 * Purpose: Declaration of the class Profesor
 ***********************************************************************/

#if !defined(__Horario_Registro_Materia_Profesor_h)
#define __Horario_Registro_Materia_Profesor_h

//class Materia;

#include "Persona.h" 
#include <string>
#include "Materia.h"
//#include "Lista_Doble.h"

class Profesor : public Persona
{
public:
   Lista_Doble<Materia>& getMaterias(void);
   Profesor();
   ~Profesor();
   Profesor(std::string cedula, std::string nombre, std::string apellido);
   bool operator==(Profesor otro);
   void imprimir(void);

   //Materia** materia;

protected:
private:
   Lista_Doble<Materia> materias;


};

#endif