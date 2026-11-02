/***********************************************************************
 * Module:  Horario.h
 * Author:  RIZEN 7
 * Modified: lunes, 2 de noviembre de 2026 13:57:50
 * Purpose: Declaration of the class Horario
 ***********************************************************************/

#if !defined(__Horario_Registro_Materia_Horario_h)
#define __Horario_Registro_Materia_Horario_h
#include <string>

class Horario
{
public:
   int getId_Horario(void);
   void setId_Horario(int newId_Horario);
   int getHora_Inicio(void);
   void setHora_Inicio(int newHora_Inicio);
   int getHora_Fin(void);
   void setHora_Fin(int newHora_Fin);
   std::string getDia(void);
   void setDia(std::string newDia);
   Horario();
   ~Horario();
   Horario(int id_Horario, int hora_Inicio, int hora_Fin, std::string dia);
   bool operator==(Horario otro);
   void imprimir(void);

protected:
private:
   int id_Horario;
   int hora_Inicio;
   int hora_Fin;
   std::string dia;


};

#endif