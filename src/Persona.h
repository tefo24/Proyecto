/***********************************************************************
 * Module:  Persona.h
 * Author:  RIZEN 7
 * Modified: s�bado, 31 de octubre de 2026 14:30:00
 * Purpose: Declaration of the class Persona
 ***********************************************************************/
#if !defined(__Horario_Registro_Materia_Persona_h)
#define __Horario_Registro_Materia_Persona_h
#include <string>


class Persona
{
public:
   std::string getCedula(void);
   void setCedula(std::string newCedula);
   std::string getNombre(void);
   void setNombre(std::string newNombre);
   std::string getApellido(void);
   void setApellido(std::string newApellido);
   Persona();
   virtual ~Persona();
   Persona(std::string cedula, std::string nombre, std::string apellido);
   void imprimirDatosPersonales(void);

protected:
   std::string cedula;
   std::string nombre;
   std::string apellido;

private:

};

#endif