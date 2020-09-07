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
### 1.3 visit체크 done체크

```    
...... 백준 9466中.......
   void dfs(int n)
{
	visit[n] = true;
	int next = arr[n];

	if (!visit[next])
		dfs(next);
	else if (!check[next])
	{
		for (int i = next; i != n; i = arr[i]) ans++;
		ans++;
	}
	check[n] = true;
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
<summary>5. 다익스트라</summary>  
    
### 다익스트라 유형 조건  
```  
    1. 간선이 모두 양수여야 한다.
    2. 한 정점에서 모든점까지 최소거리를 알고싶을때 사용
```  
### 다익스트라 사용법  
```  
    1. 선언부분
    	vector<int> dist(SIZE); //SIZE = v개수
	vector<pair<int, int>> v[SIZE];
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq;
    2. 각 V끼리 간선 길이 입력부분
	for (int i = 0; i < E; i++)
	{
		cin >> start >> dest >> weight;
		v[start].push_back(make_pair(dest, weight)); //start에서 dest까지 weight이다 == v[start] = {dest,weight}
	}
    3. 중간 설정
    	fill(dist.begin(), dist.end(), INF); // 거리 일단 INF로 초기화
	dist[N] = 0; //출발지점 빼고 
	pq.push(make_pair(0, N)); //(cost, 목적지)순 (cost순 오름차순 위해)
    4. 메인 부분
	while (!pq.empty())
	{
		int cur = pq.top().second; //목적지
		pq.pop();

		for (int i = 0; i < v[cur].size(); i++)
		{
			int next = v[cur][i].first;
			int nextcost = v[cur][i].second;

			if (dist[next] > dist[cur] + nextcost)
			{
				dist[next] = dist[cur] + nextcost;
				pq.push(make_pair(dist[next], next));
			}

		}
	}

```  

</details>   


<details markdown="1">    
<summary>6. 맵</summary>  
    
### TIP(두점 사이 VISIT체크할때)  
```
typedef pair<int, int> Pair;
map<Pair, bool> visitNode;
map< pair< Pair, Pair>, bool> visitDirect;

이렇게 변수 선언하고

visitNode[{curX, curY}] = true;
visitDirect[{ {curX, curY}, { nextX, nextY } }] = true;
이게 된다
```
</details> 

<details markdown="1">    
<summary>. SQL</summary>  
    
### 1.1 삼성 문제유형 풀때 주의사항 

```    
  
```    
</details>    


</details> 

<details markdown="1">    
<summary>7. 삼성기출</summary>  
    
### 1.1 삼성 문제유형 풀때 주의사항 

```    
    1. 실제 시험장에서는 여러개 케이스를 한번에 돌리기 때문에 이전 케이스 실행시 선언했던 배열, 변수가 다음 케이스에 영향주는 부분을 체크
    ex ) 탈주범 검거 input에서 배열을 매번 전체크기돌며 초기화 시키는 것 처럼
```    
</details>    

<details markdown="1">    
<summary>. String</summary>  
    
### 1. 형 변환  

```    
    1. string - > int : stoi({스트링 변수})
    2. int - > string : to_string({int 변수})
```    

### 2. 문자열 자르기  

```    
    string s = "abcdefg"; 
    cout << s.substr(3) << endl; //defg
    cout << s.substr(3, 2) << endl; //de
    cout << s.substr(3, 200) << endl; //defg
    cout << s.substr(100) << endl; //error
```    
</details>    

<details markdown="1">    
<summary>8. 재귀</summary>  
    
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

<details markdown="1">    
<summary>. 순열</summary>  
    
### 1. 중복없는 순열  

```
vector<int> v(5);
v = {1, 2, 3, 4, 5};
int temp[5];
int visit[5];
void dfs(int cnt)
{
	if (cnt == 5)
	{
		for (int i = 0; i < 5; i++)
			cout << temp[i] << " ";
		cout << endl;
	}
	else
	{
		for (int i = 0; i < 5; i++)
		{
			if (visit[i] == 1) continue;
			visit[i] = 1;
			temp[cnt] = v[i];
			dfs(cnt + 1);
			visit[i] = 0;
		}
	}
}
   실행결과
   1 2 3 4 5
   1 2 3 5 4
   1 2 4 3 5
   1 2 4 5 3
   .
   .
   .
   5 4 2 3 1
   5 4 3 1 2
   5 4 3 2 1
```    
### 2. combination    
```
5C3예시
int temp[5];
void dfs(int cnt, int idx)
{
	if (cnt == 3)
	{
		for (int i = 0; i < 3; i++)
			cout << temp[i] << " ";
		cout << endl;
	}
	else
	{
		for (int i = idx; i < 5; i++)
		{
			temp[cnt] = v[i];
			dfs(cnt + 1, i + 1);
		}
	}
}
```

### 2. permutation    
```
5P3예시
void dfs(int cnt)
{
	if (cnt == 3)
	{
		for (int i = 0; i < 3; i++)
			cout << temp[i] << " ";
		cout << endl;
	}
	else
	{
		for (int i = 1; i <= 5; i++)
		{
			if (visit[i] == 1) continue;
			visit[i] = 1;
			temp[cnt] = i;
			dfs(cnt + 1);
			visit[i] = 0;
		}
	}
}
```
</details>    

<details markdown="1">    
<summary>. 스택</summary>  
    
### 1. 배열 스택기본

```    
1.기본 top = -1
2 push : stack[++top]
3. pop : stack[top--]
4. isempty ? : if(top < 0)
```    
</details>    

<details markdown="1">    
<summary>. 에라토스테네스 소수</summary>  
    
### 1. 기본   

```    
   	vector<bool> check(4000000); //false로 초기화
	vector<int> p;
	void getPrime(int N)
	{
		check[1] = true;
		for (int i = 2; i * i <= N; i++)
			if (!check[i])
			{
				for (int j = i + i; j <= N; j += i) {
					check[j] = true;
				}
			}

		for (int i = 2; i <= N; i++)
			if (!check[i]) p.push_back(i);
	}
```    
</details>   


<details markdown="1">    
<summary>9. 정렬</summary>  
    
### 1. vector + comp (info 구조체를 size별 오름차순정렬)  

```    
	bool comp(info a, info b)
	{
		return a.size < b.size; // 사이즈별 오름차순
	}
  	sort(v.begin(), v.end(), comp);
```    

### 2. tip  

```
	입력이나 출력이 너무 크면 scanf, cout << << "\n"사용
```    
### 3. 투포인터  

```
 	-백준 10800中-
	for (int i = 0, j = 0; i < N; i++) //첨에 i , j 둘다 초기화하고 
	{
		while (v[j].size < v[i].size) //두번째 반복문에서는 j만 플러스하면 j를 0부터 다시 시작해야되는 시간낭비 안해도됐다.
		{
			sum += v[j].size;
			colorsum[v[j].color] += v[j].size;
			j++;
		}
		ans[v[i].idx] = sum - colorsum[v[i].color];
	}
```    
### 3. 위상정렬  

```
1. 단방향 그래프일때사용
2. 일의 우선처리 순서문제시
3. 차수가 0인애부터 선 주고 선받은애 차수 하나씩-- , 받는애가 차수0되면 q에삽입
5. 줄때 맥스계산
4. -백준 1516참조-
	
```    
</details>    

<details markdown="1">    
<summary>. 투포인터</summary>  
    
### 1. 기본

```    
    int twoPointer(int N)
{
	int s = 0, e = 0;
	int answer = 0;
	int temp = 0;

	while (1)
	{
		if (temp >= N) temp -= p[s++];
		else if (e == p.size()) break;
		else temp += p[e++];
		if (temp == N) answer++;
	}

	return answer;
}
```    
</details>    
<details markdown="1">    
<summary>. 파이썬 문법</summary>  
    
### 1. 문법   

```    
	#1.완전 새로운 배열 만들고 싶을때
   	import copy 
	map2 = copy.deepcopy(map1)
	
	#2. 10x10 visit배열 선언시
	_map = [ [0 for _ in range(10)] for _ in range(10)]
	
	#3.우선순위큐
	from queue import PriorityQueue
	que = PriorityQueue()
	que.put(4)
	print(que.get())  # 4

	#4. deque
	from _collections import deque
	dq = deque()
	
	#5.sort
	arr = [2,5,1,6,8,3,37,8,7631]
	arr.sort(reverse = True)
	
	#6. element조건 sort
	arr = [('a', 1), ('c', 100), ('b',300)]
	arr.sort(key = lambda element : element[0],reverse=True)

	#7.dict
	dic = {}
	dic['a'] = 3
	dic['b'] = 5
	dic[1] = 'hi'
	print(dic[1])

	#8. 조건sort
	import functools
	arr = sorted(배열이름, key = functools.cmp_to_key(함수이름))
	
	def compare(x, y):
	if(x[0] < y[0]): # x[0] 값이 y[0]값 보다 작으면
		return 1 # y 내용을 앞으로 보냄
	elif(x[0] > y[0]):
		return -1
	else: # x[0] 값이 y[0]값과 동일하면
		if(x[1] < y[1]): # x[1]과 y[1]을 비교해서 y[1]이 크면
			return -1 # x 내용을 앞으로 보냄
		elif(x[1] > y[1]):
			return 1
		else:
			return 0

```    
</details>   
