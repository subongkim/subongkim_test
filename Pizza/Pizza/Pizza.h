#include <iostream>
#include <string>

using namespace std;

#pragma once

class Pizza												//Abstract class
{
protected:
	string name;
public:
	virtual ~Pizza() = default;
	virtual void BasicTopping(){}
	virtual void MakeCheeze(){}
	virtual void MakeDough(){}
	virtual void finish(int){}
	virtual void Delivery(int){}
	virtual void Delete(){}
};


