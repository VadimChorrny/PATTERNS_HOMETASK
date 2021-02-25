#include <iostream>
#include "Builder.h"

int main()
{
	CarBuilder carBuilder;
	Director director(&carBuilder);
	director.make(CarType::ORDINARY);

	Car* car = carBuilder.getResult();
	car->print();

	director.make(CarType::SPORT);

	Car* car2 = carBuilder.getResult();
	car2->print();



	delete car;
}

