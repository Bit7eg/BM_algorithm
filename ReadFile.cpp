#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
using namespace std;

string enter_file(int symb, int size)
{
	char ch{ 0 };
	string text{ "" };
	ifstream fin("input_substr_search.txt");
	if (fin.is_open())
	{
		for (int i{0}; i < symb && !fin.eof(); ++i)
		{
			ch = fin.get();
		}
		for (int i{0}; i < size && !fin.eof(); ++i)
		{
			ch = fin.get();
			text.insert(text.end(), ch);
			if (text[i]=='\n')
			{
				text.erase(i, 1);
				--i;
				if (i >= 0 && text[i]=='-')
				{
					text.erase(i, 1);
					--i;
				}
				else if (i >= 0 && text[i] != ' ')
				{
					text.insert(text.end(), ' ');
				}
			}
		}
		if (fin.eof() && text.length() < size)
		{
			return "";
		}
	}
	fin.close();
	return text;
}