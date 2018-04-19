#include <iostream>
#include <string>

#include "MenuHandler.h"

using namespace std;
bool MenuHandler::ChooseTopping()
{
	int toppingNumber_;
	cout << "# [x]피자 선택/[-]토핑 선택/[ ]추가 주문/[ ]만들기" << endl;
	if (!preset.get_add_Topping())
	{
		cout << "# 추가하실 토핑을 선택해주세요." << endl;
	}
	else
	{
		cout << "# 토핑을 더 추가하시려면 선택해주세요." << endl;
	}
	for (int i = 0; i < preset.getToppingList().size(); i++)
	{
		cout << "(" << i + 1 << ") " << preset.getToppingList()[i] << endl;
	}
	cout << "(0) 추가하지 않음" << endl;
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