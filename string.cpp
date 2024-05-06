#include <cstdio>
#include<iostream>
#include "str.h"


using namespace std;

using str = klewy::String;


int main()
{
	
	
	str a = "_Test_";
	// str b = "cccc";

	str c = a * 2;

	cout << c << endl;
	cout << c.length() << endl;

	
	
	
	return 0;
}