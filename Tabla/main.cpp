#include <iostream>
#include <math.h>
#include <string>
#include <vector>
#include <string.h>
#include <list>
#include "Tabla.h"
#include "QuineMcClusky.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int num;
	vector<string> miniterminos;
	string ecuacion;
	printf("inserta tu frase plox: ");
    getline(cin,ecuacion);	
    Tabla tab(ecuacion);
	num=tab.numvariables(ecuacion);    
    QuineMcClusky  q(num);
	miniterminos=tab.llenarmatrices(ecuacion);
      string temp="";
      cout<<"Enter the minterms(RANGE=0-"<<pow(2,num)-1<<") separated by comma:"<<endl;
      cin>>temp;

      //splitting the input
      vector<string> minterms;
      istringstream f(temp);
      string s;
      while (getline(f, s, ','))
      {
          //cout << s << endl;
         int t=atoi(s.data());
         minterms.push_back(q.pad(q.decToBin(t)));
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
          cout <<q.getValue(miniterminos[i])<<"+";
      cout<<q.getValue(miniterminos[i])<<endl;

	return 0;
}
