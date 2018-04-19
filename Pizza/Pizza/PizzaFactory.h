#pragma once

class Pizza;
// 피자 가게
class PizzaFactory
{
public:
	// 피자 주문
	Pizza* OrderPizza(int);
};
