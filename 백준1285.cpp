#include <iostream>
#include <string>
#include <bitset>
#include <algorithm>
using namespace std;
int answer = 20 * 20;
int N;
char coin[20][20];
bitset<20> bit;

void input()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		string temp;
		cin >> temp;
		for (int j = 0; j < temp.size(); j++)
		{
			coin[i][j] = temp[j];
		}
	}	
}

void solve()
{
	for (int bit_idx = 0; bit_idx < (1 << N); bit_idx++)
	{
		int temp_min = 0;
		for (int col = 0; col < N; col++)
		{
			int cnt = 0;
			for (int row = 0; row < N; row++)
			{
				char ch = coin[row][col];
				if ((bit_idx & (1 << col)) != 0)
				{
					if (coin[row][col] == 'H') ch = 'T';
					else ch = 'H';
				}
				if (ch == 'T') cnt++;
			}
			temp_min += min(N - cnt, cnt);
		}
		answer = min(answer, temp_min);
	}
}
int main()
{
	
	input();
	solve();
	cout << answer << endl;
	return 0;
}
