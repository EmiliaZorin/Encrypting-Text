#include "EncryptedText.h"
#include <iostream>
using namespace std;

int main()
{
	cout << "Enter a sentence:" << endl;
	char *temp=NULL;
	cin.getline(temp, 79);
	EncryptedText etext1(temp,0);
	int key1[] = { 3, -1, 4, 1, -1, 3, 1, 0, 4, 4, -1, 0, 5, -1, 0, -2 }; 
	cout << etext1; 
	etext1 += key1;
	cout << !etext1; 
	cout << "----------------------------------------------------------" << endl;
	EncryptedText etext2("RH oLMWLM gSV yIRGRZM tIVZG LU 3eCQ GZOXZKR.", 1);
	etext2 += key1;
	cout << etext2; 
	&etext2; 
	cout << etext2; 
	return 0;
}




