#pragma once
#include<iostream>


#define DEBUG


namespace klewy
{
class String
{
public:
	//Constructors
	String() = delete; //No default constructor for now
	String(const char* str);
	~String();
	String(const String& other); //Copy constructor
	String(String&& other) noexcept; //Move constructor

	//Operators override
	String operator=(const String& other);
	String operator+(const String& other);
	String operator+=(const String& other);

	

	//Methods
	void print_out()
	{
		std::cout << str << std::endl;
	}
	friend std::ostream& operator<<(std::ostream& os, const String& dt);

private:
	char* str;
	size_t size;

};


}



