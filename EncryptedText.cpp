#include "EncryptedText.h"

EncryptedText::EncryptedText()
{
	Tptr = NULL;
	sizeKey = 0;
	key = NULL;
}


EncryptedText::EncryptedText(char* T, int s)
{
	Tptr = new Text(T);
	status = s;
}

EncryptedText::~EncryptedText()
{
}


EncryptedText& EncryptedText::operator+=(int* k)
{
	int size=0;
	for (int i = 0; k[i] != -2; i++)
	{
		size++;
	}
	sizeKey = size;
	key = new int(sizeKey);
	for (int i = 0; i < sizeKey; i++)
	{
		key[i] = k[i];
	}
	return *this;
}

EncryptedText& EncryptedText::operator!()
{
	if (status == 0)
	{
		for (int i = 0; i <= sizeKey-3; i += 3)
		{
			int code = i;
			int spesific = i + 1;
			int place = i + 2;
			switch (key[code])
			{
			case 1: 
					if (key[spesific] == -1) 
						*Tptr << key[place];
					else
						(*Tptr)[key[spesific]] << key[place];
					break;
			case 2:
				if (key[spesific] == -1)
					*Tptr >> key[place];
					else
						(*Tptr)[key[spesific]] >> key[place];
					break;
			case 3:
					if (key[spesific] == -1)
						*Tptr += key[place];
					else
						(*Tptr)[key[spesific]] += key[place];
					break;
			case 4: 
					if (key[spesific] == -1)
						!*Tptr;
					else
						!(*Tptr)[key[spesific]];
					break;
			case 5: 
					if (key[spesific] == -1)
						&*Tptr;
					else
						& !(*Tptr)[key[spesific]];
					break;
			default:
				break;
			}
		}
	}
	else if (status == 1)
		return *this;
	return *this;
}

EncryptedText& EncryptedText::operator&()
{
	if (status == 0)
	{
		for (int i = sizeKey - 3;i>=0 ; i -= 3)
		{
			int code = i;
			int spesific = i + 1;
			int place = i + 2;
			switch (key[code])
			{
			case 1:
				if (key[spesific] == -1)
					*Tptr >> key[place];
				else
					(*Tptr)[key[spesific]] << key[place]-1;
				break;
			case 2:
				if (key[spesific] == -1)
					*Tptr << key[place];
				else
					(*Tptr)[key[spesific]] >> key[place];
				break;
			case 3:
				if (key[spesific] == -1)
					*Tptr -= key[place];
				else
					(*Tptr)[key[spesific]] += key[place];
				break;
			case 4:
				if (key[spesific] == -1)
					!*Tptr;
				else
					!(*Tptr)[key[spesific]];
				break;
			case 5:
				if (key[spesific] == -1)
					&*Tptr;
				else
					& !(*Tptr)[key[spesific]];
				break;
			default:
				break;
			}
		}
	}
	else if (status == 1)
		return *this;
	return *this;

}

ostream& operator<<(ostream&out, const EncryptedText&obj)
{
	out << *obj.Tptr;
		return out;
}