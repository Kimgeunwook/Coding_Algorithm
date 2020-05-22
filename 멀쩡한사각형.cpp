using namespace std;
long long solution(int w, int h) {
	long long answer = 0;
	long double d_w = w, d_h = h;
	for (int i = 1; i < w; i++)
		answer += int((d_h / d_w) * i);
	return answer * 2;
}