#include <iostream>
#include <string>

#include "MenuHandler.h"
using namespace std;
void MenuHandler::Make()
{
	for (int i = 0; i < preset.getPickToppingList().size(); i++)
	{
		pz[pan] = af->MakeTopping(preset.getPickToppingList()[i], pz[pan]);
	}
	topping_count_ = 0; 
	
}