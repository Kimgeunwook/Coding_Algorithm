#include <iostream>
bool flag[1000001];
#include <cmath>
using namespace std;
long long _start2 = 0, _end = 0; //변수로 _start쓰니까 컴파일 에러떴음
void solve() {
	for (long long i = 2; i <= sqrt(_end); i++) {
		long long divide_num = i * i;
		long long starting = _start2;
		if (starting % divide_num != 0)
		{
			starting = (starting / divide_num + 1) * divide_num;
		}
		for (long long j = 0; ; j++)
		{
			if (starting + j * divide_num > _end) break;
			flag[starting - _start2 + j * divide_num] = true;
		}
	}
}
int get_answer() {
	int cnt = 0;
	for (long long i = 0; i <= (_end - _start2); i++)
		if (!flag[i])
		{
			cnt++;
		}

	return cnt;
}
int main()
{
	cin >> _start2 >> _end;
	solve();
	cout << get_answer() << endl;
	return 0;
}