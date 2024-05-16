#include "str.h"
#include <cstdio>
#include <cstring>
#include <exception>
#include <stdexcept>
#include <string>


namespace klewy
{
String::String(const char* str)
{
	size = strlen(str); // Size of str parameter

	this->str = new char[size + 1]; //Allocating memory for a string
	memcpy(this->str, str, size); // Copying memory from parameter string
	this->str[size] = '\0'; //Null terminating, now it's a proper string.

#ifdef DEBUG
	printf("Constructor\n");
#endif
}
String::~String()
{
	delete[]str; //Deallocating memory

#ifdef DEBUG
	printf("Destructor\n");
#endif
}
String::String(const String& other)
{
	size = other.size; //Getting size from the other string
	str = new char[size + 1]; //Allocating memory and + 1 for the null terminator
	memcpy(str, other.str, size); //Copying memory from the other string 
	str[size] = '\0';
#ifdef DEBUG
	printf("Copy\n");
#endif
	//Unlike move constructor, we don't deallocate memory here, since it has to COPY it.
}
String::String(String&& other) noexcept
{
	size = other.size; // Getting size
	str = other.str; //Now str is pointing to the moved string's memory

	other.size = 0;
	other.str = nullptr; //If you don't do it, moved string's destructor will deallocate the memory and break THIS string

#ifdef DEBUG
	printf("Move\n");
#endif

}
String& String::operator=(String &&other)
{
	size = other.size;
	str = other.str;

	other.size = 0;
	other.str = nullptr; 
#ifdef DEBUG
	std::cout << "operator = Move" << std::endl;
#endif
	return *this;
}

std::ostream& operator<<(std::ostream& os, const String& st)
{
#ifdef DEBUG
	printf("ostream func\n");
#endif


	os << st.str;
	return os;
}

String& String::operator+(const String& other)
{
	int tmp_size = size; //Saving prev size
	char* temp = new char[tmp_size + 1]; //Creating a buffer for the old str
	memcpy(temp, str, tmp_size); //Copying old str to temp
	temp[size] = '\0'; //Null terminating it

	size += other.size; // The size of the concat string

	delete[]str; //Deallocating the old string

	str = new char[size + 2]; //Allocating string
	memcpy(str, temp, tmp_size); //Copying old string here
	delete[]temp; //Deallocating memory for the temp

	str[tmp_size] = '\0'; 


	strncat(str, other.str, other.size + 2); //Connecting two string together; size + 2: 2 stands for 2 null terminators.
	
    
	//The first was before concat. The second is for the final concated string
#ifdef DEBUG
	printf("Operator +\n");
#endif
	
	return *this;
}

String& String::operator*(unsigned int times)
{
	

	int temp_size = this->size * times;
	char *temp = new char[temp_size + 1]; //allocating memory for multiplied string + null terminator
	
	for(int i = 0; i < times; i++)
	{
		snprintf(temp + (i * this->size), this->size + 1, "%s", this->str); //copying itself n times
	}
	temp[temp_size] = '\0'; //Null terminating this moron to avoid any problems
	

	delete [] this->str; //Deallocating the old str

	size = temp_size; //Updating size

	this->str = temp; //Changing str

	return *this;
}


String& String::operator=(const String& other)
{
	
	delete[]str;
	size = other.size;
	str = new char[size + 1];
	memcpy(str, other.str, size);
	str[size] = '\0';


	return *this;

#ifdef DEBUG
	printf("Operator = \n");
#endif
}



String& String::operator+=(const String& other)
{
	*this = *this + other.str; //I use operator+ here, so I won't have to write whole different logic for this operator
	//You can interpret this like [String = String + String] which exactly fits operator+. 

	return *this; //Returning itself
}

const char String::operator[](size_t index) const
{
	if(index >= size)
	{
		throw std::runtime_error("Out of bounds");
	}
	return str[index];
}
char& String::operator[](size_t index)
{
	if(index >= size)
	{
		throw std::runtime_error("Out of bounds");
	}
	return str[index];
}

int String::length() const {
	return size;
}
size_t String::find(const char* to_find)
{
	if (strlen(to_find) > size)
	{
		return -1;
	}
	
	for (int i = 0; i < size; i++)
	{
		bool flag = true;
		for (int j = 0; j < strlen(to_find); j++)
		{
			if (str[i] != to_find[j])
			{
				flag = false;
				break;
			}
			else
			{
				i++; //If  equal move the string index
			}
		}
		if (flag)
		{
			return i - strlen(to_find);
		}
	}
	return -1;	
}
String String::substr(size_t index)
{
	assert(index < size + 1 && "Out of range");
	size_t sublen = size - index + 1; // Size of new substring

	char* temp = new char[sublen + 1]; //Allocating memory
	memcpy(temp, str + index - 1, sublen); //-1 because the index starts from 1
	temp[sublen] = '\0'; 

	String retValue(temp); //Creating a new string

	delete[]temp; //Deallocating temp because temp was copied in retValue constructor
	return retValue; //returning new string
}
const char* String::c_str() const
{
	return str; //returning const char *
}
char String::at(size_t index) const
{
	if(index >= size)
	{
		throw std::runtime_error("Out of bounds");
	}
	return str[index];
}

//=====================================ITERATOR=================

char& String::iterator::operator*()
{
	return *str; //Dereferencing 
}
bool String::operator==(const String &other) const
{
	if(strcmp(str, other.str) == 0) { // 0 - equal <1 smth else >1 smth  else
		return true;
	}

	return false;
}

bool String::operator!=(const String &other) const
{
	if(strcmp(str, other.str) != 0) { // 0 - equal <1 smth else >1 smth  else
		return true;
	}

	return false;
}



String::iterator String::iterator::operator++()
{
	//index++;
	str++; //Moving pointer by one
	return *this;
}
String::iterator String::iterator::operator++(int)
{
	iterator temp = *this;
	
	this->str++; //Incrementing current iterator

	return temp; //Returning new iterator
}
String::iterator String::iterator::operator+(std::ptrdiff_t index)
{	
	if((str + index) >= &str[this->maxlen])
	{
		throw std::runtime_error("Out of bounds");
	}
	str = str + index; //Moving pointer by x
	return *this;
}



bool String::iterator::operator!=(const iterator &other)
{
	return this->str != other.str; //Comparing pointer addresses
}

bool String::iterator::operator==(const iterator &other)
{
	return this->str == other.str;	//Comparing pointer addresses
}

String::iterator String::begin()
{
	return iterator(&str[0], length()); // Returning iterator which points to str[0]
}
String::iterator String::end()
{
	return iterator(&str[length()], length());// Returning iterator which points to the end of string + 1 so like the range-for won't stop at the last symbol and won't print it
}






















}


