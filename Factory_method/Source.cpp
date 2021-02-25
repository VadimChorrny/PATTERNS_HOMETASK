#include <iostream>
using namespace std;
#include "Buttons.h"

int main()
{
	Dialog* dialog = new WindowsDialog();
	ClientCode(*dialog);
	cout << "________" << endl;
	Dialog* dialog_two = new HTMLDialog();
	ClientCode(*dialog_two);

}