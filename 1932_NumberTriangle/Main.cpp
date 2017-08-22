#include <cstdio>
#include <algorithm>
#pragma warning(disable:4996)

using namespace std;

int dp[501][501];

int main() {
	int n;

	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		for (int j = 1; j <= i+1; j++) {
			scanf("%d", &dp[i][j]);
		}
	}

	for (int i = 1; i < n; i++) {
		for (int j = 1; j <= i+1; j++) {
			dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + dp[i][j];
		}
	}

	int ans = 0;
	if (n == 1)
		ans = dp[0][1];
	for (int i = 1; i <= n; i++) {
		if (ans < dp[n - 1][i]) {
			ans = dp[n - 1][i];
		}
	}

	printf("%d\n", ans);
}