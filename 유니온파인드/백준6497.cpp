// 1. mst로 작은 거 부터 연결하다가 다 연결되면 그때 합산 점수가 답
#include <iostream>
#include <queue>
using namespace std;
struct info {
	int a, b, weight;
};

struct compare {
	bool operator()(info a, info b)
	{
		return a.weight > b.weight;
	}
};

priority_queue<info, vector<info>, compare> pq;
int N, M, answer;
int parent[200000];
void init()
{
	while (!pq.empty()) pq.pop();
	answer = 0;
	for (int i = 0; i < M; i++) parent[i] = i;
}

bool input()
{
	cin >> M >> N;

	init();

	if (M == 0 && N == 0) return false; //종료 조건

	int a, b, c;
	for (int i = 0; i < N; i++)
	{
		cin >> a >> b >> c;
		info newbie = { a,b,c };
		pq.push(newbie);
	}

	return true;
}



int _find(int x)
{
	if (parent[x] == x)
		return x;
	else {
		parent[x] = _find(parent[x]);
		return parent[x];

	}

}
void _union(int x, int y)
{
	x = _find(x);
	y = _find(y);
	parent[x] = y;
}


bool is_all_same_parent()
{
	int val = _find(parent[0]);
	for (int i = 1; i < M; i++)
		if (val != _find(parent[i])) return false;

	return true;
}

void solve()
{
	while (!pq.empty())
	{
		info cur = pq.top();
		pq.pop();
		if (_find(cur.a) != _find(cur.b))
		{
			cout << cur.a << "와" << cur.b << "이었다" << endl;
			_union(cur.a, cur.b);
		}
		else {
			answer += cur.weight;
		}

	}

}

int main()
{
	while (input())
	{
		solve();
		cout << answer << endl;
	}
	return 0;
}
