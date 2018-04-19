#include <iostream>
#include "MenuHandler.h"

using namespace std;

MenuHandler::MenuHandler(Order &preset) : preset(preset)
{
	topping_count_ = 0;
}

bool MenuHandler::Run()
{
	int menu_ = 0;
	enum class menu : int { order = 1, addBrand, addTopping };
	cout << "���Ͻô� �޴��� �������ּ���." << endl;
	cout << "# 1. ���� �ֹ�" << endl;
	//cout << "# 2. ���� �귣�� �߰�" << endl;
	//cout << "# 3. ���� �߰�" << endl;
	cout << "# 4. ���α׷� ����" << endl;
	cout << endl;
	cout << ">> ";
	cin >> menu_;
	switch (menu_)
	{
	case static_cast<int>(menu::order) :
		do{				//�ֹ� ���
			AddOrder();
			while (ChooseTopping());
			Make();
		} while (AddPizza());
		Bill();
		break;
	case static_cast<int>(menu::addBrand) :
		//AddPizzaBrand();
		break;
	case static_cast<int>(menu::addTopping) :
		//AddTopping();
		break;
	case 4:
		return false;
	}
	return true;
}
int MenuHandler::pan = -1;