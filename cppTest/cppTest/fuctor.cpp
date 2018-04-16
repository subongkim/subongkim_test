#include <iostream>

inline bool cmp1(int a, int b) // 1번
{ 
	// 1-1번
	return a > b; 
} 
inline bool cmp2(int a, int b) // 2번
{
	// 2-1번
	return a < b; 
}
struct Less // 3번
{
	// 3-1번
	inline bool operator()(int a, int b) const 
	{ 
		// 3-2번
		return a < b; 
	} 
};
struct Greater{ inline bool operator()(int a, int b) const { return a > b; } }; // 4번
template<typename T> void foo(T f) // 5번
{
	bool b = f(1, 2);
}
int main() //6번
{
	// hello
	foo(cmp1);
	foo(cmp2);
	foo(Less());
	foo(Greater());
	// world
	return 0;
}

