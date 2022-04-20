#include "MyString.h"; 

int main()
{
	MyString a("Hello, ");
	a.print();
	MyString b("World");
	b.print();
	MyString c("!");


	MyString d;
	d = a + b + c;
	d.print();

	c.operator==(d);

	return 0;
}