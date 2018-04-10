#include <iostream>
#include <initializer_list>
#include <crtdbg.h>

using std::cout;
using std::endl;

/*
#ifndef _DEBUG	// vc

#define new new(_CLIENT_BLOCK,__FILE__,__LINE)

#endif
*/
// �Ʒ� Point���� ����Ʈ �����ڰ� �����ϴ�. ����Ʈ �����ڸ� ������ ����,
// �Ʒ� ���¿��� ������ �������ּ���..
class Point {
	int x, y; //�׽�Ʈ�ڵ�
public:
	Point(int a, int b) : x(a), y(b) {
		cout << "Point(int, int)" << endl;
	}
	Point(const Point& p)
	{
		cout << "Copy" << endl;
	}
	Point(Point&& p) noexcept
	{
		cout << "Move" << endl;
	}
	~Point()
	{
		cout << "~Point" << endl;
	}
};

// �Ʒ� main �Լ��� ����ǵ��� Vector�� �����ؾ� �մϴ�.
template<typename T> class Vector {
	T* buff;
	int sz; // size
	int capa; // capacity (�޸� ��뷮)
public:
	///////�� ���� �ۼ�////////
	Vector(std::initializer_list<T> s) : buff(static_cast<T*>(operator new(sizeof(T)* s.size()))), sz(s.size()), capa(s.size())
	{
		int j = 0;
		/*for (auto i = s.begin(); i != s.end(); ++i, j++)	// begin(s)�� ����ϸ� �Ʒ� 55���ٰ� �̸��� ���ļ� �����߻�.
		{													// �̸� �а�ġ�� ����. ���� ����� �ȶ�����...
		new(buff + j) T(*i);
		}*/
		for (auto& i : s)
		{
			new(buff + (j++)) T{ std::move_if_noexcept(i) };
		}
	}
	Vector(int s, T&& t) : buff(static_cast<T*>(operator new(sizeof(T)* s))), sz(s), capa(s)
	{
		for (int i = 0; i < s; i++)
		{
			new(buff + i) T{ std::move_if_noexcept(t) };
		}
	}
	~Vector()
	{
		cout << "vector �Ҹ���" << endl;
		for (int i = 0; i < sz; i++)
		{
			buff[i].~T();
		}
		operator delete(buff);
		//delete buff; //���� �������� �𸣰���.

	}
	T* begin()
	{
		return buff;
	}
	T* end()
	{
		return buff + sz;
	}
	void resize(int s)
	{
		if (s < sz){
			cout << "resize�� �Ҹ���" << endl;
			for (int i = s; i < sz; i++)
			{
				(buff + i)->~T(); // buff[i].~T(); 
			}
			sz = s;
		}
		/*else if (s > sz)			// Point �����ڰ� ���⿡ �Ұ�����.
		{							// �� �������� �������� ����.
		// ���� �����ڰ� �־��ٸ� resize(int, T)�� ���� �� ����.
		if (s < capa)
		{
		for (int i = sz; i < s; i++)
		{
		//new(buff+i) T();
		}
		}
		else if ((sz * 2) <= s)
		{
		capa = s;
		allocate(capa, s);
		}
		else //capacity ���� ũ�� size�� 2�躸�� ���� ���
		{
		capa = sz * 2;
		allocate(capa, s);
		}
		}*/
	}
	void resize(int s, T&& t)
	{
		if (s >= capa)
		{
			if (s >= (sz * 2))
			{
				capa = s;
				allocate(capa, s, t);
			}
			else
			{
				capa = sz * 2;
				allocate(capa, s, t);
			}
		}
		else
		{
			if (s < sz){
				cout << "resize�� �Ҹ���" << endl;
				for (int i = s; i < sz; i++)
				{
					buff[i].~T();
				}
				sz = s;
			}
			else if (s == sz){}
			else // s > sz
			{
				for (int i = sz; i < s; i++)
				{
					new(buff + i) T{ std::move_if_noexcept(t) };
				}
			}
		}
		/* ���� if��
		if (s < sz){
		for (int i = s; i < sz; i++)
		{
		buff[i].~T(); //(*(buff+i)).~T();
		}
		sz = s;
		}
		else if (s > sz)
		{
		if (s < capa)
		{
		for (int i = sz; i < s; i++)
		{
		new(buff + i) T{ t };
		}
		}
		else if ((sz * 2) <= s)
		{
		capa = s;
		allocate(capa, s, t);
		}
		else //capacity ���� ũ�� size�� 2�躸�� ���� ���
		{
		capa = sz * 2;
		allocate(capa, s, t);
		}
		}*/
	}
	void allocate(const int capa, const int s)
	{
		T* tmp = buff;
		buff = static_cast<T*>(operator new(sizeof(T)*capa));
		for (int i = 0; i < sz; i++)
		{
			new(buff + i) T{ std::move_if_noexcept(*(tmp + i)) };
		}
		cout << "tmp �Ҹ���" << endl;
		for (int i = 0; i < sz; i++)
		{
			tmp[i].~T();
		}
		operator delete(tmp);
		//delete tmp;
		sz = s;
	}
	void allocate(const int capa, const int s, T& t) // t�� lvalue�̹Ƿ�(�ֳ��ϸ� t�� rvlaue�� �ް� �̸��� ������ �����Ƿ�) 
	{
		T* tmp = buff;
		buff = static_cast<T*>(operator new(sizeof(T)*capa));
		for (int i = 0; i < sz; i++)
		{
			new(buff + i) T{ std::move_if_noexcept(*(tmp + i)) };
		}
		cout << "tmp �Ҹ���" << endl;
		for (int i = 0; i < sz; i++)
		{
			tmp[i].~T();
		}
		operator delete(tmp);
		//delete tmp;
		for (int i = sz; i < s; i++)
		{
			new(buff + i) T{ std::move_if_noexcept(t) };
		}
		sz = s;
	}
	int capacity() const
	{
		return capa;
	}
	int size() const
	{
		return sz;
	}
	///////////////////////////
};

int main(int argc, char** argv) {
	//_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	// 1. �Ʒ� �� ���� ����ǰ� ���ּ���..
	//    Point 10���� ���� ���۰� ��������� �ϰ�, Point(1,1)�� �ʱ�ȭ �Ǿ�� �մϴ�.
	Vector<Point> v(10, Point(1, 1));

	// 2. ���۰� 20���� �Ҵ� �ǰ� ���� 10���� �̵�(����)�ϰ�,
	//    ���ο� 10���� Point(0,0)���� �ʱ�ȭ�ǰ� �ϼ���.
	v.resize(20, Point(0, 0));
	// 3. ���� ũ�⸦ �ٽ� 10���� �ٿ� �ּ���. - ���� �޸𸮴� ������ ����, ��ü�� �ı�(�Ҹ��� ȣ��)�� �ּ���.
	v.resize(10);
	cout << v.size() << endl; // 10
	cout << v.capacity() << endl; // 20
	// 4. initializer_list �߰��ϱ�
	Vector<int> v3{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	v3.resize(5);

	Vector<int> v2{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

	// 5. ranged for �����ϱ�
	for (auto n : v2) {
		cout << n << endl; // 1,2,3,4,5,6,7,8,9,10
	}

	return 0;
}
