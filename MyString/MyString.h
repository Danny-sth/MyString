#pragma once
#include <iostream>

class MyString
{
	char* str;
	int length;
public:
	MyString();
	MyString(const char* str);
	MyString(const MyString& other);
	MyString(MyString&& other);
	~MyString();
	void print();
	MyString& operator =(const MyString& other);
	MyString& operator +(const MyString& other);
	int getLength();
	bool operator ==(const MyString& other);
	bool operator !=(const MyString& other);
	char& operator [](int index);
};