#include "Domino.h"

Pizza* Domino::Create(Pizza*)
{
	return new Domino;
}
Domino::Domino(){
	name = "���̳� ����";
}
void Domino::finish(int n)
{
	cout << name;
}
void Domino::Delivery(int n)
{
	cout << name;
}
void Domino::BasicTopping()
{
	cout << "# �⺻ ������ �ø��� ��..." << endl;
}
void Domino::MakeCheeze()
{
	cout << "# �⺻ ġ� �Ѹ��� ��..." << endl;
}
void Domino::MakeDough()
{
	cout << "# �⺻ ���츦 �����ϴ� ��..." << endl;
}
void Domino::Delete(){}

RegisterPizza Domino::rp(1, &Domino::Create);