// 피자 관리자 고객

#include "OrderManager.h"
#include "MenuHandler.h"
class POS{
private:
	Order preset;		// 등록된 피자 목록
	MenuHandler handler;	// 메뉴관리

public:
	POS();

	void Run();
};