#pragma once
#include <iostream>
#include <string>
#include <map>
using namespace std;

__interface IDoor
{
	void open();
	void close();
};

class Door : public IDoor
{
private:
	bool state;
public:
	void open() override
	{
		cout << "Door is open...\n";
		//state = true;
	}
	void close() override
	{
		state = false;
	}

	const bool& getStatus() const
	{
		return state;
	}
	void showStatus()
	{
		cout << "State door : " << state;
	}

};

class SecureProxy
{
private:
	Door* door;
	string pass_="admin",log_="admin";
public:
	SecureProxy() = default;
	SecureProxy(Door* door_) : door(door){}
	bool checkAccess(string log, string pass)
	{
		return this->log_ == log,this->pass_ == pass; 
	}
	void open()
	{
		string pass,log;
		cout << "Enter login : "; cin >> log;
		cout << "Enter password : "; cin >> pass;
		if (checkAccess(log, pass))
		{
			cout << "door open"; 
			door->open();
		}
	}
	void close()
	{
		door->close();
	}
	void showState()
	{
		door->getStatus();
	}
};