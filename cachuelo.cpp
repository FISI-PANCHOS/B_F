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
	string string1,string2,caracter;
	int n;
	while(termino.find("'") != string::npos){
		n=termino.find("'");
		string1=termino.substr(0,n-1);
		caracter=negacion(termino.at(n-1));
		string2=termino.substr(n+1,termino.length()-n);
		string1=string1+caracter;
		termino=string1+string2;
		termino=aplicarnegacion(termino);
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
		string1=termino.substr(0,(termino.length()-n-2));
		caracter=productoAND(termino.at(n-1),termino.at(n+1));
		string1=string1+caracter;
			termino=string1;
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
	int a=0,n,cont=0;
	string lista="XYZW";
	string string1,caracter;
	if(termino.length()>1){
		for(int a=0;a<4;a++){
			cont=0;
    for(int i=0;i<termino.length();i++){
    	
    	if(termino.at(i)==lista.at(a) and termino.at(i)!='^' and termino.at(i)!='v' ){	
    		cont++;
    		if(cont>1){
    			if(termino.find("'") != string::npos){
				n=termino.find("'");
				if(termino.at(i)==termino.at(i+2) and termino.at(i)!='^' and termino.at(i)!='v' and (termino.at(i)==termino.at(n-1) or termino.at(i+2)==termino.at(n-1) )){
				string1=termino.substr(0,(termino.length()-(termino.length()-i)));
				if(termino.at(i+1)=='^'){
					caracter='0';
				}
				else{
					caracter='1';
				}
				
				if(i+4!=termino.length()){
    			termino=string1+caracter+termino.substr(i+4,termino.length());
				}
				else{
				termino=string1+caracter;
				}	

				}
				}
				if(termino.length()>2){
    			if(termino.at(i-2)==termino.at(i) and termino.at(i)!='^' and termino.at(i)!='v'){
    			string1=termino.substr(0,(termino.length()-(termino.length()-(i-2)))); 
    			caracter=termino.substr(i,1);
    				if(i+1!=termino.length()){
    				termino=string1+caracter+termino.substr(i+1,termino.length());
					}
					else{
					termino=string1+caracter;
					}
				}
				}
				if(termino.length()>3){
				if(termino.at(i-2)==termino.at(i) and termino.at(i)!='^' and termino.at(i)!='v'){
    				string1=termino.substr(0,(termino.length()-(termino.length()-(i-2))));
    				caracter=termino.substr(i,1);
    				if(i+1!=termino.length()){
    				termino=string1+caracter+termino.substr(i+1,termino.length());
					}
					else{
					termino=string1+caracter;
					}
				}
				}
				termino=reduccion(termino);
			}
		}
	}
	}
	}

	return termino;
}
string operar(string termino, int numvar,int y){
	termino=reduccion(termino);
	termino=binarizacion(termino,numvar,y);
	termino=aplicarnegacion(termino);
	termino=prioridadAND(termino);
	termino=resolverOR(termino);
	return termino;
	}
string separarterminos(string funcion, int y){
	int posicion1=0,posicion2=0;
	int n,cont=0;
	int contando=0;
	int diferencia=0;
	string string1,string2,termino;
	n=numvariables(funcion);
	while(funcion.find('(') != string::npos and funcion.find(')') != string::npos){contando++;cout<<"Es la vez numero "<<contando<<" que se ejecuta"<<endl;
		cout<<"El caracter es "<<funcion.at(cont)<<endl;
		if(funcion.at(cont)=='('){
    		posicion1=cont;
		}
		if(funcion.at(cont)==')'){
    		posicion2=cont;
				diferencia=(posicion2-posicion1);
				string1=funcion.substr(0, posicion1);
				termino=funcion.substr(posicion1+1, diferencia-1);
				funcion=funcion.substr(posicion2+1, funcion.length());
				string2=operar(termino,n,y);
				funcion=string1+string2+funcion;
				posicion2=0;
				cont=0;
    			cout<<"Terminaste el termino y la funcion es "<<funcion<<endl;
    			funcion=separarterminos(funcion,y);
		}
		else{cont++;
		}
		

	}

	
return operar(funcion,n,y);
}
void llenarmatrices(string ecuacion){
	int cont=0,i=0;
	int variables,restante=1;
	string matriz[16][5];
	string respuestas[16];
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
	for(int z=0;z<pow(2,variables);z++){
		respuestas[z]=matriz[z][variables]; //German ctmre 
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
