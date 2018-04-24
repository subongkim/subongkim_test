#include "Mister.h"

Pizza* Mister::Create(Pizza*)
{
	return new Mister;
}
Mister::Mister()
{
	name = "미스터 피자";
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
	cout << "# 기본 토핑을 올리는 중..." << endl;
}
void Mister::MakeCheeze()
{
	cout << "# 기본 치즈를 뿌리는 중..." << endl;
}
void Mister::MakeDough()
{
	cout << "# 기본 도우를 반죽하는 중..." << endl;
}
void Mister::Delete() {}

RegisterPizza Mister::rp(2, &Mister::Create);