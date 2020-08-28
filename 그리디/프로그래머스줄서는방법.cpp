//1951Ω√¿€
#include <iostream>
#include <string>
#include <vector>
using namespace std;
vector<int> v;
long long factorial(int n)
{
	if (n == 1) return 1;
	else return n * factorial(n - 1);
}
vector<int> solution(int n, long long k) {
	vector<int> answer;
	for (int i = 1; i <= n; i++) v.push_back(i);
	while (1)
	{
		if (v.size() == 0) break;
		if (k == 1)
		{
			answer.push_back(v[0]);
			v.erase(v.begin());
			continue;
		}
		long long num = k / factorial(v.size() - 1);
		long long rest = k % factorial(v.size() - 1);
		
		if (rest == 0)
		{
			num -= 1;
			rest = factorial(v.size() - 1);
		}
		answer.push_back(v[num]);
		v.erase(v.begin() + num);
		k = rest;
	}
	return answer;
}
int main()
{
	solution(3, 5);
	return 0;
}