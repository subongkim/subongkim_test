#include <iostream>
#include <string>


#include "MenuHandler.h"

using namespace std;
void MenuHandler::AddOrder()
{
	pan++;
	int pizzaBrand_;
	cout << "# [-]���� ����/[ ]���� ����/[ ]�߰� �ֹ�/[ ]�����" << endl;
	cout << "# ���Ͻô� ���ڸ� �������ּ���." << endl;
	for (int i = 0; i < preset.getBrandList().size(); i++)
	{
		cout << "(" << i + 1 << ") " << preset.getBrandList()[i] << endl;
	}
	cout << endl;
	cout << ">> ";
	cin >> pizzaBrand_;
	
	pz.push_back(pf->OrderPizza(pizzaBrand_));
	preset.setPizzaBrand(pizzaBrand_);
}