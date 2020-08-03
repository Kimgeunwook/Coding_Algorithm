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
	else if (_N == 0) //a�� ������
	{
		cout << 'z';
		search(_N, _M - 1);
	}		
	else if (_M == 0) // z�� ������
	{
		cout << 'a';
		search(_N - 1, _M);
	}		
	else if (pascal[_N + _M - 1][_M] >= K) //a____ �϶� _____���� ����� �ִ� ����Ǽ��� K���� ������ �ϴ� ���� �տ��� a�� �����ϰ� ���� �ȴ�.
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

//�����ؾߵǴ°� ���ڿ����� ������� ������ ���ϴ� ���̱⿡ pascal�� K�� ���ذ��鼭 ���� ã�°� �����ϴ�.
//https://stillchobo.tistory.com/95 ��������
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