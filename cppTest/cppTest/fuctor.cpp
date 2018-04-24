#include <iostream>

int aa = 10;
class bb
{
private:
	int a = 1, b = 2;
public:
	void change(int a)
	{
		this->a = a;
	}
	static bb& getInstance()
	{
		bb za;
		return za;
	}
};
class aaa {
public:
	aaa(int num){
		bb& test = bb::getInstance();
		test.change(num);
	}
};

class t {
public:
	static aaa bong;
};

class v {
public:
	static aaa bong;
};
aaa t::bong(8);
aaa v::bong(7);
int main() //6¹ø
{
	return 0;
}
