#include <iostream>
#include <string>

#include "MenuHandler.h"

using namespace std;
void MenuHandler::Bill()
{
	cout << "# [x]���� ����/[x]���� ����/[x]�߰� �ֹ�/[-]�����" << endl;
	enum pizzaBrand { domino = 1, mister, school };
	for (int i = 0; i <= pan; i++)
	{
		pz[i]->MakeDough();
		cout << "# �丶�� �ҽ��� �ٸ��� ��..." << endl;
		pz[i]->MakeCheeze();
		pz[i]->BasicTopping();
		cout << "# ���� ��..." << endl;
		pz[i]->finish(checkNum[i]);
		cout << "�� ���ڰ� �ϼ��Ǿ����ϴ�!" << endl;
	}
	cout << "# ��� ��..." << endl;
	for (int i = 0; i <= pan; i++)
	{
		pz[i]->Delivery(checkNum[i]);
		cout << "�� ���ڰ� ��޵Ǿ����ϴ�!" << endl;
	}
	
	for (int i = 0; i <= pan; i++)
	{
		pz[i]->Delete();
		delete[] pz[i];
	}
	pz.clear();	
}