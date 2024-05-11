#include <cstdio>
#include<iostream>
#include "str.h"


using namespace std;

using str = klewy::String;



int main()
{
	//string a;
	
	str a = "hehehahasas";

	//printf("%s\n", a.c_str());
	
	string f = "nifgffdghdfghdfghf";
	
	//a[0] = 'f';
	
	std::cout << *(++a.begin()) << endl;
	
	printf("====\n");

	for(auto i : a)
	{
		cout << i << endl;
	}
	printf("====\n");


	return 0;
}