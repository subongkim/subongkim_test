#include <iostream>
#include <string>
#include "Pizza.h"

#pragma once

using namespace std;

class Add : public Pizza								//�߰��� Ŭ����
{
protected:
	Pizza* pz;
public:
	Add(Pizza*);
	virtual void Delivery(int n) override;
	virtual void finish(int n) override;
	virtual void BasicTopping() override;
	virtual void MakeCheeze() override;
	virtual void MakeDough() override;
	virtual void Delete() override;
};


