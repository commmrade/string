#pragma once
#include<iostream>
#include<assert.h>
#include<cstring>
//#define DEBUG


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
	int length() const;
	size_t find(const char* to_find);
	String substr(size_t index);
	

	//Friend methods
	friend std::ostream& operator<<(std::ostream& os, const String& dt);

	//Statics
	static constexpr const size_t npos = -1;


private:
	char* str;
	size_t size;

};


}



