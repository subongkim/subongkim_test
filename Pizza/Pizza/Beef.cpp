#include "Beef.h"

Beef::Beef(Pizza * pz) : Add(pz){
	name = "�Ұ��";
}

void Beef::finish(int n)
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
void Beef::Delivery(int n)
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
void Beef::BasicTopping()
{
	pz->BasicTopping();
	cout << "# �Ұ�⸦ �ø��� ��..." << endl;
}
void Beef::Delete()
{
	pz->Delete();
	delete pz;
}
//virtual void MakeCheeze() override{}
//virtual void MakeDough() override{}
