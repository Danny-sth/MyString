#include <iostream>

using namespace std;


class MyString
{
public:

	MyString()
	{
		str = nullptr;
	}

	MyString(const char* str)
	{
		int size = strlen(str);
		this->str = new char[size + 1];

		for (int i = 0; i < size; i++)
		{
			this->str[i] = str[i];
		}
		this->str[size] = '\0';
	}

	~MyString()
	{
		delete[] this->str;
	}

	void print()
	{
		cout << str << endl;
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

	MyString operator +(const MyString& other)
	{
		int thisSize = strlen(this->str);
		int otherSize = strlen(other.str);
		int commonSize = thisSize + otherSize;
		MyString newString;
		newString.str = new char[commonSize + 1];

		int index = 0;
		while (this->str[index] != '\0')
		{
			newString.str[index] = this->str[index];
			index++;
		}

		while (other.str[index] != '\0')
		{
			newString.str[index] = other.str[index];
			index++;
		}
	}

private:
	char* str;
};



int main()
{
	MyString a("Hello");
	a.print();
	MyString b("World");

	a = b;
	a.print();

	return 0;
}