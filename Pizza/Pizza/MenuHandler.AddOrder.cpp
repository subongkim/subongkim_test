#include <iostream>
#include <string>


#include "MenuHandler.h"

using namespace std;
void MenuHandler::AddOrder()
{
	pan++;
	int pizzaBrand_;
	cout << "# [-]피자 선택/[ ]토핑 선택/[ ]추가 주문/[ ]만들기" << endl;
	cout << "# 원하시는 피자를 선택해주세요." << endl;
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