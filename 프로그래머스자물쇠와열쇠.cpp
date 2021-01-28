#include <string>
#include <vector>
#include <iostream>
using namespace std;
bool isCheck(int keySize, int lockSize, vector<vector<int>> board)
{
	for (int i = 0; i < lockSize; i++)
		for (int j = 0; j < lockSize; j++)
			if (board[keySize + i][keySize + j] != 1)
				return false;
	return true;
}
vector<vector<int>> attach(int x, int y, vector<vector<int>> rotate_ret, vector<vector<int>> board)
{
	for (int i = 0; i < rotate_ret.size(); i++)
		for (int j = 0; j < rotate_ret.size(); j++)
			board[x + i][y + j] += rotate_ret[i][j];
	return board;
}
vector<vector<int>> detach(int x, int y, vector<vector<int>> rotate_ret, vector<vector<int>> board)
{
	for (int i = 0; i < rotate_ret.size(); i++)
		for (int j = 0; j < rotate_ret.size(); j++)
			board[x + i][y + j] -= rotate_ret[i][j];
	return board;
}
vector<vector<int>> rotate(vector<vector<int>> key)
{
	vector<vector<int>> temp = key;

	int SIZE = key.size();

	for (int i = 0; i < SIZE; i++)
		for (int j = 0; j < SIZE; j++)
			temp[i][j] = key[SIZE - 1 - j][i];


	return temp;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
	bool answer = false;
	int keySize = key.size();
	int lockSize = lock.size();

	//중앙에 위치 시키기
	vector<vector<int>> board(2 * keySize + lockSize, vector<int>(2 * keySize + lockSize, 0));


	for (int i = 0; i < lockSize; i++)
		for (int j = 0; j < lockSize; j++)
			board[keySize + i][keySize + j] = lock[i][j];


	//4번 돌리고
	for (int k = 0; k < 4; k++)
	{
		vector<vector<int>> rotate_ret = rotate(key);

		for (int i = 1; i < keySize + lockSize; i++)
			for (int j = 1; j < keySize + lockSize; j++)
			{
				//rotate_key를 lock에 붙이고
				board = attach(i, j, rotate_ret, board);
				//ischecktrue면 return true
				if (isCheck(keySize, lockSize, board)) return true;

				//rotate_key를 lock에서 떼기
				board = detach(i, j, rotate_ret, board);
			}

		key = rotate_ret;
	}
	return answer;
}