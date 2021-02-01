#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;
set<char> _s;
string s[10];
vector<char> v;
int N;
int arr[10];
int visit[10];
int temp[10];
int alphabet[26];
int ans = 0;
void dfs(int cnt)
{
	if (cnt == v.size())
	{
		//각 알파벳마다 숫자 부여
		for (int i = 0; i < v.size(); i++)
			alphabet[v[i] - 'A'] = temp[i];

		int sum = 0;
		for (int i = 0; i < N; i++)
		{
			int len = s[i].length();
			int res = 0;
			for (int j = 0; j < len; j++)
			{
				res = res * 10 + alphabet[s[i][j] - 'A']; //문자열 길이만큼 돌면서 숫자 만들기...아이디어 미쳤따!
			}
			sum += res;
		}
		if (sum > ans) ans = sum;
	}
	else
	{
		for (int i = 0; i < v.size(); i++)
		{
			if (visit[i] == 1)continue;
			visit[i] = 1;
			temp[cnt] = arr[i];
			dfs(cnt + 1);
			visit[i] = 0;
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < 10; i++)
		arr[i] = 9 - i;

	for (int i = 0; i < N; i++)
	{
		cin >> s[i];
		for (int j = 0; j < s[i].length(); j++)
		{
			_s.insert(s[i][j]);
		}
	}

	//몇가지 종류 알파벳이 있는지 알아내기
	set<char>::iterator it;
	for (it = _s.begin(); it != _s.end(); it++)
	{
		v.push_back(*it);
	}

	dfs(0);
	cout << ans << "\n";
	return 0;
}
