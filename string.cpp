#include <cstddef>
#include <cstdio>
#include<iostream>
#include <iterator>
#include "str.h"


using namespace std;

using str = klewy::String;



int main()
{
	//string a;
	
	str a = "hehe";

	
	
	
	printf("====\n");

	// for(auto &i : a)
	// {
	// 	cout << i << endl;
	// }
	for(auto i : a)
	{
		cout << i << endl;
	}
	printf("====\n");


	return 0;
}