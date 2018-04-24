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
	num *= 10; //map을 쓴 관계로 숫자를 다르게 하기 위해 사용(string을 받게 하는게 정상)
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