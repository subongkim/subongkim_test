#pragma once

class Pizza;
class Add;

class AddFactory
{
private:
public:
	Pizza* MakeTopping(int,Pizza*);
};