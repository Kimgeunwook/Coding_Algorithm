//16:55시작
//17:10끝
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N, M, K, friend_money[10001]; // input관련 변수
#define INF 987654321
int _min ,  answer = 0;
vector<int> v[10001], visit(10001);
void input(){
	cin >> N >> M >> K;
	for (int i = 1; i <= N; i++){
		cin >> friend_money[i];
	}
	for (int i = 0; i < M; i++) {
		int a, b;  cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
}
void dfs(int n) {
	_min = min(_min, friend_money[n]);

	for (int i = 0; i < v[n].size(); i++) {
		int next = v[n][i];
		if (!visit[next]) {
			visit[next] = true;
			dfs(next);
		}
	}
}
void solve(){
	for (int i = 1; i <= N; i++)
		if (!visit[i]) {
			_min = INF;
			dfs(i);
			answer += _min;
		}
}
int main()
{
	input();
	solve();
	if (answer > K) cout << "Oh no" << endl;
	else cout << answer << endl;
	return 0;
}