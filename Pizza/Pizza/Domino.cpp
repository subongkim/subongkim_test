#include "Domino.h"

Pizza* Domino::Create(Pizza*)
{
	return new Domino;
}
Domino::Domino(){
	name = "도미노 피자";
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
	cout << "# 기본 토핑을 올리는 중..." << endl;
}
void Domino::MakeCheeze()
{
	cout << "# 기본 치즈를 뿌리는 중..." << endl;
}
void Domino::MakeDough()
{
	cout << "# 기본 도우를 반죽하는 중..." << endl;
}
void Domino::Delete(){}

RegisterPizza Domino::rp(1, &Domino::Create);