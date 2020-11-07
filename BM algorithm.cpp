#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <map>
#include <ctime>
#include "ReadFile.h"
#include "Search_Substring.h"
#include "StopTabCreate.h"
#include "SuffTabCreate.h"

using namespace std;

string search_str(string str)
{
	int size_str{int(str.length())};
	map<char, int>move_tab = StopTabForm(str);
	vector<int> suffshift = SuffTapForm(str, size_str);
	return search_answer(str, enter_file(0, size_str), size_str, move_tab, suffshift);
}

int main()
{
	string str{ "" };
	getline(cin, str);
	int time{clock()};
	str = search_str(str);
	time = clock() - time;
	cout << str << endl << time;
}