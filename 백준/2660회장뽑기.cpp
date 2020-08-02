#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int dp[51][51]; //dp�迭
	int num;//�� ���� ����
	int a, b;//���� 2�������� �� ����
	int line_max[51];//�� ���θ��� �ִ� ����¥�� �ִ��� ������ �迭
	int line_max_min = 99999;//line_max���� �ּҰ�
	int count = 0;
	cin >> num;


	for (int i = 1; i <= num; i++) //dp�迭 max���ڷ� �ʱ�ȭ
		for (int j = 1; j <= num; j++)
		{
			if (i == j)
				dp[i][j] = 0;
			else
				dp[i][j] = 99999;
		}


	for (int i = 0; i <= 50; i++) //line_max�ʱ�ȭ
		line_max[i] = -1;


	while (1)
	{
		cin >> a >> b;
		if (a == -1 && b == -1) //���� ����
			break;
		dp[a][b] = 1; // �ƴ»��̸� 1����
		dp[b][a] = 1;
	}


	for (int i = 1; i <= num; i++) //dp�����ϴ� �ܰ�
		for (int j = 1; j <= num; j++)
			for (int k = 1; k <= num; k++)
			{
				dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
				dp[j][i] = dp[i][j];
			}


	for (int i = 1; i <= num; i++) //line_maxã�´ܰ� ((���⼭ �ð� �� ���� �� �ִ� ��� �����غ���))
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
			count++; //���� ������ �����
		}
	cout << line_max_min << " " << count << endl;


	for (int i = 1; i <= num; i++) //���� �����ξֵ� ���
		if (line_max[i] == line_max_min)
			cout << i << " ";

	return 0;
}
