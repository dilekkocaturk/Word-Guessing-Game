#include <iostream>
#include <fstream>
#include<string>
#include<set>
#include <vector>
#include<time.h>
#include "dictionary.h"
#include "words.h"
using namespace std;

int main() {

	Dictionary dico;

	Words wo(dico, dico.bringValidWord());
	wo.playgame(wo);

	cout << endl << endl;
	system("pause");
	return 0;
}