#pragma once
#include "Car.h"
#include "Manual.h"
__interface IBuilder
{
	void reset(); // start of building
	void setEngine(float volume);
	void setSeats(size_t amount);
	void setGPS(bool exists);

};
class Car;

class CarBuilder : public IBuilder
{
	Car* car;
public:
	void reset()
	{
		car = new Car();
	}
	void setEngine(float value)
	{
		car->engineVolume = value;
	}
	void setSeats(size_t amount)
	{
		car->amount = amount;
	}
	void setGPS(bool exists)
	{
		car->gps = exists;
	}
	Car* getResult()
	{
		return car;
	}
};

class ManualBuilder
{
	Manual* manual;
public:
	void reset()
	{
		manual = new Manual();
	}
	void setEngine(float value)
	{
		manual->m_engineVolume = value;
	}
	void setSeats(size_t amount)
	{
		manual->m_amount = amount;
	}
	void setGPS(bool exists)
	{
		manual->m_gps = exists;
	}
	Manual* getResult()
	{
		return manual;
	}

};



enum class CarType { SPORT, ORDINARY };

class Director
{
public:
	Director(IBuilder* builder) : builder(builder) {};
	void make(CarType type)
	{
		builder->reset();
		if (type == CarType::SPORT)
		{
			builder->setEngine(3.5);
			builder->setSeats(2);
		}
		else if (type == CarType::ORDINARY)
		{
			builder->setEngine(2.0f);
			builder->setSeats(4);
			builder->setGPS(true);
		}
		else
			throw std::exception("bed type of car");

	}
private:
	IBuilder* builder;
};