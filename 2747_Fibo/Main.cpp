#include <cstdio>
#pragma warning(disable: 4996)

using namespace std;

long long fibo[41];
long long fibo2[41];

int main() {
	int n;
	n = 40;
	fibo[0] = 0;
	fibo[1] = 1;
	fibo2[0] = 1;
	fibo2[1] = 0;

	for (int i = 2; i < n + 1; i++) {
		fibo[i] = fibo[i - 1] + fibo[i - 2];
		fibo2[i] = fibo2[i - 1] + fibo2[i - 2];
	}

	int T, num;
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &num);
		printf("%lld %lld\n", fibo2[num], fibo[num]);
	}
}