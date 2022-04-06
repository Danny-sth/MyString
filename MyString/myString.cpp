#include "Header.h";


class MyString
{
private:

	char* str;
	int length;

public:

	MyString() // конструктор класса без параметров
	{
		str = nullptr;
		length = 0;
	}

	MyString(const char* str) // конструктор класса с параметрами
	{
		length = strlen(str);
		this->str = new char[length + 1];

		for (int i = 0; i < length; i++)
		{
			this->str[i] = str[i];
		}
		this->str[length] = '\0';
	}

	MyString(const MyString& other) // конструктор копирования, создание копии обьекта но в другой области памяти
	{
		length = strlen(other.str);
		this->str = new char[length + 1];


		for (int i = 0; i < length; i++)
		{
			this->str[i] = other.str[i];
		}
		this->str[length] = '\0';
	}

	MyString(MyString&& other) // конструктор перемещения, присвоение адреса на обьекты в динамической памяти
		// указателю обьекта this c последующим затиранием указателя переданного обьекта
	{
		this->length = other.length;
		this->str = other.str;
		other.str = nullptr;
	}

	~MyString() // деструктор, служит для освобождения динамической памяти
	{
		delete[] this->str;
	}

	void print()
	{
		std::cout << this->str << std::endl;
	}

	MyString& operator =(const MyString& other) // оператор присваивания
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

	MyString& operator +(const MyString& other) // конкатенация
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

	int length() // возвращает длину строки
	{
		return length;
	}

	bool operator ==(const MyString& other) // оператор сравнения
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