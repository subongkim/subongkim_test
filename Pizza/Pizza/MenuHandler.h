#pragma once

#include "OrderManager.h"
#include "Pizza.h"
#include "PizzaFactory.h"
#include "Add.h"
#include "AddFactory.h"

class MenuHandler{
private:
	Order &preset;
	vector<Pizza*> pz;
	PizzaFactory* pf;
	AddFactory* af;

	vector<int> checkNum;
	static int pan;
	int topping_count_;
private:
	void AddOrder();
	bool AddPizza();
	bool ChooseTopping();
	void AddPizzaBrand();
	void AddTopping();
	void Make();
	void Bill();
public:
	MenuHandler(Order &preset);
	bool Run();
};
