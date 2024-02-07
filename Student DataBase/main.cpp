// Standard (system) header files
#include <iostream>
#include <cstdlib>
#include "StudentDb.h"
#include "SimpleUI.h"

using namespace std;

int main()
{
	/* Creating DataBase Object for storing data*/
	StudentDb DataBase1;

	/* Creating SimpleUI Object  for User Interaction */
	SimpleUI simpleui(DataBase1);

	/* Run the DataBase */
	simpleui.run();

	return 0;
}
