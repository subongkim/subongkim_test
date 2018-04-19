#include <iostream>
#include "POS.h"

using namespace std;

POS::POS() : handler(preset)
{	//기본 브랜드와 기본 토핑 셋팅
	preset.AddBrand("도미노피자");
	preset.AddBrand("미스터피자");
	preset.AddBrand("피자 스쿨");

	preset.AddTopping("닭가슴살");
	preset.AddTopping("불고기");
	preset.AddTopping("새우");
}

void POS::Run()
{
	cout << "## 피자 주문 ##" << endl;
	while(handler.Run());
}