<<<<<<< Updated upstream:에라토스테네스소수/백준1644.cpp
//소수찾기 + 투포인터
=======
//2028����
>>>>>>> Stashed changes:백준1644.cpp
#include <iostream>
#include <vector>
using namespace std;
int N;
vector<bool> check(4000000); //false가 소수
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
int main()
{
	cin >> N;
	getPrime(N);
	cout << twoPointer(N) << endl;
	return 0;
}
