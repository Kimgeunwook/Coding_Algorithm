#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int num;//좌표들의 개수, dp배열 만들때 카운팅 변수
int answer;//최종 답
vector<pair<int, int>> coordinate; //좌표들 저장 벡터
int dp[10001];
int main()
{	
	for (int i = 1; i <= 10000; i++)
		dp[i] = 987654321;

	cin >> num; 
	for (int i = 0; i < num; i++)
	{
		int element1, element2;
		cin >> element1 >> element2;
		coordinate.push_back(pair<int, int>(element1, element2));
	}
	sort(coordinate.begin(), coordinate.end()); //x좌표 기준으로 소팅
	
	for (int j=1;j<=num;j++) //dp 1~num까지 지정
	{
		int up = 0;
		for (int i = j-1; i >=0; i--) //순서 반대로하면 dp[0]=0이어서 30line이 항상 처음하는게 미니멈이 된다
		{
			up = max(up, 2*abs(coordinate[i].second)); //x좌표끼리 거리가 얼만큼 됐든 그사이에 y좌표가 엄청 큰게 있으면 영향이 더 크므로
			int square = max(up,coordinate[j-1].first-coordinate[i].first);//y좌표가 제일 큰거랑 i,j x좌표 거리중 더 큰게 square
			dp[j] = min(dp[i] + square, dp[j]);//dp
		}
	}
	cout << dp[num] << endl;
	return 0;
}
