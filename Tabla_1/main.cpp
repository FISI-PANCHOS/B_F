#include <iostream>
#include <math.h>
#include <string>
#include <vector>
#include <stdio.h>
#include <string.h>
#include <sstream>
#include <list>
#include "Tabla.h"
#include "QuineMcClusky.h"


int main(int argc, char** argv) {
	std::string ecuacion= "(XvY)v(X^W)";
	printf("Aqui empieza ");
	Tabla tab(ecuacion);
	QuineMcClusky reduccion(ecuacion);
	reduccion.funcion_reducida(ecuacion);
		
		
	return 0;
}
