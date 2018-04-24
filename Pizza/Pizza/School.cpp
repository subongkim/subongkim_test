#include "School.h"

Pizza* School::Create(Pizza*)
{
	return new School;
}
School::School()								//Pizza에 대한 파생 클래스	
{
	name = "피자스쿨";
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
	cout << "# 기본 토핑을 올리는 중..." << endl;
}
void School::MakeCheeze()
{
	cout << "# 기본 치즈를 뿌리는 중..." << endl;
}
void School::MakeDough()
{
	cout << "# 기본 도우를 반죽하는 중..." << endl;
}
void School::Delete() {}

RegisterPizza School::rp(3, &School::Create);