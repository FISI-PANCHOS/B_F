
#include <iostream>
#include <math.h>
#include <string>
#include <vector>
#include <string.h>
#include <list>
using namespace std;
string productoAND(char a, char b){
	if(a == b and a == '1'){
		return "1";
	}
	else{
		return "0";
	}
}
string sumaOR(char a, char b){
	if(a == b and a == '0'){
		return "0";
	}
	else{
		return "1";
	}
}
string negacion(char n){
	if(n=='1'){
		return "0";
	}
	if(n=='0'){
		return "1";
	}
	
}
string aplicarnegacion(string termino){
	string string1,string2,string3;
	int n;
	string caracter;
	while(termino.find("'") != string::npos){
		n=termino.find("'");
		string1=termino.substr(0,n-1);
		caracter=negacion(termino.at(n));
		string2=termino.substr(n+1,termino.length()-n);
		string1=string1+caracter;
		termino=string1+string2;
		}
	return termino;
}
int numvariables(string funcion){
	int numvar=0;
	if(funcion.find("X") != string::npos){
		numvar++;
	}
	if(funcion.find("Y") != string::npos){
		numvar++;
	}
	if(funcion.find("Z") != string::npos){
		numvar++;
	}
	if(funcion.find("W") != string::npos){
		numvar++;
	}
	return numvar;
}
string valoresdeverdad(int cont,int restantes,int x,int y){
	string matriz[16][4];
	for(int s=0;s<pow(2,cont);s++){

		for(int i=0;i<pow(2,restantes);i++){ 
			if(i<pow(2,restantes)/2){
				matriz[i][x]=0;
			}
			else{
				matriz[i][x]=1;
			}
		}
	}
	return matriz[y][x];
}
string binarizacion(string termino,int numvariables, int y){
	int cont=0,restantes;
	restantes=numvariables;
	for(int i=0;i<termino.length();i++){
		if(termino.at(i)=='X'){
			termino.at(i)=valoresdeverdad(cont,restantes,0,y);
			numvariables--;
			cont++;
		}
		if(termino.at(i)=='Y'){
			termino.at(i)=valoresdeverdad(cont,restantes,1,y);
			numvariables--;
			cont++;
		}
		if(termino.at(i)=='Z'){
			termino.at(i)=valoresdeverdad(cont,restantes,2,y);
			numvariables--;
			cont++;
		}
		if(termino.at(i)=='W'){
			termino.at(i)=valoresdeverdad(cont,restantes,3,y);
			numvariables--;
			cont++;
		}
	}
	return termino;
}
string prioridadAND(string termino){
	string string1,string2,string3;
	int n;
	string caracter;
	while(termino.find("^") != string::npos){
		n=termino.find("^");
		string1=termino.substr(0,n-2);
		caracter=productoAND(termino.at(n-2),termino.at(n+2));
		string2=termino.substr(n+2,termino.length());
		string1=string1+caracter;
		termino=string1+string2;
		
	}
	return termino;
}
string resolverOR(string termino){
	string string1,string2,string3;
	string caracter;
	int n;
	while(termino.find("v") != string::npos){
		n=termino.find("v");
		string1=termino.substr(0,n-2);
		caracter=sumaOR(termino.at(n-2),termino.at(n+2));
		string2=termino.substr(n+2,termino.length());
		string1=string1+caracter;
		termino=string1+string2;
		
	}
	return termino;
}
string reduccion(string termino){
	
}
string operar(string termino, int numvar,int y){
	termino=reduccion(termino);
	termino=binarizacion(termino,numvar,y);
	termino=aplicarnegacion(termino);
	termino=prioridadAND(termino);
	termino=resolverOR(termino);
	return termino;
	}
string separarterminos(string funcion){
	int s,posicion1,posicion2,cont=0;
	int n;
	string string1,string2,termino;
	n=numvariables(funcion);
	
	for(int i=0;i<funcion.length();i++){
		if(funcion[i]=='('){
    		posicion1=i;
		}
		if(funcion[i]==')'){
    		posicion2=i;
		}
		if(posicion2 != 0){
			termino=funcion.substr(posicion1, posicion2);
			funcion=funcion.substr(posicion2, funcion.length());
			string1=operar(termino,n,y);
			funcion=string1+funcion;
		}
	}

	
	return operar(funcion,n,y);
}
void leerfuncion(){
	string ecuacion;
	string respuesta;
	printf("inserta tu frase plox: ");
    getline(cin,ecuacion);
    respuesta=separarterminos(ecuacion);
    cout<<respuesta;
}
int main(){
	leerfuncion();
	return 0;
}
