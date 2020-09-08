#include <iostream>
#include <vector>
using namespace std;
vector<int> vf[1001];
vector<int> ve[1001];
bool visit[1001];
int N,k,ans =0;
void Input()
{
	cin >> N;
	cin >> k;
	for (int i = 0; i < k; i++)
	{
		char a;
		int  b, c;
		cin >> a >> b >> c;
		if (a == 'F')
		{
			vf[b].push_back(c);
			vf[c].push_back(b);
		}
		else {
			ve[b].push_back(c);
			ve[c].push_back(b);
		}
	}
}
void Solve()
{
	for (int i = 1; i <= N; i++)
	{
		for (int j = 0; j < ve[i].size(); j++)
		{
			for (int z = 0; z < ve[ve[i][j]].size(); z++)
			{
				if (ve[ve[i][j]][z] != i)
				{
					vf[i].push_back(ve[ve[i][j]][z]);
					vf[ve[ve[i][j]][z]].push_back(i);
				}
			}
		}
	}
}
void dfs(int n)
{
	for (int i = 0; i < vf[n].size(); i++)
	{
		if (!visit[vf[n][i]])
		{
			visit[vf[n][i]] = true;
			dfs(vf[n][i]);
		}
	}
}
void getAns()
{
	for (int i = 1; i <= N; i++)
	{
		if (!visit[i])
		{
			visit[i] = true;
			ans++;
			dfs(i);
		}
	}
}
int main()
{
	Input();
	Solve();
	getAns();
	cout << ans << endl;
	return 0;
}