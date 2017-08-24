#include <cstdio>
#include <cstring>
#pragma warning(disable:4996)

using namespace std;

int map[501][501], dp[501][501];
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };
int M, N;

int go(int x, int y) {
	if (x == M - 1 && y == N - 1)
		return 1;

	if (dp[x][y] != -1)
		return dp[x][y];
	dp[x][y] = 0;

	for (int i = 0; i < 4; i++) {
		if (x + dx[i] < 0 || x + dx[i] >= M || y + dy[i] < 0 || y + dy[i] >= N)
			continue;
		if (map[x][y] > map[x + dx[i]][y + dy[i]]) {
			dp[x][y] += go(x + dx[i], y + dy[i]);
		}
	}
	return dp[x][y];
}

int main() {
	scanf("%d", &M); scanf("%d", &N);

	memset(dp, -1, sizeof(dp));

	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &map[i][j]);
		}
	}

	printf("%d\n", go(0, 0));
}