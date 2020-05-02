#ifndef QUINEMCCLUSKY_H
#define QUINEMCCLUSKY_H
#include "Tabla.h"
#include <string.h>
#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <iterator>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <math.h>
#include <string>


class QuineMcClusky
{	int VARIABLES;
		std::string dontcares;
	public:
		
		QuineMcClusky(std::string funcion);
		std::string funcion_reducida(std::string funcion);
		int numvariables(std::string funcion);
		std::vector<std::string> obtener_variables(std::string ecuacion);
		std::string decimal_a_binario(int n);
		std::string pad(std::string bin);
		bool isGreyCode(std::string a,std::string b);
		std::string remplazar_complementos(std::string a,std::string b);
		bool in_vector(std::vector<std::string> a,std::string b);
		std::vector<std::string> reducir(std::vector<std::string> minterms);
		std::string obternervalor(std::string a,std::string ecuacion);
		std::string formato(std::vector<std::string> miniterminos, std::string funcion);
		bool VectorsEqual(std::vector<std::string> a,std::vector<std::string> b);
	protected:
};

#endif
