#include "pizzaDecorator.h"
#include "PizzaFactory.h"
class Beef : public Add									//Add Ŭ������ �Ļ� Ŭ����
{
public:
	static Pizza* Create(Pizza*);
	static RegisterPizza rp;
	Beef(Pizza *);
	virtual void finish(int n) override;
	virtual void Delivery(int n) override;
	virtual void BasicTopping() override;
	//virtual void MakeCheeze() override{}
	//virtual void MakeDough() override{}
	virtual void Delete() override;
};