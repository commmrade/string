#include <cstdio>
#include<iostream>
#include "str.h"


using namespace std;

using str = klewy::String;



int main()
{
	//string a;
	
	str a = "hehe";

	cout << *(a.begin() + 4) << endl;
	
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