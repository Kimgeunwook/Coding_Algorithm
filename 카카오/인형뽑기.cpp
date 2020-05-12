#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
	int answer = 0;
	vector<int> basket; // 오른쪽 바구니
	vector<vector<int>> map; //왼쪽 맵
	map.resize(board.size());
	for (int i = board.size() - 1; i >= 0; i--) //맵 만들기
	{
		for (int j = 0; j < board[i].size(); j++)
		{
			if(board[i][j] != 0)
				map[j].push_back(board[i][j]);
		}
	}

	for (int i = 0; i < moves.size(); i++)
	{
		if (map[moves[i] - 1].size() > 0) //꺼낼 인형이 있으면
		{
			if (basket.size() > 0)
			{
				if (basket.back() == map[moves[i] - 1].back()) //바구니 제일 위에인형이랑 지금 넣는 인형이랑 같으면 터트리기
				{
					answer += 2; // 인형 터지면 2개 더해주기
					basket.pop_back();
					map[moves[i] - 1].pop_back();
				}
				else
				{
					basket.push_back(map[moves[i] - 1].back());
					map[moves[i] - 1].pop_back();
				}
			}
			else // 바구니에 아무것도 없으면
			{
				basket.push_back(map[moves[i] - 1].back());//그냥 넣기
				map[moves[i] - 1].pop_back(); // 맵에서는 빼기
			}
		}
	}
	return answer;
}
int main()
{
	vector<vector<int>> board;
	vector<int> moves;
	board = {{0, 0, 0, 0, 0}, { 0, 0, 1, 0, 3 }, { 0, 2, 5, 0, 1 }, { 4, 2, 4, 4, 2 }, { 3, 5, 1, 3, 1 }};
	moves = {1, 5, 3, 5, 1, 2, 1, 4};
	cout<<solution(board, moves);
	return 0;
}
