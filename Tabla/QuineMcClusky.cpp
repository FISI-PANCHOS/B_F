#include "QuineMcClusky.h"
#include "Tabla.h"

QuineMcClusky::QuineMcClusky(string funcion, char n){
	n='y';
	Tabla tab(funcion,n);
	VARIABLES=numvariables(funcion);
  	dontcares.append(numvariables(funcion),'-');
  	int num,cont3=0;
	vector<string> miniterminos;
	string temp,cadena;
	stringstream ss; 
    for(int cont2=0;cont2<pow(2,VARIABLES);cont2++){
		cont3=0;
		if(tab.separarterminos(cont3,funcion,cont2)=="1"){
			ss.str("");
			ss<<cont2;
			cadena=ss.str();
			temp=temp+cadena;
			if(cont2<pow(2,VARIABLES)-1){
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
         miniterminos.push_back(pad(decimal_a_binario(t)));
      }

      sort(miniterminos.begin(),miniterminos.end());

      do
      {
         miniterminos=reducir(miniterminos);
         sort(miniterminos.begin(),miniterminos.end());
      }while(!VectorsEqual(miniterminos,reducir(miniterminos)));


      int i;
      cout << "La expresion reducida es" << endl;
      for (i=0;i<miniterminos.size()-1; i++)
          cout <<obternervalor(miniterminos[i],funcion)<<"v";
      cout<<obternervalor(miniterminos[i],funcion)<<endl;
  	
  	
}
int QuineMcClusky::numvariables(string funcion){
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
vector<string> QuineMcClusky::obtener_variables(string ecuacion){	
	int n=0,cont=0;
	string lista[4];

		if(ecuacion.find("X") != string::npos){
			lista[cont]="X";
			cont++;
		}
		if(ecuacion.find("Y") != string::npos){
			lista[cont]="Y";
			cont++;
		}
		if(ecuacion.find("Z") != string::npos){
			lista[cont]="Z";
			cont++;
		}
		if(ecuacion.find("W") != string::npos){
			lista[cont]="W";
			cont++;
		}

   vector<string> v;
   v.clear();
   for(int i=0;i<this->VARIABLES;i++){
    	v.push_back(lista[i]);
	} 

   return v;
}
string QuineMcClusky::decimal_a_binario(int n){
   if ( n == 0 )
       return n+"";

   if ( n % 2 == 0 )
       return decimal_a_binario(n / 2) + "0";
   else
       return decimal_a_binario(n / 2) + "1";
}
string QuineMcClusky::pad(string binario){
   int max=VARIABLES-binario.length();
   for(int i=0; i<max; i++)
       binario="0"+binario;
   return binario;
}
bool QuineMcClusky::isGreyCode(string a,string b){
   int cont=0;
   for(int i=0;i<a.length();i++){
       if(a[i]!=b[i])
        cont++;
   }
   return (cont==1);
}
string QuineMcClusky::remplazar_complementos(string a,string b){
   string temp="";
   for(int i=0;i<a.length();i++)
   if(a[i]!=b[i])
       temp=temp+"-";
   else
       temp=temp+a[i];

   return temp;
}
bool QuineMcClusky::in_vector(vector<string> a,string b){
   for(int i=0;i<a.size();i++)
     if(a[i].compare(b)==0)
      return true;
    return false;
}
vector<string> QuineMcClusky::reducir(vector<string> minterms){


      vector<string> newminterms;

      int max=minterms.size();
      int* checked = new int[max];
      for(int i=0;i<max;i++)
      {
          for(int j=i;j<max;j++)
          {
               //If a grey code pair is found, replace the differing bits with don't cares.
               if(isGreyCode(minterms[i],minterms[j]))
               {
                  checked[i]=1;
                  checked[j]=1;
                  if(!in_vector(newminterms,remplazar_complementos(minterms[i],minterms[j])))
                     newminterms.push_back(remplazar_complementos(minterms[i],minterms[j]));
               }
          }
      }

      //appending all reduced terms to a new vector
      for(int i=0;i<max;i++)
      {
          //cout<<checked[i]<<endl;
          if(checked[i]!=1 && ! in_vector(newminterms,minterms[i]))
           newminterms.push_back(minterms[i]);
      }

       delete[] checked;
   
       return newminterms;
}
string QuineMcClusky::obternervalor(string a,string ecuacion){	
	vector<string> vars=this->obtener_variables(ecuacion);

   	string temp ="";

   	if(a==dontcares)
     return "1";

   	for(int i=0;i<a.length();i++)
   {
     if(a[i]!='-')
     {
        if(a[i]=='0'){
         temp=temp+vars[i]+"\'";
         if(i<a.length()-1 and ecuacion.find('^') != string::npos ){
         	temp=temp+"^";
		 }
   		}
        else{
         temp=temp+vars[i];
         if(i<a.length()-1 and ecuacion.find('^') != string::npos ){
         	temp=temp+"^";
		 }
   		}
     }
   }
   return temp;
}
bool QuineMcClusky::VectorsEqual(vector<string> a,vector<string> b){
   if(a.size()!=b.size())
      return false;

    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    for(int i=0;i<a.size();i++)
    {
        if(a[i]!=b[i])
        return false;
    }
    return true;
}

