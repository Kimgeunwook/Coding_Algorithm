#include <iostream>
using namespace std;
int dice[11], max_score = 0,location[5];
#define N 4
#define R 10
int selected[R];
int map[2][61] = { { 0,2,4,6,8,10,12,14,16,18,20,22,24,26,28,30,32,34,36,38,40,-1,-1,-1,-1,-1,//0~25 
	13,16,19,25,30,35,40,-1,-1,-1,-1,-1,//26~37  
	22,24,25,30,35,40,-1,-1,-1,-1,-1,//38~48 
	28,27,26,25,30,35,40,-1,-1,-1,-1,-1}//49~60  

	,{ 0, } };

//1.말이 이미 도착했을때 
//2.시작점 삼각점이면 어디로가게할지
//3.겹쳤을때 
//4.이동하기전에 전체배열에서 location위치 체크해주고 location값도 바꿔주기
int cnt = 0;
void dfs(int depth)
{
	if (R == depth) 
	{// 모두 선택 되었음
		cnt++;
		for (int i = 0; i < 5; i++)
			location[i] = 0;

		int now_score = 0;
		for (int i = 1; i <= R; i++)
		{
			if (map[0][location[selected[i]]] == -1)//이미 도착점일때
			{
				cout << "이미 도착점" <<location[selected[i]]<< endl;
				return;
			}
				
			if (map[0][location[selected[i]]] == 10) //원래점이 10,20,30이면 check=0해주고 출발점 바꿔주기
			{
				map[1][location[selected[i]]] = 0;
				location[selected[i]] += 20;
			}
			if (map[0][location[selected[i]]] == 20)
			{
				map[1][location[selected[i]]] = 0;
				location[selected[i]] += 27;
			}
			if (map[0][location[selected[i]]] == 30)
			{
				map[1][location[selected[i]]] = 0;
				location[selected[i]] += 33;
			}
			if (map[1][location[selected[i]] + dice[i]] == 1)//겹친 경우
			{
				cout << "여기" << endl;
				return;
			}
				
			else
			{
				map[1][location[selected[i]]] = 0;//이동전 위치 자리플래그 0으로 만들어주기
				if (map[0][location[selected[i]] + dice[i]] != -1) //이동할 자리가 도착점이 아니면
				{
					now_score += map[0][location[selected[i]] + dice[i]];
					location[selected[i]] += dice[i];
					map[1][location[selected[i]]] = 1;
				}
				else
					location[selected[i]] += dice[i];
			}
		//	cout << cnt << endl;
		}
		if (now_score > max_score) 
			max_score = now_score;
		return;
	}
	for (int i = 1; i <= N; i++) 
	{
		selected[depth + 1] = i;
		dfs(depth + 1);
	}
}

int main()
{
	for (int i = 1; i <= 10; i++)
		cin >> dice[i];
	dfs(0);
	cout << max_score << endl;
	return 0;
}
