#pragma once
#include <iostream>
using namespace std;
#include <string>
#include <thread>
#include <chrono>

#define CLEEN system("cls");

class Clock24
{
public:
	Clock24() = default;
	void updateHour(const size_t& hour)
	{
		if (hour > 24)
		{
			throw exception("error with add hours...");
		}
		else if (hour <= 24)
		{
			cout << "Update hours ... " << hour << endl;
			this->hour = hour;
		}
	}
	void updateMinute(const size_t& minute)
	{
		if (minute > 60)
		{
			throw exception("error with add minute...");
		}
		else if (minute <= 60)
		{
			cout << "Update minute ... " << minute << endl;
			this->minute = minute;
		}
	}
	void addOneHour()
	{
		if (hour <= 23)
		{
			this->hour++;
		}
		else
		{
			throw exception("in clock dont more 24!!!");
		}
	}
	// upgrade Tick()
	void addOneMinute()
	{
		if (hour <= 23 && minute <= 58)
		{
		this->minute++;
		}
		else if (minute >= 59 && minute < 60 && hour < 23) 
		{
			this->hour++;
		}
		else
		{
			throw exception("in clock dont more 60 minute!!!");
		}
	}
	void show() const
	{
		this_thread::sleep_for(chrono::milliseconds(3000));
		CLEEN;
		cout << "Time - hour -> [" << hour << ":" << minute << "] <- minute\n";
	}
private:
	size_t hour = 0,minute = 0;
};

__interface IClock12
{
	void updateHour(const size_t& hour);
	void updateMinute(const size_t& minute);
	void addOneHour();
	void addOneMinute();
};

class Clock12 : public IClock12,protected Clock24
{



private:
	Clock24* clock;
};

