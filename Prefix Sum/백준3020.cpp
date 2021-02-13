//13:48시작
#include <iostream>
using namespace std;
#define INF 987654321
int N, H;
int sum[500001], up[500002], down[500002]; //최종 구간합 구할 배열, 위에서 내려오는애 체크할 배열, 아래에서 올라온애 체크할 배열
int _min = INF, mincnt = 0;
void input()
{
	cin >> N >> H;
	for(int i = 0; i < N; i++)
	{
		int num;
		cin >> num;

		if (i % 2 == 0)
			down[num] ++;
		else
			up[H + 1 - num] ++;
	}
}
void solveUp()
{
	for (int i = H; i >= 1; i--)
	{
		down[i] += down[i + 1];
		sum[i] += down[i];
	}
}
void solveDown()
{
	for (int i = 1; i <= H; i++)
	{
		up[i] += up[i - 1];
		sum[i] += up[i];
	}
}
void getAnswer()
{
	for (int i = 1; i <= H; i++)
	{
		if (sum[i] < _min)
		{
			_min = sum[i];
			mincnt = 1;
		}
		else if (sum[i] == _min)
		{
			mincnt++;
		}
		
	}
}
int main()
{
	input();
	
	solveUp();
	solveDown();
	/*cout << "배열보여주기" << endl;
	for (int i = H; i >= 1; i--)
	{
		cout << sum[i] << endl;
	}
	cout << "배열보여주기" << endl;*/
	getAnswer();
	cout << _min << " " << mincnt << endl;
	return 0;
}
