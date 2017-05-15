using namespace std;

int solution(int n, int a, int b) {
	int answer = 0;

	while (1) {
		if (a == b)
			break;
		answer++;
		if (a % 2)
			a++;
		if (b % 2)
			b++;
		a /= 2;
		b /= 2;
	}


	return answer;
}