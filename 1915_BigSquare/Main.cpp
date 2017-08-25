#include <cstdio>
#include <algorithm>
#pragma warning(disable:4996)

using namespace std;

int map[1001][1001], dp[1001][1001];

int main() {
	int n, m, ans = 0;

	scanf("%d", &n); scanf("%d", &m);

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			scanf("%1d", &map[i][j]);
			if (map[i][j])
				dp[i][j] = 1;
		}

	for (int i = 1; i < n; i++) {
		for (int j = 1; j < m; j++) {
			if (map[i][j]) {
				dp[i][j] = min(min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]) + 1;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (ans < dp[i][j])
				ans = dp[i][j];
		}
	}

	printf("%d\n", ans*ans);
}