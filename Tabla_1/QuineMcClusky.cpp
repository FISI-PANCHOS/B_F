#include "QuineMcClusky.h"

QuineMcClusky::QuineMcClusky(std::string funcion){
}
std::string QuineMcClusky::funcion_reducida(std::string funcion){
	Tabla tab(funcion);	
	VARIABLES=numvariables(funcion);
	std::string f_reducida;
  	dontcares.append(numvariables(funcion),'-');
  	int num,cont3=0;
  	
	std::vector<std::string> miniterminos;
	std::string temp,cadena;
	std::stringstream ss; 
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
      
      std::istringstream f(temp);
      std::string s;
      while (getline(f, s, ','))
      {
          
         int t=atoi(s.data());
         miniterminos.push_back(pad(decimal_a_binario(t)));
      }

      sort(miniterminos.begin(),miniterminos.end());

      do
      {
         miniterminos=reducir(miniterminos);
         sort(miniterminos.begin(),miniterminos.end());
      }while(!VectorsEqual(miniterminos,reducir(miniterminos)));


      for (int i=0;i<miniterminos.size()-1; i++){
          f_reducida=obternervalor(miniterminos[i],funcion)+"v"+obternervalor(miniterminos[i],funcion);
  	}
  	return f_reducida;
}
int QuineMcClusky::numvariables(std::string funcion){
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
std::vector<std::string> QuineMcClusky::obtener_variables(std::string ecuacion){	
	int n=0,cont=0;
	std::string lista[4];

		if(ecuacion.find("X") != std::string::npos){
			lista[cont]="X";
			cont++;
		}
		if(ecuacion.find("Y") != std::string::npos){
			lista[cont]="Y";
			cont++;
		}
		if(ecuacion.find("Z") != std::string::npos){
			lista[cont]="Z";
			cont++;
		}
		if(ecuacion.find("W") != std::string::npos){
			lista[cont]="W";
			cont++;
		}

   std::vector<std::string> v;
   v.clear();
   for(int i=0;i<this->VARIABLES;i++){
    	v.push_back(lista[i]);
	} 

   return v;
}
std::string QuineMcClusky::decimal_a_binario(int n){
   if ( n == 0 )
       return n+"";

   if ( n % 2 == 0 )
       return decimal_a_binario(n / 2) + "0";
   else
       return decimal_a_binario(n / 2) + "1";
}
std::string QuineMcClusky::pad(std::string binario){
   int max=VARIABLES-binario.length();
   for(int i=0; i<max; i++)
       binario="0"+binario;
   return binario;
}
bool QuineMcClusky::isGreyCode(std::string a,std::string b){
   int cont=0;
   for(int i=0;i<a.length();i++){
       if(a[i]!=b[i])
        cont++;
   }
   return (cont==1);
}
std::string QuineMcClusky::remplazar_complementos(std::string a,std::string b){
   std::string temp="";
   for(int i=0;i<a.length();i++)
   if(a[i]!=b[i])
       temp=temp+"-";
   else
       temp=temp+a[i];

   return temp;
}
bool QuineMcClusky::in_vector(std::vector<std::string> a,std::string b){
   for(int i=0;i<a.size();i++)
     if(a[i].compare(b)==0)
      return true;
    return false;
}
std::vector<std::string> QuineMcClusky::reducir(std::vector<std::string> miniterminos){


      std::vector<std::string> newminiterminos;

      int max=miniterminos.size();
      int* checked = new int[max];
      for(int i=0;i<max;i++)
      {
          for(int j=i;j<max;j++)
          {
               //If a grey code pair is found, replace the differing bits with don't cares.
               if(isGreyCode(miniterminos[i],miniterminos[j]))
               {
                  checked[i]=1;
                  checked[j]=1;
                  if(!in_vector(newminiterminos,remplazar_complementos(miniterminos[i],miniterminos[j])))
                     newminiterminos.push_back(remplazar_complementos(miniterminos[i],miniterminos[j]));
               }
          }
      }

      //appending all reduced terms to a new vector
      for(int i=0;i<max;i++)
      {
          //cout<<checked[i]<<endl;
          if(checked[i]!=1 && ! in_vector(newminiterminos,miniterminos[i]))
           newminiterminos.push_back(miniterminos[i]);
      }

       delete[] checked;
   
       return newminiterminos;
}
std::string QuineMcClusky::obternervalor(std::string a,std::string ecuacion){	
	std::vector<std::string> vars=this->obtener_variables(ecuacion);

   	std::string temp ="";

   	if(a==dontcares)
     return "1";

   	for(int i=0;i<a.length();i++)
   {
     if(a[i]!='-')
     {
        if(a[i]=='0'){
         temp=temp+vars[i]+"\'";
        
        
   		}
        else{
         temp=temp+vars[i];
         	
        
   		}
     }
   }
   return temp;
}
bool QuineMcClusky::VectorsEqual(std::vector<std::string> a,std::vector<std::string> b){
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

