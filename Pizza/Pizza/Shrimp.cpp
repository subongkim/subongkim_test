#include "Shrimp.h"

Shrimp::Shrimp(Pizza* pz) : Add(pz){
	name = "새우";
}

void Shrimp::finish(int n)
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
void Shrimp::Delivery(int n)
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
void Shrimp::BasicTopping()
{
	pz->BasicTopping();
	cout << "# 새우를 올리는 중..." << endl;
}
void Shrimp::Delete()
{
	pz->Delete();
	delete pz;
}
//virtual void MakeCheeze() override{}
//virtual void MakeDough() override{}
