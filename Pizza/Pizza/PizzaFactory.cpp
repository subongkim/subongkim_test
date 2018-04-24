#include <iostream>
#include <map>
#include "Pizza.h"
#include "Domino.h"
#include "Mister.h"
#include "School.h"
#include "Chicken.h"
#include "Beef.h"
#include "Shrimp.h"
#include "PizzaFactory.h"

void PizzaFactory::Register(int num, Pizza*(*f)(Pizza*))
{
	create_map[num] = f;
}

Pizza* PizzaFactory::OrderPizza(int num)
{
	Pizza* pizza = NULL;
	auto ret = create_map.find(num);
	if (ret == create_map.end())
		return 0;
	pizza = create_map[num](nullptr);
	return pizza;
	/*if (num == 1)
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
	}*/
}

Pizza* PizzaFactory::OrderPizza(int num, Pizza* pz)
{
	num *= 10; //map�� �� ����� ���ڸ� �ٸ��� �ϱ� ���� ���(string�� �ް� �ϴ°� ����)
	Pizza* pizza = NULL;
	auto ret = create_map.find(num);
	if (ret == create_map.end())
		return nullptr;
	pizza = create_map[num](pz);
	return pizza;
	/*
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
	*/
}