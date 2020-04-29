
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
char valoresdeverdad(int cont,int variables,int restante,int x,int y){
	int i=0;
	char matriz[16][5];
	int a=0;
	int t,w=0;
	if(restante>0){
		t=pow(2,cont);
			for(int s=0;s<t;s++){
			restante=(variables-cont);
			w=pow(2,restante);		
			while(a!=w){
				while(a<(w/2)){
				matriz[i][x]='0';
				a++;
				i++;
			}
			while(a>=(w/2)and a<w){
				matriz[i][x]='1';
				a++;
				i++;
				}
			}
			a=0;
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
			termino.at(i)=valoresdeverdad(cont,numvariables,restantes,x,y);
			restantes--;
			cont++;
		}
		if(termino.at(i)=='Y'){
			termino.at(i)=valoresdeverdad(cont,numvariables,restantes,Y,y);
			restantes--;
			cont++;
		}
		if(termino.at(i)=='Z'){
			termino.at(i)=valoresdeverdad(cont,numvariables,restantes,z,y);
			restantes--;
			cont++;
		}
		if(termino.at(i)=='W'){
			termino.at(i)=valoresdeverdad(cont,numvariables,restantes,w,y);
			restantes--;
			cont++;
		}
	}
	return termino;
}
string prioridadAND(string termino){
	string string1,string2,string3;
	string caracter;
	int n;
	while(termino.find("^") != string::npos){
		n=termino.find("^");
		string1=termino.substr(0,(termino.length()-n));
		caracter=productoAND(termino.at(n-1),termino.at(n+1));
		string1=string1+caracter;
		if(n+2!=termino.length()){
		termino=string1+termino.substr(n+2,termino.length());
		}
		else{
			termino=string1;
		}
		termino=prioridadAND(termino);
	}
	return termino;
}
string resolverOR(string termino){
	string caracter;
	int n;
	while(termino.find("v") != string::npos){
		n=termino.find("v");
		caracter=sumaOR(termino.at(n-1),termino.at(n+1));
		if(n+2!=termino.length()){
		termino=caracter+termino.substr(n+2,termino.length());
		}
		else{
			termino=caracter;
		}
		termino=resolverOR(termino);
	}
	return termino;
}
string reduccion(string termino){
	string string1,caracter;
    for(int i=0;i<termino.length();i++){
    	if(termino.at(i)==termino.at(i+2) and termino.at(i)!='^' and termino.at(i)!='v'){
    		string1=termino.substr(0,termino.length()-n);
    		caracter=termino.substr(n+2,1);
    		termino=string1+caracter+termino.substr(n+5,termino.length());
		}
	}
	return termino;
}

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
	int cont=0,i=0;
	int variables,restante=1;
	string matriz[16][5];
	int a=0;
	int t,w=0;
	variables=numvariables(ecuacion);

	for(int j=0;j<variables;j++){
		if(restante>0){
		t=pow(2,cont);
			for(int s=0;s<t;s++){
			restante=(variables-cont);
			w=pow(2,restante);
			while(a!=w){
				while(a<(w/2)){
				matriz[i][j]="0";
				a++;
				i++;
			}
			while(a>=(w/2)and a<w){
				matriz[i][j]="1";
				a++;
				i++;
				}
			}
			a=0;
		}
		}
			i=0;
		cont++;
	}
	for(int cont2=0;cont2<pow(2,variables);cont2++){
		matriz[cont2][variables]=separarterminos(ecuacion,cont2);
	}

	for(int e=0;e<pow(2,variables);e++){
		for(int b=0;b<variables+1;b++){
			cout<<matriz[e][b];
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
