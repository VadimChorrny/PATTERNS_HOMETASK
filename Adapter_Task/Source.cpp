#include <iostream>
#include "Clock.h"

int main()
{
	try
	{
		// review Clock24
		Clock24 clok;
		clok.updateHour(21);
		clok.updateMinute(59);
		clok.show();
		cout << "-----------" << endl;
		CLEEN;
		clok.addOneHour();
		clok.addOneMinute();
		clok.addOneMinute();
		clok.show();
	}
	catch (const std::exception& e) 
	{
		cerr << e.what() << endl;
	}
}