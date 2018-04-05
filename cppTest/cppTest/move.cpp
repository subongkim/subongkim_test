#include <iostream>
using namespace std;
class Test
{
public:
	Test() {}	// 자원할당
	~Test() {}	// 자원해지
	Test(const Test& t) { cout << "Copy" << endl; }
	Test(Test&& t)		{ cout << "Move" << endl; }

	Test& operator=(const Test& t)	{
		{ cout << "Copy=" << endl; }
		return *this; } // 복사 대입연산자
	Test& operator=(Test&& t)		{ 
		{ cout << "Move=" << endl; }
		return *this; } // move 대입연산자
};

template<typename T> void Swap(T& x, T& y)
{

	//	Test tmp = x;	// 복사 생성자
	//	x = y;			// 복사 대입
	//	y = tmp;
	Test tmp = move(x);
	x = move(y);
	y = move(tmp);
}
int main()
{
	Test t1;
	Test t2 = t1;						// Copy
	Test t3 = Test();					// Move
	Test t4 = static_cast<Test&&>(t1);	// Move
	Test t5 = move(t2);					// Move, move가 내부적으로 위처럼 캐스팅함.

	Test t6;
	Test t7 = t6;	// 초기화. 복사 생성자
	t6 = t7;		// 대입.   대입 연산자
	t6 = move(t7);	// move 대입 연산자
}

