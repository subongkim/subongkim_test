#include <iostream>
using namespace std;
class Test
{
	int* resource;
public:
	Test() {}	// �ڿ��Ҵ�
	~Test() {}	// �ڿ�����

	//���� ������ : �������� or ������� 
	//const lvalue reference�̹Ƿ� lvalue�� rvalue ��� ���� �� ����.
	Test(const Test& t) { cout << "Copy" << endl; }

	// move ������ : ������ ����(�ڿ� ����)
	//rvalue�� ���� ���� �� ����.
	Test(Test&& t)		{ cout << "Move" << endl; }
};

int main()
{
	Test t1;
	Test t2 = t1;		// t1�� lvalue�̹Ƿ� ���� ������ ȣ��
	Test t3 = Test();	// �ӽð�ü(rvlaue)�̹Ƿ� move ������ ȣ��
						// �� �����ε� �켱������ ���� rvalue reference�� ��.
}

