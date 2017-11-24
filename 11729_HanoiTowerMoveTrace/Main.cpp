#include <cstdio>
#include <cmath>
#pragma warning(disable:4996)

using namespace std;

void hanoi(int n, int start, int end, int buffer) {
	if (n == 1) {
		printf("%d %d\n", start, end);
		return;
	}
	hanoi(n - 1, start, buffer, end);
	hanoi(1, start, end, buffer);
	hanoi(n - 1, buffer, end, start);
}

int main() {
	int N;

	scanf("%d", &N);
	long long cnt = pow(2, N) - 1;
	printf("%lld\n", cnt);
	hanoi(N, 1, 3, 2);
}