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
	String operator*(unsigned int times);
	const char operator[](size_t index) const;
	//Todo : [] for index changing
	char& operator[](size_t index);



	//Methods
	int length() const;
	size_t find(const char* to_find);
	String substr(size_t index);
	const char* c_str() const;
	char at(size_t index) const; 

	//Friend methods
	friend std::ostream& operator<<(std::ostream& os, const String& dt);

	//Statics
	static constexpr const size_t npos = -1;



	class iterator //I think its worst fucking possible implementation of iterator
	{
	private:
		char *str;
		
	public:
		iterator(char *s, size_t index) : str(s){};
		char& operator*();
		
		iterator& operator++();
		
		bool operator!=(const iterator &other);
		
		bool operator==(const iterator &other);
		

	};

	iterator begin();
	iterator end();





private:
	char* str;
	size_t size;

};


}



