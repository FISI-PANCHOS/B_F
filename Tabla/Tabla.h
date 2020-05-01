#ifndef TABLA_H
#define TABLA_H
#include <iostream>
#include <math.h>
#include <string>
#include <vector>
#include <string.h>
#include <list>
using namespace std;
class Tabla
{
	public:
		Tabla(string ecuacion,char n);
		string productoAND(char a, char b);
		string sumaOR(char a, char b);
		string negacion(char n);
		string aplicarnegacion(string termino);
		int numvariables(string funcion);
		char valoresdeverdad(int cont,int restante,int x,int y);
		string binarizacion(string termino,int &cont,int &restantes, int y);
		string prioridadAND(string termino);
		string resolverOR(string termino);
		string reduccion(string termino);
		string operar(int &cont,string termino, int numvar,int &restantes, int y);
		string separarterminos(int &cont1, string funcion, int y);
		void llenarmatrices(string ecuacion, char n);
		void leerfuncion();
		~Tabla();
	protected:
};

#endif
