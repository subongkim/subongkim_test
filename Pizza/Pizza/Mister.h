#include "Pizza.h"

class Mister : public Pizza								//Pizza�� ���� �Ļ� Ŭ����
{

public:
	Mister();
	virtual void finish(int) override;
	virtual void Delivery(int) override;
	virtual void BasicTopping() override;
	virtual void MakeCheeze() override;
	virtual void MakeDough() override;
	virtual void Delete() override;
};