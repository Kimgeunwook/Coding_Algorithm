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
<summary>3. LIS</summary>  
    
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
### 3.1 LIS(N^2시간 방법)     

```    
    -백준11053中-

for (int i = 1; i <= N; i++)
	{
		dp[i] = 1;
		for (int j = 1; j < i; j++)
		{
			if (arr[i] > arr[j] && dp[j] + 1 > dp[i]) dp[i] = dp[j] + 1;
		}
	}
    
```    
</details>    


<details markdown="1">    
<summary>4. 그리디</summary>  
    
### dp와 마찬가지로 머리싸움인듯 하다. 

</details>   

<details markdown="1">    
<summary>4. 삼성기출</summary>  
    
### 1.1 삼성 문제유형 풀때 주의사항 

```    
    1. 실제 시험장에서는 여러개 케이스를 한번에 돌리기 때문에 이전 케이스 실행시 선언했던 배열, 변수가 다음 케이스에 영향주는 부분을 체크
    ex ) 탈주범 검거 input에서 배열을 매번 전체크기돌며 초기화 시키는 것 처럼
```    
</details>    

<details markdown="1">    
<summary>5. 재귀</summary>  
    
### 1.1 재귀할때 백트래킹을 생각 안해도 되는방법 

```    
    void dfs(int cnt, int result)
{
	if (cnt >= SIZE)
	{
		_max = max(_max, result);
	}
	else
	{
		
		dfs(cnt + 1, calc(result, vi[cnt + 1] , vc[cnt])); //이렇게 원본 배열을 건드리지말고 값을 생성해서 리턴값을 바로 넘기기 
									// 그럼 밑에서 다른 방향으로 재귀를 갈때 값을 다시 변경해주고 시작안해도된다.(백트래킹이 필요없다)

		
		if (cnt + 2 <= SIZE)
		{
			int nextResult = calc(vi[cnt + 1], vi[cnt + 2], vc[cnt + 1]);
			int curResult = calc(result, nextResult, vc[cnt]);
			dfs(cnt + 2, curResult);
		}
	}
}
```    
</details>    
