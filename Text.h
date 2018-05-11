#pragma once
#include <iostream>
#include "Word.h"
using namespace std;
class Text {
private:
	int amount;
	Word** WordArray;
public:
	Text();
	Text(char*);
	~Text();
	Text& operator!();
	friend ostream& operator <<(ostream&, const Text&);
	int Getsize();
	Word** GetSen();
	Text& operator &();
	Text& operator<<(int);
	Text& operator>>(int);
	Text& operator +=(int);
	Text& operator -=(int);
	Word& operator [](int);
	int coutLetters(char*);
};

