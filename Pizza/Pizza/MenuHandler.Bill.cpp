#include <iostream>
#include <string>

#include "MenuHandler.h"

using namespace std;
void MenuHandler::Bill()
{
	cout << "# [x]피자 선택/[x]토핑 선택/[x]추가 주문/[-]만들기" << endl;
	enum pizzaBrand { domino = 1, mister, school };
	for (int i = 0; i <= pan; i++)
	{
		pz[i]->MakeDough();
		cout << "# 토마토 소스를 바르는 중..." << endl;
		pz[i]->MakeCheeze();
		pz[i]->BasicTopping();
		cout << "# 굽는 중..." << endl;
		pz[i]->finish(checkNum[i]);
		cout << "의 피자가 완성되었습니다!" << endl;
	}
	cout << "# 배달 중..." << endl;
	for (int i = 0; i <= pan; i++)
	{
		pz[i]->Delivery(checkNum[i]);
		cout << "의 피자가 배달되었습니다!" << endl;
	}
	
	for (int i = 0; i <= pan; i++)
	{
		pz[i]->Delete();
		delete[] pz[i];
	}
	pz.clear();	
}