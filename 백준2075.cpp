#include <iostream>
#include <queue>
#include <functional>
using namespace std;
int N;
priority_queue<int> pq; // ����, �� ��ȣ

void input()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	[��ó] �ع��� 2075�� N��° ū�� �ؾ˰��� �з� �켱���� ť | �ۼ��� �İ� �ؼ�


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