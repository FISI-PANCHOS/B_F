#include <iostream>
#include <string.h>
int cont;
using namespace std;
bool productoAND(bool a, bool b){
	bool resultado;
	resultado=a*b;
	return resultado;
}
bool sumaOR(bool a, bool b){
	bool resultado;
	resultado=a+b;
	return resultado;
}
bool negacion(bool n){
	n=!n;
	return n;
}
bool operacion(bool A, bool B, char operando){
	bool resultado;
	switch(operando){
		case '^':
			resultado=productoAND(A,B);
		break;
		case 'v':
			resultado=sumaOR(A,B);
		break;		
	}
	return resultado;
}
bool tabladeverdad(char ecuacion[], int posicion[],int longitud,int numparentesis){
	int factores=0;
	for(int i=0;i<numparentesis-1;i++){
		factores=(posicion[i+1]-posicion[i])
		switch (factores){
			case 4:
				if
			break;
			case 5:
			break;
			case 6:
			break;
		}
		cont=0;
		if(ecuacion)
		
	}
	
}
int contadordenegaciones(char funcion[]){
	
}
void mostrartabla
void reemplazosegundonivel(char booleana){
	bool reducciones[100];
	reducciones[cont]=booleana;
	
	
}
void leerfuncion(char funcion[100]){
	int s,j=0;
	int terminos;
	int posiciones[100];
	printf("inserta tu frase plox: ");
    gets(funcion);
    s=strlen(funcion);
    for(int i=0;i<s;i++){
    	if(funcion[i]=='('){
    		posiciones[j]=i;
    		j++
    	}
		if(funcion[i]==')'){
    		posiciones[j]=i;
    		j++
    	}	
    }
	tabladeverdad(funcion[],posiciones[],s,j);
}

}
int main(){
	bool
	char funcion[100];
	
    leerfuncion(funcion);
    return 0;
    
    return 0;
}


if(funcion[i]=='('){
    	/*if(funcion[i+4]==')'||funcion[i]=='e'){*
    		switch(funcion[i+2]){
    		case '^':
    			reducciones[j]=productoAND(funcion[i+1],funcion[i+3]);
    			if()
    			
    			 j++;
    		break;
    		case 'v':
    			reducciones[j]=sumaOR(funcion[i+1],funcion[i+3]);
    			cout<<reducciones[j];
    			j++;
    		break;
    		case ''':
    			reducciones[j]=negacion(funcion[i+1]);
    			cout<<reducciones[j];
    			j++;
    		break;
    		
    			
		}
		/*}*/
