#include<iostream>
#include "str.h"


using namespace std;

using str = klewy::String;


int main()
{
	while (true)
	{
		str a = "hello world";
		//cin.get();

		//cout << a << endl;


		str b = a.substr(-10);

		cout << b << endl;
	}
	
	
	return 0;
}