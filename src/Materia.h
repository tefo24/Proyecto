/***********************************************************************
 * Module:  Materia.h
 * Author:  RIZEN 7
 * Modified: lunes, 2 de noviembre de 2026 14:04:02
 * Purpose: Declaration of the class Materia
 ***********************************************************************/

#if !defined(__Horario_Registro_Materia_Materia_h)
#define __Horario_Registro_Materia_Materia_h

#include "Horario.h"
#include <string>
#include "Lista_Doble.h"

class Materia
{
public:
   int getNrc(void);
   void setNrc(int newNrc);
   std::string getNombre(void);
   void setNombre(std::string newNombre);
   Lista_Doble<Horario>& getHorarios(void);
   void agregarHorario(Horario horario);
   Materia();
   ~Materia();
   Materia(int nrc, std::string nombre);
   bool operator==(Materia otro);
   void imprimir(void);


protected:
private:
   int nrc;
   std::string nombre;
   Lista_Doble<Horario> horarios;


};

#endif