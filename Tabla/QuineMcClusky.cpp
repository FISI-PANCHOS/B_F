#include "QuineMcClusky.h"

QuineMcClusky::QuineMcClusky(int var)
{
	VARIABLES=var;
  	dontcares.append(var,'-');
}
vector<string> QuineMcClusky::getVars(string ecuacion){	
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
string QuineMcClusky::decToBin(int n)
{
   if ( n == 0 )
       return n+"";

   if ( n % 2 == 0 )
       return decToBin(n / 2) + "0";
   else
       return decToBin(n / 2) + "1";
}
string QuineMcClusky::pad(string bin)
{
   int max=VARIABLES-bin.length();
   for(int i=0; i<max; i++)
       bin="0"+bin;
   return bin;
}
bool QuineMcClusky::isGreyCode(string a,string b)
{
   int flag=0;
   for(int i=0;i<a.length();i++)
   {
       if(a[i]!=b[i])
        flag++;
   }
   return (flag==1);
}
string QuineMcClusky::replace_complements(string a,string b)
{
   string temp="";
   for(int i=0;i<a.length();i++)
   if(a[i]!=b[i])
       temp=temp+"-";
   else
       temp=temp+a[i];

   return temp;
}
bool QuineMcClusky::in_vector(vector<string> a,string b)
{
   for(int i=0;i<a.size();i++)
     if(a[i].compare(b)==0)
      return true;
    return false;
}
vector<string> QuineMcClusky::reduce(vector<string> minterms)
{


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
                  if(!in_vector(newminterms,replace_complements(minterms[i],minterms[j])))
                     newminterms.push_back(replace_complements(minterms[i],minterms[j]));
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
string QuineMcClusky::getValue(string a,string ecuacion)
{	vector<string> vars=this->getVars(ecuacion);

   string temp ="";

   if(a==dontcares)
     return "1";

   for(int i=0;i<a.length();i++)
   {
     if(a[i]!='-')
     {
        if(a[i]=='0')
         temp=temp+vars[i]+"\'";
        else
         temp=temp+vars[i];
     }
   }
   return temp;
}
bool QuineMcClusky::VectorsEqual(vector<string> a,vector<string> b)
{
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

