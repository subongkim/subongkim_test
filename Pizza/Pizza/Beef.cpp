#include "Beef.h"

Beef::Beef(Pizza * pz) : Add(pz){
	name = "불고기";
}

void Beef::finish(int n)
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
void Beef::Delivery(int n)
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
void Beef::BasicTopping()
{
	pz->BasicTopping();
	cout << "# 불고기를 올리는 중..." << endl;
}
void Beef::Delete()
{
	pz->Delete();
	delete pz;
}
//virtual void MakeCheeze() override{}
//virtual void MakeDough() override{}
