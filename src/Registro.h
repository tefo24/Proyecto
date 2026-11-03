/***********************************************************************
 * Module:  Registro.h
 * Author:  RIZEN 7
 * Modified: lunes, 2 de noviembre de 2026 13:58:18
 * Purpose: Declaration of the class Registro
 ***********************************************************************/

#if !defined(__Horario_Registro_Materia_Registro_h)
#define __Horario_Registro_Materia_Registro_h
#include <string>

class Registro
{
public:
   std::string getCedula(void);
   void setCedula(std::string newCedula);
   int getNrc(void);
   void setNrc(int newNrc);
   int getId_Horario(void);
   void setId_Horario(int newId_Horario);
   std::string getFecha(void);
   void setFecha(std::string newFecha);
   int getHora_Entrada(void);
   void setHora_Entrada(int newHora_Entrada);
   int getHora_Salida(void);
   void setHora_Salida(int newHora_Salida);
   Registro();
   ~Registro();
   Registro(std::string cedula, int nrc, int id_Horario, std::string fecha);
   bool operator==(const Registro& otro) const;
   void imprimir(void);
   bool registrarEntrada(int hora_Actual);
   bool registrarSalida(int hora_Actual);

protected:
private:
   std::string cedula;
   int nrc;
   int id_Horario;
   std::string fecha;
   int hora_Entrada;
   int hora_Salida;


};

#endif