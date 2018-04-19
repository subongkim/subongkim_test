#include <iostream>
#include "Add.h"
#include "Chicken.h"
#include "Beef.h"
#include "Shrimp.h"
#include "AddFactory.h"

using namespace std;

Pizza* AddFactory::MakeTopping(int num, Pizza* pz)
{
	if (num == 1)
	{
		return new Chicken(pz);
	}
	else if (num == 2)
	{
		return new Beef(pz);
	}
	else if (num == 3)
	{
		return new Shrimp(pz);
	}
}