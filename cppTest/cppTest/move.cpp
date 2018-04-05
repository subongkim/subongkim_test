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
	// 깊은 복사로 구현한 복사 생성자
	Cat(const Cat& c) : age(c.age) // 일반 객체들은 이쪽으로 옴.
	{
		name = new char[strlen(c.name) +1];
		strcpy(name, c.name);
	}
	~Cat() { delete[] name; }
	// 소유권 이전의 이동(move) 생성자
	Cat(Cat&& c) : age(c.age) // rvalue reference이므로 rvalue만 옴.(임시객체 등)
	{
		c.name = nullptr;
	}
};
Cat foo() // 값 리턴 -> 임시객체로 리턴(rvalue)
{
	Cat cat("NABI", 2);
	return cat;
}

int main()
{
	Cat c = foo(); //임시객체
}

