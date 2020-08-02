#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int V, E;
int parent[10001];
int sum = 0, cnt = 1;
struct info {
	int start, dest, weight;
};
bool comp(info a, info b)
{
	return a.weight < b.weight;
}
vector<info> v;
int _find(int a)
{
	if (parent[a] == a) return a;
	else return _find(parent[a]);
}
void Union(int a, int b)
{
	a = _find(a);
	b = _find(b);
	parent[b] = a;
}

int main()
{
	cin >> V >> E;
	//ó���� �ڱ� �θ� �ڱ��ڽ����� �ʱ�ȭ
	for (int i = 1; i <= V; i++)
		parent[i] = i;

	//�Է�
	int a, b, c;
	for (int i = 0; i < E; i++)
	{
		cin >> a >> b >> c;
		info newbie = { a, b, c };
		v.push_back(newbie);
	}

	//weight ������������ ����
	sort(v.begin(), v.end(), comp);

	for (int i = 0; i < v.size(); i++)
	{
		info cur = v[i];

		if (_find(cur.start) != _find(cur.dest))
		{
			Union(cur.start, cur.dest);
			sum += cur.weight;
		}
	}
	cout << sum << endl;
	return 0;
}