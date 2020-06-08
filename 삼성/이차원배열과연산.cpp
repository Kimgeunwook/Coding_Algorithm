#include <iostream>
#include <map>
#include <queue>
using namespace std;
struct NUM
{
	int n, cnt;
};
struct compare
{
	bool operator()(NUM a, NUM b)
	{
		if (a.cnt != b.cnt)
			return a.cnt > b.cnt;
		return a.n > b.n;
	}
};
int answer = 0,idx = 1;
int r, c, k;
int arr[101][101];
int temp[101][101];
int row_size = 3, col_size = 3;
int max_row = 0, max_col = 0;
map<int, int> cnt_map;
map<int, int>::iterator it;
priority_queue<NUM, vector<NUM>, compare> pq;
int main()
{
	//입력
	cin >> r >> c >> k;
	for (int i = 1; i <= 3; i++)
		for (int j = 1; j <= 3; j++)
			cin >> arr[i][j];
	
	while (1)
	{
		//조건만족
		if (arr[r][c] == k)
		{
			cout << answer << endl;
			return 0;
		}
		answer++;
		
		//row사이즈가 같거나 많으면
		if (row_size >= col_size) 
		{
			max_col= 0;
			for (int i = 1; i <= row_size; i++)
			{
				// 숫자 몇번나오는지 카운팅
				for (int j = 1; j <= col_size; j++)
				{
					if(arr[i][j] != 0)
						cnt_map[arr[i][j]]++;
					arr[i][j] = 0;
				}

				//pq에 넣어주기
				for (it = cnt_map.begin(); it != cnt_map.end(); it++)
				{
					NUM temp = { it->first,it->second };
					pq.push(temp);
				}
					
				//pq에 있는거 arr에 넣어주기(100넘어가는것도 관리)
				int idx = 1;
				while (!pq.empty())
				{
					if (idx > 100)
					{
						pq.pop();
						continue;
					}

					arr[i][idx] = pq.top().n;
					idx++;

					if (idx > 100)
					{
						pq.pop();
						continue;
					}

					arr[i][idx] = pq.top().cnt;
					idx++;

					pq.pop();
				}
				if (idx - 1 > max_col)
				{
					max_col = idx - 1;
				}
					
				cnt_map.clear();
			}
		}
		else
		{
			max_row = 0;
			for (int j = 1; j <= col_size; j++)
			{
				
				for (int i = 1; i <= row_size; i++)
				{
					// 숫자 몇번나오는지 카운팅
					if (arr[i][j] != 0)
						cnt_map[arr[i][j]]++;
					arr[i][j] = 0;
				}

				//pq에 넣어주기
				for (it = cnt_map.begin(); it != cnt_map.end(); it++)
				{
					NUM temp = { it->first,it->second };
					pq.push(temp);
				}

				//pq에 있는거 arr에 넣어주기(100넘어가는것도 관리)
				int idx = 1;
				while (!pq.empty())
				{
					if (idx > 100)
					{
						pq.pop();
						continue;
					}

					arr[idx][j] = pq.top().n;
					idx++;

					if (idx > 100)
					{
						pq.pop();
						continue;
					}

					arr[idx][j] = pq.top().cnt;
					idx++;

					pq.pop();
				}
				if (idx - 1 > max_row)
				{
					max_row = idx - 1;
				}

				cnt_map.clear();
			}
		}
		if(max_row)
			row_size = max_row;
		if(max_col)
			col_size = max_col;

		if (answer > 100)
		{
			cout << -1 << endl;
			return 0;
		}
	}
	
	return 0;
}
