#include <iostream>
using namespace std;
class Test
{
public:
	Test() {}	// �ڿ��Ҵ�
	~Test() {}	// �ڿ�����
	Test(const Test& t) { cout << "Copy" << endl; }
	Test(Test&& t)		{ cout << "Move" << endl; }

	Test& operator=(const Test& t)	{
		{ cout << "Copy=" << endl; }
		return *this; } // ���� ���Կ�����
	Test& operator=(Test&& t)		{ 
		{ cout << "Move=" << endl; }
		return *this; } // move ���Կ�����
};

template<typename T> void Swap(T& x, T& y)
{

	//	Test tmp = x;	// ���� ������
	//	x = y;			// ���� ����
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
	Test t5 = move(t2);					// Move, move�� ���������� ��ó�� ĳ������.

	Test t6;
	Test t7 = t6;	// �ʱ�ȭ. ���� ������
	t6 = t7;		// ����.   ���� ������
	t6 = move(t7);	// move ���� ������
}

