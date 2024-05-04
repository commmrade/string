#include "str.h"
#include <cstring>


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

std::ostream& operator<<(std::ostream& os, const String& st)
{
#ifdef DEBUG
	printf("ostream func\n");
#endif


	os << st.str;
	return os;
}

String String::operator+(const String& other)
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
String String::operator=(const String& other)
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

String String::operator+=(const String& other)
{
	*this = *this + other.str; //I use operator+ here, so I won't have to write whole different logic for this operator
	//You can interpret this like [String = String + String] which exactly fits operator+. 

	return *this; //Returning itself
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
			}
			else
			{
				i++;
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




}


