#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <set>
#include <vector>
#include <string>
using namespace std;

class Dictionary {

public:
	Dictionary();
	~Dictionary();
	string bringValidWord();
	bool isWordValid(string word);
private:
	set<string>words;
	vector<string>secrets;
	bool testLegalSecretWord(string word);
};

#endif