#include "School.h"

Pizza* School::Create(Pizza*)
{
	return new School;
}
School::School()								//Pizza�� ���� �Ļ� Ŭ����	
{
	name = "���ڽ���";
}

void School::finish(int n)
{
	cout << name;
}
void School::Delivery(int n)
{
	cout << name;
}
void School::BasicTopping()
{
	cout << "# �⺻ ������ �ø��� ��..." << endl;
}
void School::MakeCheeze()
{
	cout << "# �⺻ ġ� �Ѹ��� ��..." << endl;
}
void School::MakeDough()
{
	cout << "# �⺻ ���츦 �����ϴ� ��..." << endl;
}
void School::Delete() {}

RegisterPizza School::rp(3, &School::Create);