#include "Chicken.h"

Chicken::Chicken(Pizza* pz) : Add(pz)
{
	name = "�߰�����";
}

void Chicken::finish(int n)
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
void Chicken::Delivery(int n)
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
void Chicken::BasicTopping()
{
	pz->BasicTopping();
	cout << "# �߰������� �ø��� ��..." << endl;

}
//virtual void MakeCheeze() override{}
//virtual void MakeDough() override{}
void Chicken::Delete()
{
	pz->Delete();
	delete pz;
}