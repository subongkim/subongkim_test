#pragma once
#include <string>
#include <map>
class Pizza;

class PizzaFactory
{
	map<int, Pizza*(*)(Pizza*)> create_map;
public:
	void Register(int, Pizza*(*f)(Pizza*));
	static PizzaFactory& getInstance()
	{
		static PizzaFactory instance;
		return instance;
	}
	Pizza* OrderPizza(int);
	Pizza* OrderPizza(int, Pizza* pz);
};
struct RegisterPizza
{
	RegisterPizza(int num, Pizza*(*f)(Pizza*))
	{
		PizzaFactory& factory = PizzaFactory::getInstance();
		factory.Register(num, f);
	}
};