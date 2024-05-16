#include <cstddef>
#include <cstdio>
#include<iostream>
#include <iterator>
#include "str.h"


using namespace std;

using str = klewy::String;



int main()
{
	
	str a = "hello";
	str b = " world";
	str c = a + b;

	std::cout << c << std::endl;


	return 0;
}