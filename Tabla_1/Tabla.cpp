#include "Tabla.h"

Tabla::Tabla(std::string ecuacion)
{	
}
std::string Tabla::productoAND(char a, char b){
	if(a == b and a == '1'){
		return "1";
	}
	else{
		return "0";
	}
}
std::string Tabla::sumaOR(char a, char b){
	if((a == b) && (a == '0')){
		return "0";
	}
	else{
		return "1";
	}
}
std::string Tabla::negacion(char n){
	if(n=='1'){
		return "0";
	}
	if(n=='0'){
		return "1";
	}
}
std::string Tabla::aplicarnegacion(std::string termino){
	std::string string1,string2,caracter;
	int n;
	while(termino.find("'") != std::string::npos){
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
int Tabla::numvariables(std::string funcion){
	int numvar=0;
	if(funcion.find("X") != std::string::npos){
		numvar++;
	}
	if(funcion.find("Y") != std::string::npos){
		numvar++;
	}
	if(funcion.find("Z") != std::string::npos){
		numvar++;
	}
	if(funcion.find("W") != std::string::npos){
		numvar++;
	}
	return numvar;
}
char Tabla::valoresdeverdad(int cont,int restante,int x,int y){
	int i=0;
	char matriz[16][5];
	int a=0;
	int t,w=0;
	if(restante>0){
		t=pow(2,cont);
			for(int s=0;s<t;s++){
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
int  Tabla::contadordeuso(char a,int y){
	int cont;
	static int contX=0,contY=0,contZ=0,contW=0;
	static int b=0;
	if(b!=y){
		contX=0;
		contY=0;
		contZ=0;
		contW=0;
		b=y;
	}
	switch(a){
		case 'X':
			cont=contX;
			contX++;
		break;
		case 'Y':
			cont=contY;
			contY++;
		break;
		case 'Z':
			cont=contZ;
			contZ++;
		break;
		case 'W':
			cont=contW;
			contW++;
		break;
	}
	return cont;
}
std::string Tabla::binarizacion(std::string termino,int &cont,int &restantes, int y){
	int x=0,Y=1,z=2,w=3;
	int n;
	for(int i=0;i<termino.length();i++){
		if(termino.at(i)=='X'){
			n=contadordeuso('X',y);
			if(n>0){
				cont=cont-1;
				restantes=restantes+1;
				termino.at(i)=valoresdeverdad(cont,restantes,x,y);
				restantes--;
				cont++;
			}
			if(n==0){
				termino.at(i)=valoresdeverdad(cont,restantes,x,y);
				restantes--;
				cont++;
			}
			
		}
		if(termino.at(i)=='Y'){
			n=contadordeuso('Y',y);
			if(n>0){
				cont--; 
				restantes++;
				termino.at(i)=valoresdeverdad(cont,restantes,Y,y);
				restantes--;
				cont++;
			}
			if(n==0){
			termino.at(i)=valoresdeverdad(cont,restantes,z,y);
				restantes--; 
				cont++;
			}
		}
		if(termino.at(i)=='Z'){
			n=contadordeuso('Z',y);
			if(n>0){
				cont=cont-1;
				restantes=restantes+1;
				termino.at(i)=valoresdeverdad(cont,restantes,z,y);
				restantes--;
				cont++;
			}
			if(n==0){
			termino.at(i)=valoresdeverdad(cont,restantes,z,y);
				restantes--;
				cont++;
			}
		}
		if(termino.at(i)=='W'){
			n=contadordeuso('W',y);
			if(n>0){
				cont=cont-1;
				restantes=restantes+1;
				termino.at(i)=valoresdeverdad(cont,restantes,w,y);
				restantes--;
				cont++;
			}
			else{
				termino.at(i)=valoresdeverdad(cont,restantes,w,y);
			}
			if(n<1){
				restantes--;
				cont++;
			}
		}
	}
	return termino;
}
std::string Tabla::prioridadAND(std::string termino){
	std::string string1,string2,string3;
	std::string caracter;
	int n;
	while(termino.find("^") != std::string::npos){
		n=termino.find("^");
		string1=termino.substr(0,(termino.length()-n-2));
		caracter=productoAND(termino.at(n-1),termino.at(n+1));
		string1=string1+caracter;
			termino=string1;
		termino=prioridadAND(termino);
	}
	return termino;
}
std::string Tabla::resolverOR(std::string termino){
	std::string caracter;
	int n;
	while(termino.find("v") != std::string::npos){
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
std::string Tabla::reduccion(std::string termino){
	int a=0,n,cont=0;
	std::string lista="XYZW";
	std::string string1,caracter;
	if(termino.length()>1){
		for(int a=0;a<4;a++){
			cont=0;
    for(int i=0;i<termino.length();i++){
    	
    	if(termino.at(i)==lista.at(a)){	
    		cont++;
    		if(cont>1){
    			if(termino.find("'") != std::string::npos){
				n=termino.find("'");
				if(termino.at(i-2)==termino.at(i)){ //and //termino.at(i)==termino.at(n-1) /*or termino.at(i-2)==termino.at(n-1) */){
				string1=termino.substr(0,(termino.length()-(termino.length()-i)));
				if(termino.at(i-1)=='^'){
					caracter='0';
				}
				else{
					caracter='1';
				}
				if(i+1>=termino.length()){
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
std::string Tabla::operar(int &cont,std::string termino, int numvar,int &restantes, int y){
	termino=reduccion(termino);
	termino=binarizacion(termino,cont,restantes,y);	
	termino=aplicarnegacion(termino);
	termino=prioridadAND(termino);
	termino=resolverOR(termino);
	return termino;
	}
std::string Tabla::separarterminos(int &cont1, std::string funcion, int y){
	int posicion1=0,posicion2=0;
	int n,restante,cont=0;
	int diferencia=0;
	std::string string1,string2,termino,ecuacion;
	ecuacion=funcion;
	n=numvariables(ecuacion);
	restante=n;
	while(funcion.find('(') != std::string::npos and funcion.find(')') != std::string::npos){
		if(funcion.at(cont)=='('){
    		posicion1=cont;
		}
		if(funcion.at(cont)==')'){
    		posicion2=cont;
				diferencia=(posicion2-posicion1);
				string1=funcion.substr(0, posicion1);
				termino=funcion.substr(posicion1+1, diferencia-1);
				funcion=funcion.substr(posicion2+1, funcion.length());
				string2=operar(cont1,termino,n,restante,y);
				funcion=string1+string2+funcion;
				posicion2=0;
				cont=0;
		}
		else{cont++;
		}
		

	}
	funcion=operar(cont1,funcion,n,restante,y);
	
return operar(cont1,funcion,n,restante,y);
}
std::vector<std::string> Tabla::llenarmatrices(std::string ecuacion){ //Aqui esta lo de los datos
	int cont1=0,variables=0;
	variables=numvariables(ecuacion);
	std::vector<std::string> respuestas;
	for(int cont=0;cont<pow(2,variables);cont++){
		cont1=0;
		respuestas.push_back(separarterminos(cont1,ecuacion,cont));
	}
	
 
	}


Tabla::~Tabla()
{
}
