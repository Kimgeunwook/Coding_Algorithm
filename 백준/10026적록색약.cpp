#include <iostream>
using namespace std;
char map[101][101];
char map2[101][101];
bool map_use[101][101];
bool map2_use[101][101];
int usual_count = 0;//Á¤»óÄ«¿îÆ®
int unusual_count = 0;//»ö¸ÍÄ«¿îÆ®
char start = 'p';//½ÃÀÛÁÂÇ¥
char start2 = 'p';//»ö¸Í ½ÃÀÛÁÂÇ¥
int num;
void search(int x, int y)
{
	map_use[x][y] = true;
	if (map[x][y] != start)
	{
		start = map[x][y];
		usual_count++;
	}

	for (int i = -1; i<2; i++)
		for (int j = -1; j <2; j++)
		{
			if (i*j == 0 && !(i == 0 && j == 0))
			{
				if (map[x + i][y + j] == start && !map_use[x + i][y + j])//¿©±â¶û
					search(x + i, y + j);
			}
		}
}
void search2(int x, int y)
{
	map2_use[x][y] = true;
	if (map2[x][y] != start2)
	{
		start2 = map2[x][y];
		unusual_count++;
	}

	for (int i = -1; i<2; i++)
		for (int j = -1; j <2; j++)
		{
			if (i*j == 0 && !(i == 0 && j == 0))
			{
				if (map2[x + i][y + j] == start2 && !map2_use[x + i][y + j])//¿©±â¶û
					search2(x + i, y + j);
			}
		}
}
int main()
{
	cin >> num;
	for (int i = 1; i <= num; i++)
		for (int j = 1; j <= num; j++)
		{
			cin >> map[i][j];
			if (map[i][j] == 'R')
				map2[i][j] = 'G';
			else
				map2[i][j] = map[i][j];
		}

	for (int i = 1; i <= num; i++)
		for (int j = 1; j <= num; j++)
		{
			if (!map_use[i][j])
				search(i, j);
			if (!map2_use[i][j])
				search2(i, j);
			start2 = 'p';
			start = 'p';//ÃÊ±âÈ­
		}

	cout << usual_count << " " << unusual_count << endl;
	return 0;
}