#pragma once
#include <iostream>
using namespace std;
#include <list>
class Word
{
	string engWord,uaWord;
};

class CollectionWord : public Word
{
private:
	list<Word> words;
public:
	void AddWord(Word word1, Word word2)
	{
		this->words.push_back(word1);
		this->words.push_back(word2);
	}	

	void DeleteWord(const string& s)
	{
		list<Word>::iterator it = find(begin(words), end(words), s);
		words.erase(it);
	}



};

