#include <iostream>

int Add1(int a, int b) { return a + b; }
inline int Add2(int a, int b) { return a + b; }

int main()
{
	int n1 = Add1(1, 2);	//ȣ��
	int n2 = Add2(1, 2);	//ġȯ

	int(*f)(int, int);

	f = &Add2;

	int n3 = f(1, 2);	//�Լ������Ϳ� ��Ƽ� ����ϸ� 'ġȯ'��� 'ȣ��'�� ��.
						//�����Ϸ��� �ƴ� ���� f�� �Լ������� ������� �˱� ������. 
						//���� �Լ������� '����'�̱⿡ �����Ͻð��� ���� �� ���µ��� ����
						//�ζ����Լ��� �����Ͻð��� �����ϱ⶧����.
	return 0;
}

