#include <cstdio>
#pragma warning(disable:4996)

using namespace std;
int answer = 0;

int go(int n, int cnt,  int plus) {
	plus += 2;

	if (n == 1)
		answer++;

	
	for (int i = 0; i <= plus; i++) {
		if (n/3 - i > 1)
			go(n / 3 - i, cnt + 1, plus - i);
	}
}

int main() {
	int n = 15;

	 go(n, 0, 0);

	 printf("%d\n", answer);
}