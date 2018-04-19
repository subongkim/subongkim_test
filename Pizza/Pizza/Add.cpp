#include <iostream>
//#include "Pizza.h"
#include "Add.h"
using namespace std;

Add::Add(Pizza* pz)
{
	this->pz = pz;
}
void Add::Delivery(int n) {}
void Add::finish(int n) {}
void Add::BasicTopping()
{}
void Add::MakeCheeze()
{
	cout << "# 치즈를 뿌리는 중..." << endl;
}
void Add::MakeDough()
{
	cout << "# 도우를 반죽하는 중..." << endl;
}
void Add::Delete()
{
	pz->Delete();
	delete pz;
}




