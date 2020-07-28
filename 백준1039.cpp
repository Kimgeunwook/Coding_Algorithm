//#include <iostream>
//using namespace std;
//#include <string>
//int N, K;
//int _max = -1;
//string s;
//int visit[11][1000001];
//void swap(int a, int b)
//{
//	char temp = s[a];
//	s[a] = s[b];
//	s[b] = temp;
//}
//int dfs(int cnt)
//{
//	if(cnt == K)
//	{
//		//if (stoi(s) > _max) _max = stoi(s);
//		return stoi(s);
//	}
//	else
//	{
//		int ret = visit[cnt][stoi(s)];
//
//		for(int i = 0; i < s.length() - 1; i++)
//			for (int j = i + 1; j < s.length(); j++)
//			{
//				swap(i,j);
//				if (s[0] == '0')
//				{
//					swap(i, j);
//					continue;
//				}
//				if (visit[cnt + 1][stoi(s)] == 1) continue;
//				visit[cnt + 1][stoi(s)] = 1;
//				dfs(cnt + 1);
//				swap(j,i);
//			}
//	}
//}
//int main()
//{
//	//to_string()
//	//int num = stoi("2222");
//	cin >> N >> K;
//	s = to_string(N);
//	visit[0][stoi(s)] = 1;
//
//	dfs(0);
//
//	cout << _max << endl;
//	return 0;
//}

#include <iostream>
using namespace std;
#include <string>
#include <queue>
int N, K, cnt = 0, _max = -1;
int SIZE;
queue<pair<string,int>> q;
string s, temp;
int visit[11][1000001];
void swap(int a, int b)
{
	char _temp = temp[a];
	temp[a] = temp[b];
	temp[b] = _temp;
}

void bfs()
{
	while (!q.empty())
	{
		if (q.front().second == K) break;
		for (int i = 0; i < SIZE - 1; i++)
		{
			for (int j = i + 1; j < SIZE; j++)
			{
				temp = q.front().first;
				
				swap(i, j);
				if (temp[0] == '0')
				{
					swap(i, j);
					continue;
				}
				if (visit[q.front().second + 1][stoi(temp)] == 1) continue;
				visit[q.front().second  + 1][stoi(temp)] = 1;
				if(q.front().second + 1 == K) _max = max(_max, stoi(temp));
				q.push(make_pair(temp, q.front().second + 1));
			}
		}
		q.pop();
	}

}
int main()
{
	cin >> N >> K;
	s = to_string(N);
	SIZE = s.length();
	q.push(make_pair(s,0));

	bfs();
	cout << _max << endl;
	return 0;
}