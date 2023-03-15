#include <iostream>
#include <fstream>
#include<string>
#include<set>
#include <vector>
#include<time.h>
#include "dictionary.h"
#include "words.h"
using namespace std;

Dictionary::Dictionary() {
	ifstream inFile;
	string str;

	inFile.open("words.txt");
	if (!inFile)
	{
		cout << "Input file could not be opened! Terminating!" << endl;
		exit(0);
	}

	inFile >> str;
	while (!inFile.eof())
	{
		words.insert(str);
		inFile >> str;
	}

	inFile.close();
}

Dictionary::~Dictionary() {}

string Dictionary::bringValidWord() {
	srand(time(NULL));

	for (set<string>::iterator it = words.begin(); it != words.end(); ++it)
	{
		if (testLegalSecretWord(*it))
		{
			secrets.push_back(*it);
		}
	}
	return secrets[rand() % secrets.size()];
}

bool Dictionary::isWordValid(string word) {
	if (words.count(word))
	{
		return true;
	}
	return false;
}

bool Dictionary::testLegalSecretWord(string word)
{
	for (int i = 0; i < word.length() - 1; i++) {
		for (int j = i + 1; j < word.length(); j++) {
			if (word[i] == word[j]) {
				return false;
			}
		}
	}
	return true;
}

Words::Words(Dictionary dio, string hiddenWord)
{
	diob = dio;
	secret = hiddenWord;
	count = 0;
	counter = 0;
	cheated = false;
	numguesses = 0;
}

Words::~Words() {}

void Words::playgame(Words &w) {

	cout << "Bilbakalim Oyununa Hosgeldiniz :\n"
		<< "5 harften olusan bir kelime tuttum.\n";

	while (1)
	{
		cout << "Tahmininiz Nedir? ";
		cin >> guess;

		if (guess == secret)
		{
			numguesses++;
			if (cheated == true)
			{
				cout << "Bildiniz! " << numguesses + 1 << " tahminde ipucu kullanarak dogru sonuca ulastiniz!";
			}
			else
			{
				cout << "Bildiniz! " << numguesses << " tahminde dogru sonuca ulastiniz!";
			}
			break;
		}

		if (guess == "xxxxx")
		{
			cout << "Ipucu: Gizli Kelime: " << secret << endl;
			cheated = true;
			continue;
		}

		if (diob.isWordValid(guess) == true)
		{
			cout << "Eslesen harf sayisi: " << countofMatchLetters(guess) << endl;
			cout << "Eslesen harflerin dogru konumu: " << countofTruePlaceLetters(guess) << endl;
			numguesses++;
		}
		else
		{
			cout << "Bu kelime sozlukte yok!\n";
		}
	}
}
int Words::countofMatchLetters(string guess) {
	count = 0;
	for (int i = 0; i < secret.size(); i++) {
		for (int j = 0; j < guess.size(); j++) {
			if (secret[i] == guess[j]) {
				count++;
				break;
			}
		}
	}
	return count;
}

int Words::countofTruePlaceLetters(string guess) {

	for (int i = 0; i < secret.size(); i++)
	{
		counter = 0;
		if (secret[i] == guess[i])
		{
			counter++;
		}
	}
	return counter;
}