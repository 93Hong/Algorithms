#include <cstdio>
#include <cmath>
#pragma warning(disable:4996)

using namespace std;

int cnt = 0;

void hanoi(int n, int s, int e, int temp) {
	
	if (n <= 1) {
		printf("%d -> %d\n", s, e);
		return;
	}
	cnt++;
	hanoi(n - 1, s, temp, e);
	hanoi(1, s, e, temp);
	hanoi(n - 1, temp, e, s);
}

int main() {
	int N;
	scanf("%d", &N);
	
	long long cnt = pow(2, N) - 1;
	printf("%lld\n", cnt);

	if (N < 20)
		hanoi(N, 1, 3, 2);
}