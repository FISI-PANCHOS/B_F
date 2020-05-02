#ifndef TABLA_H
#define TABLA_H
#include <iostream>
#include <math.h>
#include <string>
#include <vector>
#include <string.h>
#include <list>

class Tabla
{
	public:
		Tabla(std::string ecuacion);
		std::string productoAND(char a, char b);
		std::string sumaOR(char a, char b);
		std::string negacion(char n);
		std::string aplicarnegacion(std::string termino);
		int numvariables(std::string funcion);
		char valoresdeverdad(int cont,int restante,int x,int y);
		int contadordeuso(char a,int y);
		std::string binarizacion(std::string termino,int &cont,int &restantes, int y);
		std::string prioridadAND(std::string termino);
		std::string resolverOR(std::string termino);
		std::string reduccion(std::string termino);
		std::string operar(int &cont,std::string termino, int numvar,int &restantes, int y);
		std::string separarterminos(int &cont1,std::string funcion, int y);
		std::vector<std::string> llenarmatrices(std::string ecuacion);

		~Tabla();
	protected:
};

#endif
