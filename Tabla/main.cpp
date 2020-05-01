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

//Esto es lo que voy trabajando hasta aghora en el main, no va a compilar, aun tengo que arreglar una cosita xdd
int main(int argc, char** argv) {
	string ecuacion;
	char n='n';
	printf("inserta tu frase plox: ");
    getline(cin,ecuacion);
	Tabla tab(ecuacion,n);
	QuineMcClusky reduccion(ecuacion,n);
		

	return 0;
}
