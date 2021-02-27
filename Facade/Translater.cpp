#include "Translater.h"
#include <list>
#include <iostream>
using namespace std;

class Word
{
	string en, ua;
public:
	Word(string& en, string ua) : en(en), ua(ua) {}
};

class CollectionWord : public Word
{
private:
	list<Word> words;
	list<Word>::iterator it;
public:
	void AddWord(Word w)
	{
		this->words.push_back(w);
	}
	void DeleteWord(string s)
	{
		it = find(begin(words), end(words), s);
		if (it != end(words))
		{
			words.erase(it);
		}
		else
		{
			cerr << "Words dont find!" << endl;
		}
	}
	void ShowAllWords()
	{
		for (auto& i : words)
		{
			i;
		}
	}
};

class Facade : public Word
{
private:
	CollectionWord* words_ = nullptr;
public:
	Facade(CollectionWord* words) :words_(words) {}
	~Facade() { delete words_; }

	string Operation()
	{
	}




};