#include <cstdio>
#pragma warning(disable: 4996)

using namespace std;
long long int fibo[81];

int main() {
	int N;
	scanf("%d", &N);
	fibo[0] = 1;
	fibo[1] = 1;

	for (int i = 2; i < N + 1; i++) {
		fibo[i] = fibo[i - 1] + fibo[i - 2];
	}

	printf("%lld\n", fibo[N - 1] * 2 + fibo[N] * 2);
}