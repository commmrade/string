#include<iostream>
#include "str.h"


using namespace std;

using str = klewy::String;


int main()
{
	str a = "hi";
	a += " world";
	cout << a.length() << endl;
	

	return 0;
}