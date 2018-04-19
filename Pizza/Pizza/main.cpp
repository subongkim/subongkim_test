#include <iostream>
#include "POS.h"
using namespace std;

#ifndef _DEBUG	// vc

#define new new(_CLIENT_BLOCK,__FILE__,__LINE)

#endif

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	POS start;
	start.Run();
	return 0;
}
