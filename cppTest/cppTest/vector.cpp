#include <iostream>
#include <initializer_list>
#include <crtdbg.h>

using std::cout;
using std::endl;


#ifndef _DEBUG	// vc

#define new new(_CLIENT_BLOCK,__FILE__,__LINE)

#endif

// 아래 Point에는 디폴트 생성자가 없습니다. 디폴트 생성자를 만들지 말고,
// 아래 상태에서 과제를 진행해주세요..
class Point {
	int x, y; //테스트코드
public:
	Point(int a, int b) : x{ a }, y{ b } {
		cout << "Point(int, int)" << endl;
	}
	Point(const Point& p) : x{ p.x }, y{ p.y }
	{
		cout << "Copy" << endl;
	}
	Point(Point&& p) _NOEXCEPT : x{ std::move(p.x) }, y{ std::move(p.y) }
	{
		cout << "Move" << endl;
	}
	~Point()
	{
		cout << "~Point" << endl;
	}
};

// 아래 main 함수가 실행되도록 Vector를 구현해야 합니다.
template<typename T> class Vector {
	T* buff;
	int sz; // size
	int capa; // capacity (메모리 사용량)
public:
	///////이 곳에 작성////////
	Vector(std::initializer_list<T> s) : buff(static_cast<T*>(operator new(sizeof(T)* s.size()))), sz(s.size()), capa(s.size())
	{
		int j = 0;
		//ㅣㅎ
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
		cout << "vector 소멸자" << endl;
		for (int i = 0; i < sz; i++)
		{
			buff[i].~T();
		}
		operator delete(buff);
		//delete buff; //operator new를 하면 메모리 앞에 크기를 저장함.(new[]는 개수까지)
		//그 이후 operator delete 시에 그 크기에 맞게 메모리 해제를 하지만 문제는 소멸자를 한번만 부른다는 것!	
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
			cout << "resize시 소멸자" << endl;
			for (int i = s; i < sz; i++)
			{
				(buff + i)->~T(); // buff[i].~T(); 
			}
			sz = s;
		}
		/*else if (s > sz)			// Point 생성자가 없기에 불가능함.
		{							// 즉 이쪽으로 들어오지는 않음.
		// 만약 생성자가 있었다면 resize(int, T)와 묶을 수 있음.
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
		else //capacity 보단 크나 size의 2배보다 작을 경우
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
				cout << "resize시 소멸자" << endl;
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
		/* 기존 if문
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
		else //capacity 보단 크나 size의 2배보다 작을 경우
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
		cout << "tmp 소멸자" << endl;
		for (int i = 0; i < sz; i++)
		{
			tmp[i].~T();
		}
		operator delete(tmp);
		//delete tmp;
		sz = s;
	}
	void allocate(const int capa, const int s, T& t) // t는 lvalue이므로(왜냐하면 t는 rvlaue를 받고 이름을 가지고 있으므로) 
	{
		T* tmp = buff;
		buff = static_cast<T*>(operator new(sizeof(T)*capa));
		for (int i = 0; i < sz; i++)
		{
			new(buff + i) T{ std::move_if_noexcept(*(tmp + i)) };
		}
		cout << "tmp 소멸자" << endl;
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
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	// 1. 아래 한 줄이 실행되게 해주세요..
	//    Point 10개를 위한 버퍼가 만들어져야 하고, Point(1,1)로 초기화 되어야 합니다.
	Vector<Point> v(10, Point(1, 1));

	return 0;
}
