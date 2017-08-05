#include <cstdio>
#pragma warning(disable:4996)

using namespace std;
int answer = 0;
int N;

void go(int n, int cnt,  int plus) {

	if (n == N && plus == 0)
		answer++;
	if (cnt > 20)
		return;

	plus += 2;

	
	for (int i = 0; i <= plus; i++) {
		if (n * 3 + i <= N) {
			go(n * 3 + i, cnt + 1, plus - i);
		}
	}
}

int main() {
	N = 48;

	go(1, 0, 0);

	printf("%d\n", answer);
}