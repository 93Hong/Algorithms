#include <cstdio>
#pragma warning(disable: 4996)

using namespace std;

long long fibo[100];

int main() {
	int n;
	scanf("%d", &n);

	fibo[0] = 0;
	fibo[1] = 1;

	for (int i = 2; i < n + 1; i++) {
		fibo[i] = fibo[i - 1] + fibo[i - 2];
		fibo[i] %= 1000000;
	}

	printf("%lld\n", fibo[n]);
}