#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int dp[51][51]; //dp배열
	int num;//총 숫자 개수
	int a, b;//숫자 2개받을때 쓸 변수
	int line_max[51];//각 라인마다 최대 몇점짜리 있는지 저장할 배열
	int line_max_min = 99999;//line_max에서 최소값
	int count = 0;
	cin >> num;


	for (int i = 1; i <= num; i++) //dp배열 max숫자로 초기화
		for (int j = 1; j <= num; j++)
		{
			if (i == j)
				dp[i][j] = 0;
			else
				dp[i][j] = 99999;
		}


	for (int i = 0; i <= 50; i++) //line_max초기화
		line_max[i] = -1;


	while (1)
	{
		cin >> a >> b;
		if (a == -1 && b == -1) //종료 조건
			break;
		dp[a][b] = 1; // 아는사이면 1저장
		dp[b][a] = 1;
	}


	for (int i = 1; i <= num; i++) //dp저장하는 단계
		for (int j = 1; j <= num; j++)
			for (int k = 1; k <= num; k++)
			{
				dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
				dp[j][i] = dp[i][j];
			}


	for (int i = 1; i <= num; i++) //line_max찾는단계 ((여기서 시간 더 줄일 수 있는 방법 생각해보기))
	{
		for (int j = 1; j <= num; j++)
		{
			if (dp[i][j] > line_max[i])
				line_max[i] = dp[i][j];
		}
		if (line_max[i] < line_max_min)
			line_max_min = line_max[i];
	}


	for (int i = 1; i <= num; i++)
		if (line_max[i] == line_max_min)
		{
			count++; //같은 점수가 몇개인지
		}
	cout << line_max_min << " " << count << endl;


	for (int i = 1; i <= num; i++) //같은 점수인애들 출력
		if (line_max[i] == line_max_min)
			cout << i << " ";

	return 0;
}
