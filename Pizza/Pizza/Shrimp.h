#include "pizzaDecorator.h"
#include "PizzaFactory.h"
class Shrimp : public Add								//Add 클래스의 파생 클래스
{
public:
	static Pizza* Create(Pizza*);
	static RegisterPizza rp;
	Shrimp(Pizza*);
	virtual void finish(int n) override;
	virtual void Delivery(int n) override;
	virtual void BasicTopping() override;
	//virtual void MakeCheeze() override{}
	//virtual void MakeDough() override{}
	virtual void Delete() override;
};