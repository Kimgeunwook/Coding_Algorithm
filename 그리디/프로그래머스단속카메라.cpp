#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;
bool isend[10001];
struct info {
	int idx, isstart, dist; // true  시작
};
struct comp {
	bool operator()(info a, info b) {
		return a.dist > b.dist;
	}
};

priority_queue<info, vector<info>, comp> pq;
vector<int> v;
int solution(vector<vector<int>> routes) {
	int answer = 0;
	for (int i = 0; i < routes.size(); i++)
	{
		info temp = { i, 1, routes[i][0] };
		pq.push(temp);
		temp = { i, 0, routes[i][1] };
		pq.push(temp);
	}

	while (!pq.empty())
	{
		info cur = pq.top();
		pq.pop();
		
		if (cur.isstart == 1)//시작점이면
		{
			v.push_back(cur.idx);
		}
		else
		{
			if (isend[cur.idx]) continue; //이미죽은애면 무시
			else
			{
				isend[cur.idx] = true; //죽은표시
				answer++;
				for (int i = 0; i < v.size(); i++) isend[v[i]] = true;
				v.clear();
			}
		}
		
	}
	return answer;
}
int main()
{
	cout << solution({ {-20,15 }, { -14,-5 }, { -18,-13 }, { -5,-3 } }) << endl;
	return 0;
}
