#include <iostream>

int Add1(int a, int b) { return a + b; }
inline int Add2(int a, int b) { return a + b; }

int main()
{
	int n1 = Add1(1, 2);	//호출
	int n2 = Add2(1, 2);	//치환

	int(*f)(int, int);

	f = &Add2;

	int n3 = f(1, 2);	//함수포인터에 담아서 사용하면 '치환'대신 '호출'이 됨.
						//컴파일러가 아는 것은 f는 함수포인터 변수라고만 알기 때문에. 
						//또한 함수포인터 '변수'이기에 컴파일시간에 정할 수 없는데에 반해
						//인라인함수는 컴파일시간에 동작하기때문에.
	return 0;
}

