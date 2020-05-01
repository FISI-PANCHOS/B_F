#ifndef QUINEMCCLUSKY_H
#define QUINEMCCLUSKY_H
#include <string.h>
#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <iterator>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <math.h>
#include <string>

using namespace std;
class QuineMcClusky
{	int VARIABLES;
		string dontcares;
	public:
		
		QuineMcClusky( string funcion,char n);
		int numvariables(string funcion);
		vector<string> getVars(string ecuacion);
		string decToBin(int n);
		string pad(string bin);
		bool isGreyCode(string a,string b);
		string replace_complements(string a,string b);
		bool in_vector(vector<string> a,string b);
		vector<string> reduce(vector<string> minterms);
		string getValue(string a,string ecuacion);
		bool VectorsEqual(vector<string> a,vector<string> b);
	protected:
};

#endif
