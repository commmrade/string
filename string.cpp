#include <cstddef>
#include <cstdio>
#include<iostream>
#include <iterator>
#include "str.h"


using namespace std;

using str = klewy::String;



int main()
{
	
	str a = "ffuck";
	str b = "fuck";

	if(a != b)
	{
		printf("true\n");
	}


	return 0;
}