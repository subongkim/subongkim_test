#include <iostream>
#include <string>

#include "MenuHandler.h"
using namespace std;
bool MenuHandler::AddPizza()
{
	bool yes_Or_No_;
	cout << "# [x]���� ����/[x]���� ����/[-]�߰� �ֹ�/[ ]�����" << endl;
	cout << "# �߰��� ���ڸ� �ֹ��Ͻ� �ǰ���?" << endl;
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