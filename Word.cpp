#include "Word.h"
using namespace std;

Word::Word()
{
	size_str = 0;
	str = NULL;
}
Word::Word(char* string, int s)
{
	size_str = s;
	str = new char[size_str+1];
	int i;
	for (i = 0; i < size_str; i++)
	{
		str[i] = string[i];
	}
	str[i] = '\0';
}

Word::~Word()
{
	
}

Word& Word::operator!()
{
	int num, diff;
	for (int i = 0; i < size_str; i++)
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			diff = str[i] - '0';
			num = 9 - diff;
			str[i] = num + '0';
		}
		else if (str[i] >= 'A' && str[i] <= 'Z')
		{
			num = str[i] - 'A';
			str[i] = 'z' - num;
		}

		else if (str[i] >= 'a' && str[i] <= 'z')
		{
			num = str[i] - 'a';
			str[i] = 'Z' - num;
		}
	}
	return *this;
}

Word& Word::operator&()
{
	int end = size_str - 1, i = 0;
	char *rev;
	rev = new char[size_str];
	while (end >= 0)
	{
		rev[i] = str[end];
		i++;
		end--;
	}
	for (int i = 0; i < size_str; i++)
	{
		str[i] = rev[i];
	}
	return *this;
}

Word& Word::operator<<(int n)
{
	while (n > 0)
	{
		int temp = str[0];//saving the first char in the string.
		for (int i = 0; i < size_str - 1; i++)//moving the string left.
		{
			str[i] = str[i + 1];
		}
		str[size_str - 1] = temp;//putting the first char int the last place of the string.
		n--;
	}
	return *this;
}

Word& Word::operator>>(int n)
{
	while (n > 0)
	{
		int temp = str[size_str - 1];//saving the last char in the string.
		for (int i = size_str - 1; i > 0; i--)//moving the string right.
		{
			str[i] = str[i - 1];
		}
		str[0] = temp;//putting in the first place the last char that I saved.
		n--;
	}
	return *this;
}

Word& Word::operator+=(int n)
{
	srand((unsigned)time(0));
	char *help = new char[size_str + 2];
	char c = 'A' + rand() % 26;
	int i;
	for (i = 0; i < n; i++)
	{
		help[i] = str[i];
	}
	help[i] = c;
	for (; i < size_str; i++)
	{
		help[i + 1] = str[i];
	}
	help[i + 1] = '\0';
	size_str = size_str + 1;
	delete[]str;
	str = new char[size_str + 1];
	for (i = 0; i < size_str + 1; i++)
	{
		str[i] = help[i];
	}
	return *this;
}

Word& Word::operator-=(int n)
{
	char *help = new char[size_str];
	int i;
	for (i = 0; i < n; i++)
	{
		help[i] = str[i];
	}
	if (i == n)
	{
		for (; i < size_str + 1; i++)
			help[i] = str[i + 1];
	}
	delete[]str;
	str = new char[size_str];
	for (i = 0; i < size_str; i++)
	{
		str[i] = help[i];
	}
	size_str--;
	return *this;
}

char& Word::operator[](int n)
{
	int mode = n% size_str;
	return str[mode];
}

ostream& operator <<(ostream&out, const Word& obj)
{
	out << obj.str;
	return out;
}

int Word::GetSize()
{
	return size_str;
}

char* Word::GetWord()
{
	return str;
}


void Word::Setword(char* temp)
{
	str = temp;
}



