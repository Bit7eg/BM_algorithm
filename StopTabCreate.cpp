#include <iostream>
#include <iomanip>
#include <string>
#include <map>
using namespace std;

map<char, int>StopTabForm(string str)
{
	map<char, int>StopTab;
	for (int i{ 0 }; i < str.length() - 1; ++i)
	{
		StopTab[str[i]] = i + 1;
	}
	return StopTab;
}