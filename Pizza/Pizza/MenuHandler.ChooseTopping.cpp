#include <iostream>
#include <string>

#include "MenuHandler.h"

using namespace std;
bool MenuHandler::ChooseTopping()
{
	int toppingNumber_;
	cout << "# [x]���� ����/[-]���� ����/[ ]�߰� �ֹ�/[ ]�����" << endl;
	if (!preset.get_add_Topping())
	{
		cout << "# �߰��Ͻ� ������ �������ּ���." << endl;
	}
	else
	{
		cout << "# ������ �� �߰��Ͻ÷��� �������ּ���." << endl;
	}
	for (int i = 0; i < preset.getToppingList().size(); i++)
	{
		cout << "(" << i + 1 << ") " << preset.getToppingList()[i] << endl;
	}
	cout << "(0) �߰����� ����" << endl;
	cout << endl;
	cout << ">> ";
	cin >> toppingNumber_;
	
	if (toppingNumber_ == 0)
	{
		checkNum.push_back(topping_count_);
		return false;
	}
	else
	{
		topping_count_++;
		preset.setTopping(toppingNumber_);
		return true;
	}
}