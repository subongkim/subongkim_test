#include <iostream>
#include "POS.h"

using namespace std;

POS::POS() : handler(preset)
{	//�⺻ �귣��� �⺻ ���� ����
	preset.AddBrand("���̳�����");
	preset.AddBrand("�̽�������");
	preset.AddBrand("���� ����");

	preset.AddTopping("�߰�����");
	preset.AddTopping("�Ұ��");
	preset.AddTopping("����");
}

void POS::Run()
{
	cout << "## ���� �ֹ� ##" << endl;
	while(handler.Run());
}