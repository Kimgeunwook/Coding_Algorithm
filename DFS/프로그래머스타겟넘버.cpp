#include <iostream>
#include <string>
#include <vector>
using namespace std;
int answer = 0;
int temp[20];
void dfs(vector<int> numbers, int cnt, int target)
{
	if (cnt == numbers.size())
	{
		int sum = 0;
		for (int i = 0; i < numbers.size(); i++) sum += temp[i] * numbers[i];
		if (sum == target) answer++;
	}
	else
	{
		for (int i = -1; i < 2; i++)
		{
			if (i == 0) continue;
			temp[cnt] = i;
			dfs(numbers, cnt + 1, target);
		}
	}
}
int solution(vector<int> numbers, int target) {
	dfs(numbers, 0, target);
	return answer;
}
int main()
{
	cout << solution({ 1,1,1,1,1 }, 3)<<endl;
	return 0;
}
