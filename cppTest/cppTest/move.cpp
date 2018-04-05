#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
class Test
{
	char* data;
public:
	Test(const char* dataPtr) : data(new char[strlen(dataPtr)+1]){	
		strcpy(data, dataPtr);
	}
	~Test() {	delete[] data;	}	// �Ҹ���
	Test(const Test& t) { 	cout << "Copy" << endl;	} // ���� ������
	Test(Test&& t) : data(t.data){ // �̵� ������
		t.data = nullptr;
		cout << "Move" << endl; 
	}
	Test& operator=(const Test& t)	// ���� ���Կ�����
	{
		cout << "Copy=" << endl; 
		return *this; 
	}
	Test& operator=(Test&& t)	// move ���Կ�����		
	{  
		data = t.data;
		t.data = nullptr;
		cout << "Move=" << endl; 
		return *this; 
	} 
	friend ostream& operator<<(ostream& os, const Test& t)
	{
		os << t.data;
		return os;
	}
}; 
template<typename T> void Swap(T& x, T& y)
{
	Test tmp = move(x);
	x = move(y);
	y = move(tmp);
}
int main()
{
	Test t1("world");
	Test t2("hello");
	cout << "swap" << endl;
	Swap(t1, t2);
	cout << t1 << " " << t2 << endl;
}

