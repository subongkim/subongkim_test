#include "Pizza.h"
#include "PizzaFactory.h"
class School : public Pizza								//Pizza에 대한 파생 클래스	
{

public:
	School();
	static Pizza* Create(Pizza*);
	static RegisterPizza rp;
	virtual void finish(int) override;
	virtual void Delivery(int) override;
	virtual void BasicTopping() override;
	virtual void MakeCheeze() override;
	virtual void MakeDough() override;
	virtual void Delete() override;
};
