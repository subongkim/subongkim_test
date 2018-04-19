#include <iostream>
#include <string>

#include "MenuHandler.h"
using namespace std;
bool MenuHandler::AddPizza()
{
	bool yes_Or_No_;
	cout << "# [x]피자 선택/[x]토핑 선택/[-]추가 주문/[ ]만들기" << endl;
	cout << "# 추가로 피자를 주문하실 건가요?" << endl;
	cout << "(1) Yes" << endl;
	cout << "(0) No" << endl;
	cout << endl;
	cout << ">> ";
	cin >> yes_Or_No_;
	if (yes_Or_No_ == true)
	{
		preset.clearToppingList();
	}
	return yes_Or_No_ == true ? true : false;
}