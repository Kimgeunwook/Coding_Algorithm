#include <iostream>
#include <algorithm>
using namespace std;
int pascal[201][201];
int N, M, K;
void init_pascal()
{
	pascal[0][0] = 1;
	for (int i = 1; i <= 200; i++)
	{
		pascal[i][0] = 1;
		for (int j = 1; j <= i; j++)
		{
			pascal[i][j] = min( (int)1e9 + 1, pascal[i - 1][j - 1] + pascal[i - 1][j]);
		}
	}
}
void search(int _N, int _M)
{
	if (_N + _M == 0) return;
	else if (_N == 0) //a가 없을때
	{
		cout << 'z';
		search(_N, _M - 1);
	}		
	else if (_M == 0) // z가 없을때
	{
		cout << 'a';
		search(_N - 1, _M);
	}		
	else if (pascal[_N + _M - 1][_M] >= K) //a____ 일때 _____으로 만들수 있는 경우의수가 K보다 많으면 일단 제일 앞에는 a로 설정하고 가도 된다.
	{
		cout << 'a';
		search(_N - 1, _M);
	}		
	else
	{
		cout << 'z';
		K -= pascal[_N + _M - 1][_M];
		search(_N , _M - 1);
	}
}

//생각해야되는게 문자열끼리 상대적인 순서를 정하는 것이기에 pascal과 K를 비교해가면서 답을 찾는게 가능하다.
//https://stillchobo.tistory.com/95 여기참고
int main()
{
	init_pascal();
	cin >> N >> M >> K;
	if (pascal[N + M][M] < K)
	{
		cout << -1 << endl;
	}
	else search(N, M);
	return 0;
}