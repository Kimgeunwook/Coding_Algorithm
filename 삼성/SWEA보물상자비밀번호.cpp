//1243시작
#include <iostream>
#include <string>
#include <algorithm>
#include <functional>
#include <vector>
using namespace std;
int N, K;
string str;
vector<int> v_s;
void init()
{
	cin >> N >> K;
	cin >> str;
	v_s.clear();
}
void rotate()
{
	char temp = str[str.size() - 1];
	str = temp + str.substr(0, str.size() - 1);
}
void add()
{
	int unit = N / 4;
	for (int i = 0; i < 4; i++)
	{
		string temp = str.substr(0 + i * unit, unit); //넣을 문자열 생성
		int pushnum = 0;
		for (int k = 0; k < unit; k++)
		{
			if (temp[temp.size() - 1 - k] - '0' >= 10)
			{
				pushnum += pow(16, k) * (10 + temp[temp.size() - 1 - k] - 'A');
			}
			else
			{
				pushnum += pow(16, k) * (temp[temp.size() - 1 - k] - '0');
			}
			
		}
		bool flag = true;
		for (int j = 0; j < v_s.size(); j++) //이미 나온앤지 검사
		{
			if (v_s[j] == pushnum) flag = false;
		}

		if (flag)
		{
			v_s.push_back(pushnum); //안나왔으면 넣기
		}
	}
}
void solve()
{
	for (int i = 0; i <  N / 4; i++)
	{
		rotate();
		add();
	}
}
int main()
{
	int T; cin >> T;
	for (int i = 1; i <= T; i++)
	{
		init();
		solve();
		sort(v_s.begin(), v_s.end(), greater<int>());
		cout << "#" << i << " " << v_s[K - 1] << endl;
	}
	return 0;
}