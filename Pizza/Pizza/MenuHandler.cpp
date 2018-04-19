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
	cout << "원하시는 메뉴를 선택해주세요." << endl;
	cout << "# 1. 피자 주문" << endl;
	//cout << "# 2. 피자 브랜드 추가" << endl;
	//cout << "# 3. 토핑 추가" << endl;
	cout << "# 4. 프로그램 종료" << endl;
	cout << endl;
	cout << ">> ";
	cin >> menu_;
	switch (menu_)
	{
	case static_cast<int>(menu::order) :
		do{				//주문 방식
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