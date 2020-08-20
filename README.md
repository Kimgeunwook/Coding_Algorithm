<details markdown="1">    
<summary>1. BFS</summary>  
    
### 1.1 BFS 탐색시 주의사항  

```    
    1. Queue 사용 지향
    2. dx[4] dy[4] 이용한 4방향 검사
    3. visit 체크로 시간 메모리 줄이기
    4. 탐색시 map범위 넘어가는거 체크
    5. visit 체크타이밍 중요 (push하기 전에 체크 (q.pop()하고 체크하면 메모리초과날 확률있다))
	    ex)
	    q.pop();
	    @@@여기서 visit 체크하면 메모리초과 난 문제도 있었다@@@

		for (int k = 0; k < 4; k++)
			if (map[x + dx[k]][y + dy[k]] > 0 && !visit[x + dx[k]][y + dy[k]])
			{
				visit[x + dx[k]][y + dy[k]] = true;
				q.push({ x + dx[k] , y + dy[k] });
			}
```    
</details>    



<details markdown="1">    
<summary>2. DFS</summary>  
    
### 1.1 Dfs와 dp결합

```    
... 백준1937(욕심쟁이 판다) 문제中...
   int dfs(int x, int y)
{
	if (dp[x][y] != 0) return dp[x][y]; //이미 x,y자리가 값이 있으면 return 
	dp[x][y] = 1; 
	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 0 && nx < N && ny >= 0 && ny < N && map[nx][ny] > map[x][y])
		{
			dp[x][y] = max(dp[x][y], dfs(nx, ny) + 1); //4방향에서 얻은 것중 제일 큰값 설정
		}
	}
	return dp[x][y];
}
```    
#  
### 1.2 백트래킹

```    
...... 백준 1987中.......
   for (int i = 0; i < 4; i++) 
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		if(nx >= 1 && nx <= r && ny >= 1 && ny <= c)
		{
			if (visit[map[nx][ny] - 'A'] == 0) 
			{
				visit[map[nx][ny] - 'A'] = 1; 
				dfs(nx, ny, depth + 1);
				visit[map[nx][ny] - 'A'] = 0; //이부분 백트래킹
			}
		}
	}
```    
</details>    



<details markdown="1">    
<summary>3. DP</summary>  
    
### 3.1 LIS(lower_bound방법 nlogn시간)  

```    
    -백준2352中-

#include <algorithm> //lowerbound 위한 헤더 

	v.push_back(arr[1]);
	for (int i = 2; i <= N; i++)
	{
		if (arr[i] > v[v.size() - 1]) // 제일 뒤에 숫자보다 크면 push
		{
			v.push_back(arr[i]);
			continue;
		}
		int it = lower_bound(v.begin(), v.end(), arr[i]) - v.begin(); //현재 숫자보다 '이상' 인곳에 현재숫자로 대체(= 손해볼일 없다)
		v[it] = arr[i];
	}

	cout << v.size() << endl; //사이즈가 곧 최장거리
	return 0;
}
    
```    
</details>    
