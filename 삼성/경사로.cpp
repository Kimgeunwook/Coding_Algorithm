#include <iostream>
#include <algorithm>
using namespace std;
int map1[100][100], map2[100][100];
int visit_hol[100][100];
int N, L, next_flag;
int cur_hol, cur_hol_cnt;
int search(int map[100][100])
{
	int ret = 0;
	for (int i = 0; i < N; i++)
	{ 
		for (int a = 0; a < N; a++)
			for (int b = 0; b < N; b++)
				visit_hol[a][b] = 0;

		cur_hol = 0;
		cur_hol_cnt = 0;
		next_flag = 0;

		for (int j = 0; j < N; j++)
		{
			if (j != 0 && abs(cur_hol - map[i][j]) > 1) //높이차가 2이상이면
				break;
			if (map[i][j] == cur_hol)
			{
				cur_hol_cnt++;
			}
			else
			{
				if (map[i][j] > cur_hol) //낮음 -> 높음
				{
					cur_hol = map[i][j];
					if (cur_hol_cnt >= L) //다리 놓을 수 있으면
					{
						for(int k = j - 1; k >= j - L; k--)
							if (visit_hol[i][k] == 1)
							{
								next_flag = 1;
								break;
							}
						if (next_flag == 1)
							break;
						cur_hol_cnt = 1;
					}
					else //다리 놓을 개수가 L보다작으면
					{
						if( j != 0)
							break;
						else
							cur_hol_cnt = 1;
					}	
				}
				else //높음 -> 낮음
				{
					cur_hol = map[i][j];
					cur_hol_cnt = 1;
					
					if (j + L > N)
						break;	
					for (int p = j; p < j + L; p++)
					{
						if (map[i][p] == cur_hol)
						{
							visit_hol[i][p] = 1;
						}
						else
						{
							next_flag = 1;
							break;
						}
					}
					if (next_flag)
						break;
				}
			}
			if (j == N - 1)
			{
				ret++;
			}
			
		}
	}
	return ret;
}
int main()
{
	cin >> N >> L;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> map1[i][j];
		
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			map2[i][j] = map1[j][i];
		
	cout << search(map1) + search(map2) << endl;
	return 0;
}
