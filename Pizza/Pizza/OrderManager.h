#pragma once
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Order										
{
	int pizzaBrand_, toppingNumber_;
	bool add_Topping_;
	vector<int> checkNumber_;
	vector<string> pizza_list_;
	vector<string> topping_list_;
	vector<int> pick_brand_;
	vector<int> pick_topping_;

public:
	Order();
	void AddBrand(string brand);
	void AddTopping(string topping);
	void clearToppingList();
	vector<string> getBrandList();
	vector<string> getToppingList();
	vector<int> getPickToppingList();
	int get_add_Topping();
	void setPizzaBrand(int);
	void setTopping(int);
	
};
using OrderPreset = Order;