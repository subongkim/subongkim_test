#include "Mister.h"

Pizza* Mister::Create(Pizza*)
{
	return new Mister;
}
Mister::Mister()
{
	name = "�̽��� ����";
}

void Mister::finish(int n)
{
	cout << name;
}
void Mister::Delivery(int n)
{
	cout << name;
}
void Mister::BasicTopping()
{
	cout << "# �⺻ ������ �ø��� ��..." << endl;
}
void Mister::MakeCheeze()
{
	cout << "# �⺻ ġ� �Ѹ��� ��..." << endl;
}
void Mister::MakeDough()
{
	cout << "# �⺻ ���츦 �����ϴ� ��..." << endl;
}
void Mister::Delete() {}

RegisterPizza Mister::rp(2, &Mister::Create);