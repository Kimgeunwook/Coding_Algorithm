#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int solution(string s)
{
	int answer = 1;
	for (int i = 0; i < s.size(); i++)
	{
		int temp = 0;
		for (int j = 1; j < s.size(); j++)
		{
			if (i - j < 0 || i + j >= s.size()) break;
			if (s[i - j] == s[i + j]) temp++;
			else break;
		}
		answer = max(answer, 2 * temp + 1);
	}

	for (int i = 0; i < s.size() - 1; i++)
	{
		int temp = 0;
		if (s[i] == s[i + 1])
		{
			for (int j = 1; j < s.size(); j++)
			{
				if (i - j < 0 || i + 1 + j >= s.size()) break;
				if (s[i - j] == s[i + 1 + j]) temp++;
				else break;
			}
			answer = max(answer, 2 * (temp + 1));
		}

	}


	return answer;
}