#include "Text.h"
using namespace std;
Text::Text()
{
	amount = 0;
	WordArray = NULL;
}

Text::Text(char* sen)
{
	int counter = 1;
	char temp[200] = "\0";
	int i = 0, j = 0, k = 0, len;
	for (i = 0; sen[i] != '\0'; i++)
	{
		if (sen[i] == ' ' && sen[i + 1] != '\0')
		{
			counter++;
		}
	}
	len = i;
	amount = counter;
	WordArray = new Word*[counter];
	i = 0;
	while (i <= len)
	{
		if (sen[i] != ' ' && sen[i]!='\0')
		{
			temp[j] = sen[i];
			i++;
			j++;
		}
		else if (sen[i] == ' ' || sen[i] == '\0' || sen[i] == '.')
		{
			temp[j] = '\0';
			WordArray[k] = new Word(temp, j);
			j = 0;
			i++;
			k++;
		}
	}
}

Text::~Text()
{
	/*for (int i = 0; i < amount; i++)
	{
		delete[] WordArray[i];
	}
	delete[] WordArray;*/
}


int Text::Getsize()
{
	return amount;
}

Word** Text::GetSen()
{
	return WordArray;


}

Text& Text:: operator &()
{
	int i = 0,j=0;
	char *rev;
	for (i = 0; i <= amount/2; i++)
	{
		rev = WordArray[i]->GetWord();
		WordArray[i]->Setword(WordArray[amount - 1 - i]->GetWord());
		WordArray[amount - 1 - i]->Setword(rev);	
	}
	return *this;
}

ostream& operator<<(ostream& out, const Text& obj)
{
	for (int i = 0; i < obj.amount; i++)
	{
		out << *obj.WordArray[i] << " ";
	}
	cout << endl;
	return out;
}

Text& Text::operator!()
{
	for (int i = 0; i < amount; i++)
	{
		!*WordArray[i];
	}
	return *this;
}

Text& Text::operator<<(int n)
{
	char *temp;
	n = n - 1;
	while (n >= 0)
	{
		temp = WordArray[0]->str;
		for (int i = 0;i<amount-1; i++)
		{
			WordArray[i]->Setword(WordArray[i + 1]->GetWord());
		}
		WordArray[amount-1]->Setword(temp);
		n--;
	}
	return *this;
}

Text& Text::operator>>(int n)
{
	char *temp;
	n = n - 1;
	while (n >= 0)
	{
		temp = WordArray[amount-1]->str;
		for (int i =amount-1 ; i>0; i--)
		{
			WordArray[i]->Setword(WordArray[i -1]->GetWord());
		}
		WordArray[0]->Setword(temp);
		n--;
	}
	return *this;
}

Text& Text::operator+=(int n)
{
	srand((unsigned)time(0));
	int i,j,size = rand() % 10 + 1;
	char* random = new char[size];
	char **help = NULL;
	help = new char*[amount + 1];
	for (i = 0; i < n; i++)
	{
		help[i] = WordArray[i]->GetWord();
	}
	for (j = 0; j < size; j++)
	{
		random[j]='A' + rand() % 26;
	}
	random[j] = '\0';
	help[i] = random;
	for (; i < amount; i++)
	{
		help[i + 1] = WordArray[i]->GetWord();
	}
	delete[]WordArray;
	amount++;
	WordArray = new Word*[amount];
	for (i = 0; i < amount; i++)
	{
		int len = coutLetters(help[i]);
		WordArray[i] = new Word(help[i],len);
		WordArray[i]->Setword(help[i]);
	}
	return *this;
}

int Text::coutLetters(char* str)
{
	int i;
	for (i = 0; str[i] != '\0'; i++);
	return i;
}


Text& Text::operator-=(int n)
{
	int i,j;
	char **help = new char*[amount];
	for (j=0,i = 0; i < amount; i++)
	{
		if (i != n)
		{
			help[j++] = WordArray[i]->GetWord();
		}
	}
	delete[]WordArray;
	amount--;
	WordArray = new Word*[amount];
	for (i = 0; i < amount; i++)
	{
		int len = coutLetters(help[i]);
		WordArray[i] = new Word(help[i], len);
		WordArray[i]->Setword(help[i]);
	}
	return *this;
}


Word& Text::operator[](int n)
{
	return *WordArray[n];
}
