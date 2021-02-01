//1306Ω√¿€
#include <vector>
using namespace std;
bool visit[200001];
int solution(vector<int> nums)
{
	int answer = 0;
	for (int i = 0; i<nums.size(); i++)
	{
		if (!visit[nums[i]])
		{
			visit[nums[i]] = true;
			answer++;
		}
	}
	if (answer >= nums.size() / 2) answer = nums.size() / 2;
	return answer;
}