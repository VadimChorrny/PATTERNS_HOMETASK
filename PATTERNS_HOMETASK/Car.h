#pragma once
#include <iostream>
#include "Builder.h"

struct Car
{
	Car() = default;
	bool gps;
	size_t amount;
	float engineVolume;
	void print() const
	{
		std::cout << "Car engine [" << engineVolume << "]\n";
		std::cout << "Car seats [" << amount << "]\n";
		std::cout << "Car gps [" << std::boolalpha << gps << "]\n";
	}
};