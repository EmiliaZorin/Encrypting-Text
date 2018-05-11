#pragma once
#include <iostream>
#include <time.h>
#include <assert.h>
using namespace std;

class Word {
private:
	char *str;
	int size_str;
public:
	friend class Text;
	Word();
	Word(char*, int);
	~Word();
	Word& operator !();
	Word& operator &();
	Word& operator <<(int);
	Word& operator >>(int);
	Word& operator +=(int);
	Word& operator -=(int);
	char& operator [](int);
	friend ostream& operator<<(ostream& out, const Word& obj);
	int GetSize();
	char* GetWord();
	void Setword(char*);

};
