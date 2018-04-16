#include <iostream>

inline bool cmp1(int a, int b) // 1��
{ 
	// 1-1��
	return a > b; 
} 
inline bool cmp2(int a, int b) // 2��
{
	// 2-1��
	return a < b; 
}
struct Less // 3��
{
	// 3-1��
	inline bool operator()(int a, int b) const 
	{ 
		// 3-2��
		return a < b; 
	} 
};
struct Greater{ inline bool operator()(int a, int b) const { return a > b; } }; // 4��
template<typename T> void foo(T f) // 5��
{
	bool b = f(1, 2);
}
int main() //6��
{
	// hello
	foo(cmp1);
	foo(cmp2);
	foo(Less());
	foo(Greater());
	// world
	return 0;
}

