#include <iostream>
#include "Pizza.h"
#include "Domino.h"
#include "Mister.h"
#include "School.h"
#include "PizzaFactory.h"

Pizza* PizzaFactory::OrderPizza(int num)
{
	Pizza* pizza = NULL;
	if (num == 1)
	{
		return new Domino;
	}
	else if (num == 2)
	{
		return new Mister;
	}
	else if (num == 3)
	{
		return new School;
	}
}
