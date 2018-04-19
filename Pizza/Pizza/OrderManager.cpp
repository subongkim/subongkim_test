#include <iostream>
#include <vector>
#include <string>
#include "Add.h"
#include "OrderManager.h"

using namespace std;
Order::Order()
{
	pizzaBrand_ = 0, toppingNumber_ = 0;
	add_Topping_ = false;
}

void Order::AddBrand(string brand)
{
	pizza_list_.push_back(brand);
}
void Order::AddTopping(string topping)
{
	topping_list_.push_back(topping);
}
vector<string> Order::getBrandList()
{
	return pizza_list_;
}
vector<string> Order::getToppingList()
{
	return topping_list_;
}
void Order::clearToppingList()
{
	pick_topping_.clear();
}
vector<int> Order::getPickToppingList()
{
	return pick_topping_;
}
void Order::setPizzaBrand(int brand)
{
	pizzaBrand_ = brand;
	pick_brand_.push_back(brand);
}
void Order::setTopping(int topping)
{
	
	toppingNumber_ = topping;
	if (toppingNumber_ == 0)
	{
		add_Topping_ = false;
	}
	add_Topping_ = true;
	pick_topping_.push_back(topping);
}
int Order::get_add_Topping()
{
	return add_Topping_;
}
