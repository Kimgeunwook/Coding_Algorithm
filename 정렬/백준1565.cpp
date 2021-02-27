//1935시작 2040끝
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int N, M;
vector<int> v[1001];
int visit[1001];
vector<int> ans;
queue<int> q;
void input()
{
	cin >> N >> M;
	for (int k = 0; k < M; k++)
	{
		int a;cin >> a;

		vector<int> temp;
		for (int i = 0; i < a; i++)
		{
			int b; cin >> b;
			temp.push_back(b);
		}


		for (int i = 0; i < temp.size(); i++)
			for (int j = i + 1; j < temp.size(); j++)
			{
				v[temp[i]].push_back(temp[j]);
				visit[temp[j]]++;
			}
	}
}
void getfirst()
{
	for (int i = 1; i <= N; i++)
		if (visit[i] == 0) q.push(i);
}
void solve()
{
	while (!q.empty())
	{
		int cur = q.front();
		q.pop();
		ans.push_back(cur);
		for (int i = 0; i < v[cur].size(); i++)
		{
			int n = v[cur][i];
			visit[n]--;
			if (visit[n] == 0) q.push(n);
		}
	}
}
void getans()
{
	if (ans.size() != N) cout << 0 << endl;
	else
		for (int i = 0; i < ans.size(); i++)
			cout << ans[i] << endl;
}
int main()
{
	input(); //입력받기
	getfirst(); //위상정렬에서 앞에 아무도 없는애들 queue에 넣어주기
	solve(); //제일 앞에애들 ans에 넣어주기
	getans(); //ans순서대로 출력
	return 0;
}


