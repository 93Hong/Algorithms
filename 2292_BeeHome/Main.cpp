#include <cstdio>
#include <algorithm>
#pragma warning(disable: 4996)

using namespace std;

long int dp[120000];

int main() {
	long int N;
	scanf("%d", &N);

	int n = N / 6 + 1;
	dp[0] = 1;

	n = min(111111, n);

	if (n < 10)
		n = 10;
	
	for (int i = 1; i < n + 1; i++) {
		dp[i] = dp[i - 1] + 6 * i;
	}
	int re;
	for (int i = 0; i < n; i++) {
		if (dp[i] >= N) {
			re = i;
			break;
		}
	}

	printf("%d\n", re + 1);
}