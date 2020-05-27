#define _CRT_SECURE_NO_WARNINGS
#include "Data.h"

//C'tor
Data::Data(int id, char* name)
{
	if (!setName(name))
	{
		exit(-1);
	}
	setId(id);
}

//A function that checks is the name is valid according to format we got: first name - space - last name.
bool validName(char* name)
{
	bool space = false, first = false, last = false;
	int  i = 0;

	while (name[i] == ' ')
		i++;

	while (name[i] != '\0')
	{
		if (isalpha(name[i]))
		{
			if (!first)
			{
				first = true;
			}
			else
			{
				if (space && !last)
					last = true;
			}
		}
		else if (name[i] == ' ' && first && !last && !space)
			space = true;
		else
			return false;
		i++;
	}
	if (first && last && space)
		return true;
	else
		return false;
}

//Set id
bool Data::setId(int id)
{
	this->id = id;
	return true;
}

//Set name
bool Data::setName(char* name)
{
	if (validName(name))
	{
		strcpy(this->name, name);
		return true;
	}
	else
		return false;
}

//print methos
void Data::print()
{
	cout << this->id << this->name << endl;
}