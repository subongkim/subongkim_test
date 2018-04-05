#include <iostream>

class Cat
{
	char* name;
	int age;
public:
	Cat(const char* n, int a) : age(a)
	{
		name = new char[strlen(n) + 1];
		strcpy(name, n);
	}
	~Cat() { delete[] name; }
};

int main()
{
	Cat c1("NABI", 2);
	Cat c2 = c1;
}