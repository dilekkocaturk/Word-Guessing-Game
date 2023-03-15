#ifndef WORDS_H
#define WORDS_H

#include <set>
#include <vector>

#include "dictionary.h"
#include <string>
using namespace std;

class Words {
public:
	Words(Dictionary dio, string hiddenWord);
	~Words();
	void playgame(Words &w);
private:
	int countofMatchLetters(string guess);
	int countofTruePlaceLetters(string guess);
	int numguesses;
	bool cheated;
	string secret;

	Dictionary diob;
	string guess;
	int counter;
	int count;

};

#endif