
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
	if((a == b) && (a == '0')){
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
char valoresdeverdad(int cont,int restantes,int x,int y){
	char matriz[16][4];
	for(int s=0;s<pow(2,cont);s++){

		for(int i=0;i<pow(2,restantes);i++){ 
			if(i<pow(2,restantes)/2){
				matriz[i][x]='0';
			}
			else{
				matriz[i][x]='1';
			}
		}
	}
	return matriz[y][x];
}
string binarizacion(string termino,int numvariables, int y){
	int cont=0,restantes;
	int x=0,Y=1,z=2,w=3;
	restantes=numvariables;
	for(int i=0;i<termino.length();i++){
		if(termino.at(i)=='X'){
			termino.at(i)=valoresdeverdad(cont,restantes,x,y);
			numvariables--;
			cont++;
		}
		if(termino.at(i)=='Y'){
			termino.at(i)=valoresdeverdad(cont,restantes,Y,y);
			numvariables--;
			cont++;
		}
		if(termino.at(i)=='Z'){
			termino.at(i)=valoresdeverdad(cont,restantes,z,y);
			numvariables--;
			cont++;
		}
		if(termino.at(i)=='W'){
			termino.at(i)=valoresdeverdad(cont,restantes,w,y);
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
		caracter=sumaOR(termino.at(n-1),termino.at(n+1));
		if(n+2!=termino.length()){
		termino=caracter+termino.substr(n+2,termino.length());
			
		termino=string1+string2;
		}
		else{
			termino=caracter;
		}
		
		
	}
	return termino;
}
/*string reduccion(string termino){
	
}*/
string operar(string termino, int numvar,int y){
	
	//termino=reduccion(termino);

	termino=binarizacion(termino,numvar,y);
	termino=aplicarnegacion(termino);
	termino=prioridadAND(termino);
	termino=resolverOR(termino);
	
	return termino;
	}
string separarterminos(string funcion, int y){
	int s,posicion1=0,posicion2=0,cont=0;
	int n;
	int diferencia=0;
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
			diferencia=(posicion2-posicion1);
			termino=funcion.substr(posicion1+1, diferencia-1);
			funcion=funcion.substr(posicion2+1, funcion.length());
			string1=operar(termino,n,y);
			funcion=string1+funcion;
			posicion2=0;
		}
	}

	
	return operar(funcion,n,y);
}
void llenarmatrices(string ecuacion){
	int n;
	n=numvariables(ecuacion);
	string matriz[16][5];
	for(int cont=0;cont<n;cont++){
		for(int s=0;s<pow(2,cont);s++){
			for(int j=0;j<n;j++){
				for(int i=0;i<pow(2,n-cont);i++){ 
				if(i<pow(2,n-cont)/2){
				matriz[i][j]='0';
			}
				else{
				matriz[i][j]='1';
			}
	}
	}
	}
	
	}
	for(int cont2=0;cont2<pow(2,n);cont2++){
		matriz[cont2][n]=separarterminos(ecuacion,cont2);
	}

	for(int a=0;a<pow(2,n);a++){
		for(int b=0;b<n+1;b++){
			cout<<matriz[a][b];
		}
		cout<<endl;
	}
}
void leerfuncion(){
	int y=0,n=0;
	string ecuacion;
	string respuesta;
	printf("inserta tu frase plox: ");
    getline(cin,ecuacion);
	llenarmatrices(ecuacion);
}
int main(){
	leerfuncion();
	return 0;
}
