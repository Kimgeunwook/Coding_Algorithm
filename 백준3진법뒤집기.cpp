#include <iostream>
#include <string>
#include <vector>
#include<cmath>
using namespace std;
int get_initnum(int n)
{
	if (n < 3) return 0;
	int cnt = 0;
	int ret = 1;
	while (1)
	{
		if (ret > n) break;
		ret *= 3;
		cnt++;
	}
	return cnt - 1;
}
int solution(int n) {
	int answer = 0;
	string str = "";
	int num = n;
	for (int i = get_initnum(n); i >= 0; i--)
	{
		if (num == 0)
		{
			str += "0";
			continue;
		}
		int divide_num = pow(3, i);
		str += to_string(num / divide_num);
		num -= (num / divide_num) * divide_num;
	}
	for (int i = str.size() - 1; i >= 0; i--)
	{
		answer += (str[i] - '0') * pow(3, i);
	}
	
	return answer;
}

int main()
{
	cout << solution(1) << endl;
	cout << solution(2) << endl;
	cout << solution(3) << endl;
	cout << solution(4) << endl;
	return 0;
}