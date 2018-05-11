#pragma once
#include "Text.h"

class EncryptedText{
private:
	Text* Tptr;
	int status;
	int *key;
	int sizeKey;
public:
	friend class Text;
	EncryptedText();
	EncryptedText(char*, int);
	~EncryptedText();
	EncryptedText& operator+=(int*);
	EncryptedText& operator!();
	EncryptedText& operator&();
	friend ostream& operator<<(ostream&,const EncryptedText&);
};