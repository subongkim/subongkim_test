#include "Shrimp.h"

Shrimp::Shrimp(Pizza* pz) : Add(pz){
	name = "����";
}

void Shrimp::finish(int n)
{
	n--;
	if (n != 0)
	{
		cout << name << "��(/��)";
		pz->finish(n);
	}
	else{
		cout << name << "��(/��) �ø� ";
		pz->finish(n);
	}
}
void Shrimp::Delivery(int n)
{
	n--;
	if (n != 0)
	{
		cout << name << "��(/��)";
		pz->Delivery(n);
	}
	else{
		cout << name << "��(/��) �ø� ";
		pz->Delivery(n);
	}
}
void Shrimp::BasicTopping()
{
	pz->BasicTopping();
	cout << "# ���츦 �ø��� ��..." << endl;
}
void Shrimp::Delete()
{
	pz->Delete();
	delete pz;
}
//virtual void MakeCheeze() override{}
//virtual void MakeDough() override{}
