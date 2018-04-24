#pragma once

#include "OrderManager.h"
#include "Pizza.h"
#include "PizzaFactory.h"
#include "pizzaDecorator.h"

class MenuHandler{
private:
	Order &preset;
	vector<Pizza*> pz;
	//PizzaFactory* pf;
	//AddFactory* af;
	vector<int> checkNum;
	static int pan;
	int topping_count_;
private:
	void AddOrder();
	bool AddPizza();
	bool ChooseTopping();
	void Make();
	void Bill();
	string change(int a)
	{
		if (a == 1)
		{
			return "domino";
		}
	}
		
public:
	MenuHandler(Order &preset);
	bool Run();
};
