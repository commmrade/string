#pragma once
#include<iostream>
#include<assert.h>
#include<cstring>
#include <stdint.h>
#include<iterator>


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
	String& operator=(const String& other);
	String& operator=(String &&other); //Move =
	String operator+(const String& other);
	String& operator+=(const String& other);
	String& operator*(unsigned int times);

	bool operator==(const String &other) const;
	bool operator!=(const String &other) const;
	const char operator[](size_t index) const;
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



	class iterator  //I think its worst fucking possible implementation of iterator
	{
	private:
		char *str;
		size_t maxlen;
		
	public:
		using difference_type = std::ptrdiff_t;

		iterator(char *s, size_t mx) : str(s), maxlen(mx) {}; // Passing maxlen so the iterator can't point to not used memory
		char& operator*();
		
		iterator operator++(); //Prefix incr
		iterator operator+(std::ptrdiff_t index);
		iterator operator++(int); //Postfix incr


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



