//2103Ω√¿€
#include <iostream>
#include <vector>
using namespace std;

int solution(int n, vector<int> stations, int w)
{
	int answer = 0;

	int curmax = 1;
	stations.push_back(n + w + 1);
	for (int i = 0; i < stations.size(); i++)
	{
		if (curmax < stations[i] - w)
		{
			int len = stations[i] - w - curmax;
			int firstdivide = len / (2 * w + 1);
			int firsttemp = len % (2 * w + 1);
			if (firsttemp != 0) firstdivide++;
			answer += firstdivide;
		}

		curmax = stations[i] + w + 1;
		if (curmax > n) break;
	}
	return answer;
}