// ���� ������ ��

#include "OrderManager.h"
#include "MenuHandler.h"
class POS{
private:
	Order preset;		// ��ϵ� ���� ���
	MenuHandler handler;	// �޴�����

public:
	POS();

	void Run();
};