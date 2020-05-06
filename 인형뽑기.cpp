#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
	int answer = 0;
	vector<int> basket; // ������ �ٱ���
	vector<vector<int>> map; //���� ��
	map.resize(board.size());
	for (int i = board.size() - 1; i >= 0; i--) //�� �����
	{
		for (int j = 0; j < board[i].size(); j++)
		{
			if(board[i][j] != 0)
				map[j].push_back(board[i][j]);
		}
	}

	for (int i = 0; i < moves.size(); i++)
	{
		if (map[moves[i] - 1].size() > 0) //���� ������ ������
		{
			if (basket.size() > 0)
			{
				if (basket.back() == map[moves[i] - 1].back()) //�ٱ��� ���� ���������̶� ���� �ִ� �����̶� ������ ��Ʈ����
				{
					answer += 2; // ���� ������ 2�� �����ֱ�
					basket.pop_back();
					map[moves[i] - 1].pop_back();
				}
				else
				{
					basket.push_back(map[moves[i] - 1].back());
					map[moves[i] - 1].pop_back();
				}
			}
			else // �ٱ��Ͽ� �ƹ��͵� ������
			{
				basket.push_back(map[moves[i] - 1].back());//�׳� �ֱ�
				map[moves[i] - 1].pop_back(); // �ʿ����� ����
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