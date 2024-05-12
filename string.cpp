#include <cstddef>
#include <cstdio>
#include<iostream>
#include <iterator>
#include "str.h"


using namespace std;

using str = klewy::String;



int main()
{
	
	while(true)
	{
		str a = "fufufdufudfdusfdsufsdufsdufsu";
		str b = a * 100; //Mem leak test
	}


	return 0;
}