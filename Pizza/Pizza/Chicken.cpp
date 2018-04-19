#include "Chicken.h"

Chicken::Chicken(Pizza* pz) : Add(pz)
{
	name = "닭가슴살";
}

void Chicken::finish(int n)
{
	n--;
	if (n != 0)
	{
		cout << name << "과(/와)";
		pz->finish(n);
	}
	else{
		cout << name << "을(/를) 올린 ";
		pz->finish(n);
	}
}
void Chicken::Delivery(int n)
{
	n--;
	if (n != 0)
	{
		cout << name << "과(/와)";
		pz->Delivery(n);
	}
	else{
		cout << name << "을(/를) 올린 ";
		pz->Delivery(n);
	}
}
void Chicken::BasicTopping()
{
	pz->BasicTopping();
	cout << "# 닭가슴살을 올리는 중..." << endl;

}
//virtual void MakeCheeze() override{}
//virtual void MakeDough() override{}
void Chicken::Delete()
{
	pz->Delete();
	delete pz;
}