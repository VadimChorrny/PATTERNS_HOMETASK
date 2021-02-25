#pragma once
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
class Message
{
public:

	Message(const string& message)
		:message_(message)
	{}
	friend ostream& operator<<(ostream& os, const Message& mess)
	{
		os << mess.message_ << endl;
		return os;
	}

private:
	string message_;
};

class LogMessage
{
public:
	//LogMessage(const LogMessage&) = delete; // заборона копіювати 
	//LogMessage& operator = (const LogMessage&) = delete; // заборона присвоювати
	void AddLogMessage(const Message& mess)
	{
		ofstream file("Message.txt", ios_base::app);
		if (file.is_open())
		{
			counter++;
			file << mess << endl;
		}
		else
			return;
		file.close();
	}
	static LogMessage* getInstance()
	{
		if (instance == nullptr)
		{
			instance = new LogMessage();
		}
		return instance;
	}
private:
	static LogMessage* instance; // singleton future
	size_t counter;
};

