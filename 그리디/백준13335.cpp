//1429Ω√¿€
#include <iostream>
#include <queue>
using namespace std;
struct info {
	int w, t;
};
int N, W, L,a;
queue<info> truck, bridge;
void Input()
{
	cin >> N >> W >> L;
	for (int i = 0; i < N; i++)
	{
		cin >> a;
		info newbie = { a,0 };
		truck.push(newbie);
	}
		
}
void simulation()
{
	int time = 0;
	int now_weight = 0;
	while (!truck.empty() || !bridge.empty())
	{
		time++;
		if (!bridge.empty())
		{
			info cur = bridge.front();
			if (time - cur.t == W) 
			{
				now_weight -= cur.w;
				bridge.pop();
			} 
		}
		if (!truck.empty())
		{
			info cur = truck.front();
			if (cur.w + now_weight <= L)
			{
				truck.pop();
				now_weight += cur.w;
				info temp = { cur.w, time };
				bridge.push(temp);
			}
		}
	}

	cout << time << endl;
}
int main()
{
	Input();
	simulation();
	return 0;
}