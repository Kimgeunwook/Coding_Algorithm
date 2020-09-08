//1552½ÃÀÛ
#include <iostream>
#include <string>
#include <vector>
using namespace std;
#define MAX 1e+18
long long solution(int n, vector<int> times) {
	long long answer = 0;
	long long s = 0, e = MAX ;

	while (s <= e)
	{
		long long mid = (s + e) / 2;
		long long temp = 0;
		for (int i = 0; i < times.size(); i++)
			temp += mid / times[i];
		
		if (temp >= n)
		{
			answer = mid;
			e = mid - 1;
		}
		else s = mid + 1;
	}

	return answer;
}
int main()
{
	cout << solution(6, { 7, 10 }) << endl;
	return 0;
}
