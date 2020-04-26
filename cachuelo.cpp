#include <iostream>
#include <string.h>

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
bool operar(){
	
}
void leerfuncion(char funcion[100]){
	int s,j=0;
	bool a,b;
	bool reducciones[50];
	printf("inserta tu frase plox: ");
    gets(funcion);
    s=strlen(funcion);
    for(int i=0;i<s;i++){
    if(funcion[i]=='('){
    	/*if(funcion[i+4]==')'||funcion[i]=='e'){*/
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
    	
    		
	    		
        
    }
	
}

}
int main(){
	char funcion[100];
	
    leerfuncion(funcion);
    return 0;
    
    return 0;
}
