#include "Pizza.h"

class Domino : public Pizza								//Pizza�� ���� �Ļ� Ŭ����
{

public:
	Domino();
	virtual void finish(int) override;
	virtual void Delivery(int) override;
	virtual void BasicTopping() override;
	virtual void MakeCheeze() override;
	virtual void MakeDough() override;
	virtual void Delete() override;
};