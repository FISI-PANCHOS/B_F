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
	int num,cont3=0;
	vector<string> miniterminos;
	string ecuacion,temp,cadena;
	stringstream ss;
	printf("inserta tu frase plox: ");
    getline(cin,ecuacion);	
    Tabla tab(ecuacion);
	num=tab.numvariables(ecuacion);    
    QuineMcClusky  q(num);
    for(int cont2=0;cont2<pow(2,num);cont2++){
		cont3=0;
		if(tab.separarterminos(cont3,ecuacion,cont2)=="1"){
			ss.str("");
			ss<<cont2;
			cadena=ss.str();
			temp=temp+cadena;
			if(cont2<pow(2,num)-1){
			temp=temp+",";
			}
		}	
	}
      //splitting the input
      istringstream f(temp);
      string s;
      while (getline(f, s, ','))
      {
          //cout << s << endl;
         int t=atoi(s.data());
         miniterminos.push_back(q.pad(q.decToBin(t)));
      }

      sort(miniterminos.begin(),miniterminos.end());

      do
      {
         miniterminos=q.reduce(miniterminos);
         sort(miniterminos.begin(),miniterminos.end());
      }while(!q.VectorsEqual(miniterminos,q.reduce(miniterminos)));


      int i;
      cout << "The reduced boolean expression in SOP form:" << endl;
      for (i=0;i<miniterminos.size()-1; i++)
          cout <<q.getValue(miniterminos[i],ecuacion)<<"v";
      cout<<q.getValue(miniterminos[i],ecuacion)<<endl;

	return 0;
}
