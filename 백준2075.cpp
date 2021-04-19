#include <iostream>
#include <queue>
#include <functional>
using namespace std;
int N;
priority_queue<int> pq; // 숫자, 열 번호

void input()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	[출처] ※백준 2075번 N번째 큰수 ※알고리즘 분류 우선순위 큐 | 작성자 컴공 준성


	cin >> N;
	int a;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
		{
			cin >> a;
			pq.push(-a);
			if (pq.size() > N) pq.pop();
		}
}

int main()
{
	input();
	cout << -pq.top()<< endl;

	return 0;
}