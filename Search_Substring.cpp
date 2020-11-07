#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <map>
#include "ReadFile.h"
using namespace std;

string search_answer(string str, string text, int size_str, map<char, int>Stop_Tab, vector<int> suffshift)
{
	string answer{ "" };
	for (int i = 0, j = 0; text != "";)
	{
		for (j = size_str - 1; j >= 0 && str[j] == text[j]; j--);
		if (j < 0)
		{
			return answer;
		}
		else
		{
			if (suffshift[j + 1] > j - Stop_Tab[text[j]] + 1)
			{
				answer += to_string(suffshift[j + 1]) + " ";
				i += suffshift[j + 1];
			}
			else
			{
				answer += to_string(j - Stop_Tab[text[j]] + 1) + " ";
				i += j - Stop_Tab[text[j]] + 1;
			}
		}
		text = enter_file(i, size_str);
	}
	return "The given string does not contain the given substring";
}