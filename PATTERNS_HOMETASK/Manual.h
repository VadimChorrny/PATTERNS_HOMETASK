#pragma once
#include <iostream>
#include "Builder.h"

struct Manual
{
	Manual() = default;
	bool m_gps;
	size_t m_amount;
	float m_engineVolume;
	void print() const
	{
		std::cout << "GPS off/on simple click" << std::boolalpha << m_gps << std::endl;
		std::cout << "In this car is - " << m_amount << "seats, Simple touch." << std::endl;
		std::cout << "Volume your engine , simple repair " <<  m_engineVolume << std::endl;
	}
};
