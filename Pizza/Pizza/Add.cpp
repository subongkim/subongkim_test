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
	cout << "# ġ� �Ѹ��� ��..." << endl;
}
void Add::MakeDough()
{
	cout << "# ���츦 �����ϴ� ��..." << endl;
}
void Add::Delete()
{
	pz->Delete();
	delete pz;
}




