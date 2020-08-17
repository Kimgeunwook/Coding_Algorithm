//1630½ÃÀÛ
#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> solution(vector<int> prices) {
	vector<int> answer;
	for (int i = 0; i < prices.size(); i++)
	{
		int cur = prices[i];
		int temp = 0;
		if (i == prices.size() - 1) break;
		for (int j = i + 1; j < prices.size(); j++)
		{
			if (prices[j] >= cur) temp++;
			else {
				temp++;
				break;
			}
		}
		answer.push_back(temp);
	}
	answer.push_back(0);
	return answer;
}
int main()
{
	solution({ 1,2,3,2,3 });
	return 0;
}
