#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
struct info {
	int weight, price;
};
int N, K;
vector<info> v;
vector<int> bags;
long long answer = 0;
bool comp(info a, info b)
{
	return a.weight < b.weight;
}
int main()
{
	//입력
	cin >> N >> K;
	int a, b;
	for (int i = 0; i < N; i++)
	{
		cin >> a >> b;
		info newbie = {a, b};
		v.push_back(newbie);
	}
	for (int i = 0; i < K; i++)
	{
		cin >> a;
		bags.push_back(a);
	}

	//무게 오름차순 소팅
	sort(v.begin(), v.end(),comp);
	//무게 오름차순 소팅
	sort(bags.begin(), bags.end());

	int idx = 0;
	priority_queue<int, vector<int>> pq;

	for (int i = 0; i < bags.size(); i++)
	{
		for (int j = idx; j < v.size(); j++)
		{
			if (bags[i] > v[j].weight) {
				pq.push(v[j].price);
				idx++;
			}
			else break;
		}
			 
		if (!pq.empty()) {
			answer += pq.top();
			pq.pop();
		} 
	}

	cout << answer << endl;
	return 0;
}
