#include <iostream>
using namespace std;
class Test
{
	int* resource;
public:
	Test() {}	// 자원할당
	~Test() {}	// 자원해지

	//복사 생성자 : 깊은복사 or 참조계수 
	//const lvalue reference이므로 lvalue와 rvalue 모두 받을 수 있음.
	Test(const Test& t) { cout << "Copy" << endl; }

	// move 생성자 : 소유권 이전(자원 전달)
	//rvalue만 전달 받을 수 있음.
	Test(Test&& t)		{ cout << "Move" << endl; }
};

int main()
{
	Test t1;
	Test t2 = t1;		// t1은 lvalue이므로 복사 생성자 호출
	Test t3 = Test();	// 임시객체(rvlaue)이므로 move 생성자 호출
						// 단 오버로딩 우선순위에 의해 rvalue reference로 감.
}

