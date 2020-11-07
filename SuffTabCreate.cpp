#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
using namespace std;

vector<int> SuffTapForm(string str, int size_str)
{
	vector<int> suffshift(size_str + 1);
	for (int i{0}; i <= size_str; ++i)
	{
		for (int j{ size_str - 2 }, k{ 0 }; j >= -1; --j)
		{
			for (k = 0; k < i; ++k)
			{
				if (j - k < 0)
				{
					k = i;
					break;
				}
				else
				{
					if (str[j - k] != str[size_str - 1 - k])
					{
						break;
					}
				}
			}
			if (k == i)
			{
				if (j - i < 0)
				{
					suffshift[size_str - i] = size_str - j - 1;
					break;
				}
				else if (str[j - i] != str[size_str - 1 - i])
				{
					suffshift[size_str - i] = size_str - j - 1;
					break;
				}
			}
		}
	}
	return suffshift;
}