#include<iostream>
#include "str.h"


using namespace std;

using str = klewy::String;


int main()
{
	str a = "fuck";
	str b = "cccc";

	str c = a + b;

	cout << c << endl;

	cout << c.length() << endl;


	
	
	return 0;
}