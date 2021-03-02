#include<iostream>
using namespace std;
#include "Doors.h"

int main()
{
	cout << "___________\n";
	Door door;
	SecureProxy proxy(&door);
	proxy.open();
	proxy.showState();
}