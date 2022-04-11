#include "Header.h";


class MyString
{
private:

	char* str;
	int length;

public:

	MyString() 
	{
		str = nullptr;
		length = 0;
	}

	MyString(const char* str) 
	{
		length = strlen(str);
		this->str = new char[length + 1];

		for (int i = 0; i < length; i++)
		{
			this->str[i] = str[i];
		}
		this->str[length] = '\0';
	}

	MyString(const MyString& other) 
	{
		length = strlen(other.str);
		this->str = new char[length + 1];


		for (int i = 0; i < length; i++)
		{
			this->str[i] = other.str[i];
		}
		this->str[length] = '\0';
	}

	MyString(MyString&& other) 
	{
		this->length = other.length;
		this->str = other.str;
		other.str = nullptr;
	}

	~MyString() 
	{
		delete[] this->str;
	}

	void print()
	{
		std::cout << this->str << std::endl;
	}

	MyString& operator =(const MyString& other) 
	{
		if (this->str != nullptr)
		{
			delete[] this->str;
		}

		int size = strlen(other.str);
		this->str = new char[size + 1];

		for (int i = 0; i < size; i++)
		{
			this->str[i] = other.str[i];
		}
		this->str[size] = '\0';
		return *this;
	}

	MyString& operator +(const MyString& other) 
	{
		MyString newString;

		int thisSize = strlen(this->str);
		int otherSize = strlen(other.str);
		newString.length = thisSize + otherSize;

		newString.str = new char[thisSize + otherSize + 1];

		int i = 0;
		for (; i < thisSize; i++)
		{
			newString.str[i] = this->str[i];
		}

		for (int j = 0; j < otherSize; j++, i++)
		{
			newString.str[i] = other.str[j];
		}
		newString.str[thisSize + otherSize] = '\0';
		return newString;
	}

	int length()
	{
		return length;
	}

	bool operator ==(const MyString& other)
	{
		if (this->length != other.length)
			return false;


		for (int i = 0; i < this->length; i++)
		{
			if (this->str[i] != other.str[i])
				return false;
		}
		return true;
	}

	bool operator !=(const MyString& other)
	{
		return !(this->operator==(other));
	}

	char& operator [](int index)
	{
		return this->str[index];
	}
};