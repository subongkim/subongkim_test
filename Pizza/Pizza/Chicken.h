#include "Add.h"

class Chicken : public Add								//Add Ŭ������ �Ļ� Ŭ����
{
public:
	Chicken(Pizza*);
	virtual void finish(int n) override;
	virtual void Delivery(int n) override;
	virtual void BasicTopping() override;
	//virtual void MakeCheeze() override{}
	//virtual void MakeDough() override{}
	virtual void Delete() override;
};