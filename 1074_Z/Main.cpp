#include <cstdio>
#include <math.h>
#pragma warning(disable: 4996)

using namespace std;

int sum = 0;

int solve(int N, int r, int c) {
	if (N == 1) {
		sum += r * 2 + c;
		return 0;
	}

	int n = pow(2, N - 1);
	int square = n * n;

	if (r / n == 0 && c / n == 1)
		sum += square;
	else if (r / n == 1 && c / n == 0)
		sum += square * 2;
	else if (r / n == 1 && c / n == 1)
		sum += square * 3;

	solve(N - 1, r % n, c % n);
}

int main() {
	int N, r, c;
	scanf("%d", &N); scanf("%d", &r); scanf("%d", &c);

	solve(N, r, c);
	printf("%d\n", sum);
}