//13:58
#include <string>
#include <vector>
#include <queue>
using namespace std;
string answer = "";
string merge(int n)
{
	int hour = n / 60;
	int minute = n % 60;
	string shour = to_string(hour);
	string sminute = to_string(minute);
	if (hour<10) shour = "0" + shour;
	if (minute<10)sminute = "0" + sminute;
	return shour + ":" + sminute;
}
priority_queue<int, vector<int>, greater<int>> pq;
string solution(int n, int t, int m, vector<string> timetable) {


	for (int i = 0; i < timetable.size(); i++)
	{
		int hour = 10 * (timetable[i][0] - '0') + timetable[i][1] - '0';
		int minute = 10 * (timetable[i][3] - '0') + timetable[i][4] - '0';
		int time = 60 * hour + minute;
		pq.push(time);
	}

	int start = 540;
	bool avail = true; //사람이 탄 마지막버스가 꽉찬지
	int lastbus = -1;
	int last = -1;//마지막 탄 사람
	for (int i = 0; i < n; i++)
	{
		int cnt = 0;
		while (!pq.empty())
		{
			int cur = pq.top();
			if (cur > start) break;
			lastbus = start;
			last = cur;
			cnt++;
			pq.pop();
			if (cnt == m)
			{
				avail = false;
				break;
			}
			else
				avail = true;
		}
		start += t;
	}
	start -= t;
	if (lastbus == start)
	{
		if (avail)
			return merge(lastbus);
		else
			return merge(last - 1);
	}
	else
	{
		return merge(start);
	}
}