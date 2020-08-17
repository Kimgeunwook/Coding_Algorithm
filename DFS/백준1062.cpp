#include <iostream>
#include <set>
#include <algorithm>
using namespace std;
char alphabet[26] ;
set<char> s;
int N, K;
string arr[50];
int _max = 0;
int cc = 0;
bool visit[26];
void dfs(int cnt, int idx)
{
	if (cnt == K - 5)
	{
		int ans = 0;
		for (int i = 0; i < N; i++)
		{
			int flag = 0;
			for (int j = 0; j < arr[i].size(); j++)
			{
				if (visit[arr[i][j] - 'a'] == 0)
					flag = 1;
			}
			if (flag == 0) ans++;
		}
		_max = max(_max, ans);
	}
	else
	{
		for (int i = idx; i < 26; i++)
		{
			if (alphabet[i] == 'a' || alphabet[i] == 'n' || alphabet[i] == 't' || alphabet[i] == 'i' || alphabet[i] == 'c') continue;
			visit[alphabet[i] - 'a'] = true;
			dfs(cnt + 1, i + 1);
			visit[alphabet[i] - 'a'] = false;
		}

	}
}
int main()
{
	char ch = 'a';
	for (int i = 0; i < 26; i++)
		alphabet[i] = char(ch + i);
	cin >> N >> K;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
		arr[i] = arr[i].substr(4, arr[i].size() - 8);
	}
	visit['a' - 'a'] = true;
	visit['n' - 'a'] = true;
	visit['t' - 'a'] = true;
	visit['i' - 'a'] = true;
	visit['c' - 'a'] = true;
	if (K < 5)
	{
		cout << 0 << endl;
		return 0;
	}
	dfs(0,0);
	cout << _max << endl;
	return 0;
}
