#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <functional>
using namespace std;

int arr[241];
int solution(vector<int> people, int limit) {
	int answer = 0;
	/**/
	int l = 0, r = people.size() - 1;
	sort(people.begin(), people.end(), greater<int>());
	while (l < r)
	{
		if (people[l] + people[r] > limit)
		{
			l++;
		}
		else
		{
			l++;
			r--;
		}
		answer++;
	}
	if (l == r) answer++;*/
	for (int i = 0; i < people.size(); i++) arr[people[i]]++;

	for (int i = 0; i < people.size(); i++)
	{
		if (arr[people[i]] > 0)
		{
			answer++;
			arr[people[i]]--;
			int temp = limit - people[i];
			for (int j = temp; j > 0; j--)
			{
				if (arr[j] > 0) {
					arr[j]--;
					break;
				}
				
			}
		}
	}
	return answer;
}
int main()
{
	cout << solution({ 30, 70, 50, 80, 50 }, 130) << endl;
	return 0;
}