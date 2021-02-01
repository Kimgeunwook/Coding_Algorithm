#include <iostream>
using namespace std;
#include <queue>
#include <functional>
int small_people[10];
priority_queue<int, vector<int>, greater<int>> answer;
int main()
{
	int sum = 0;
	int a, b;
	for (int i = 1; i <= 9; i++)
	{
		cin >> small_people[i];
		sum += small_people[i];
	}
	for (int i = 1; i <= 9; i++)
		for (int j = 1; j <= 9; j++)
		{
			if (i == j)
				continue;
			else if (sum - small_people[i] - small_people[j] == 100)
			{
				a = i;
				b = j;
				break;
			}
		}
	for (int i = 1; i <= 9; i++)
	{
		if (i == a || i == b)
			continue;
		else
		{
			answer.push(small_people[i]);
		}
	}
	while (!answer.empty())
	{
		cout << answer.top() << endl;
		answer.pop();
	}

	return 0;
}
