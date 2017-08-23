#include <cstdio>
#pragma warning(disable: 4996)

using namespace std;

long long int dp[102][102];
int map[102][102];

int main() {
	int N;
	long long int ans = 0;

	scanf("%d", &N);
	dp[1][1] = 1;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			scanf("%d", &map[i][j]);
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (map[i][j] == 0)
				continue;
			if (i + map[i][j] <= N)
				dp[i + map[i][j]][j] += dp[i][j];
			if (j + map[i][j] <= N)
				dp[i][j + map[i][j]] += dp[i][j];
		}
	}
	ans = dp[N][N];

	printf("%lld\n", ans);
}