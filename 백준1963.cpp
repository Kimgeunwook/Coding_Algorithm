#include <iostream>
#include <string>
#include <queue>
using namespace std;
string start, dest;
bool prime[10000], visit[10000];
int _min = 987654321;
queue<pair<string,int>> q;
void get_prime()
{
	//false인게 소수 
	for (int i = 2; i * i <= 10000; i++)
		if (!prime[i])
		{
			for (int j = i + i; j <= 10000; j += i) {
				prime[j] = true;
			}
		}
}
void init()
{
	while (!q.empty())q.pop();
	for (int i = 1000; i < 10000; i++) visit[i] = false;
}
int bfs()
{
	string temp_string = "";
	visit[stoi(start)] = true;
	q.push({ start, 0 });
	while (!q.empty())
	{
		string cur_s = q.front().first;
		int cur_idx = q.front().second;
		q.pop();
		if (cur_s == dest) return cur_idx;
		for(int i = 0 ; i < 4; i ++)
			for (int j = 0; j < 10; j++)
			{
				temp_string = cur_s;
				temp_string[i] = '0' + j; //string에서 idx값 변경위해 char형식으로 넣어주기

				//4자리수 && 소수이고 && 방문한적 없으면
				if (1000 <= stoi(temp_string) && stoi(temp_string) < 10000 && !(prime[stoi(temp_string)]) && !visit[stoi(temp_string)])
				{
					visit[stoi(temp_string)] = true;
					q.push({ temp_string, cur_idx + 1 });
				}
			}
	}
	return -1;
}
int main()
{
	get_prime();
	int T; cin >> T;
	while (T--)
	{
		cin >> start >> dest;
		init();
		int ret = bfs();
		if (ret == -1) cout << "Impossible" << endl;
		else cout << ret << endl;
	}
	return 0;
}