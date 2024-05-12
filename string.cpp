#include <cstddef>
#include <cstdio>
#include<iostream>
#include <iterator>
#include "str.h"


using namespace std;

using str = klewy::String;



int main()
{
	
	str a = "haha";


	for(auto i : a)
	{
		cout << i << endl;
	}
	


	return 0;
}