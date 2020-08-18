//16:27½ÃÀÛ
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int solution(int distance, vector<int> rocks, int n) {
	int answer = 0;
	int remove = 0;
	int lastRock = 0;
	int l = 0, r = distance;
	sort(rocks.begin(), rocks.end());
	rocks.push_back(distance);
	while (l <= r)
	{
		remove = lastRock = 0;
		int mid = (l + r) / 2;
		for (int i = 0; i < rocks.size(); i++)
		{
			if (rocks[i] - lastRock < mid) remove++;
			else lastRock = rocks[i];
		}

		if (remove > n) r = mid - 1;
		else {
			answer = max(answer, mid);
			l = mid + 1;
		}
	}

	return answer;
}
int main()
{
	cout << solution(25, {2, 14, 11, 21, 17}, 2) << endl;
	return 0;
}
