//21:18
#include <iostream>
using namespace std;
int arr[10][10];
int N, int starting_point;
void input()
{
	cin >> N >> starting_point;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> arr[i][j];
}
void floyd()
{
	for (int k = 0; k < N; k++)
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)

}
int main()
{
	input();
	floyd();
	return 0;
}