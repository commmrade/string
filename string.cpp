#include <cstddef>
#include <cstdio>
#include<iostream>
#include <iterator>
#include "str.h"


using namespace std;

using str = klewy::String;




int main()
{
	
	str a = "fuck";
	a += " авфывы";
	

	std::cout << a << std::endl;


	return 0;
}
