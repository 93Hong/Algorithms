#include <cstdio>
#include <algorithm>
#pragma warning(disable: 4996)

using namespace std;

int map[1001][1001], dp[1001][1001][4];
int dx[3] = { 0, 1, 0 }, dy[3] = {-1, 0, 1};
int N, M;

int go(int x, int y, int dir) {
	if (x == N - 1 && y == M - 1)
		return dp[x][y][dir];
	if (x >= N && x < 0 || y >= M && y < 0)
		return 0;
	if (dp[x][y][dir])
		return dp[x][y][dir];

	for (int i = 0; i < 3; i++) {
		if (dir == i)
			continue;
		int xx = x + dx[i], yy = y + dy[i];

		dp[x][y][dir] = max(dp[x][y][dir], dp[xx])

		int temp = 0;
		temp += go(xx, yy, i);

		if (temp > dp[x][y][dir])
			dp[x][y][dir] = temp;
	}
	return dp[x][y][dir];
}

int main() {
	scanf("%d", &N); scanf("%d", &M);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &map[i][j]);
		}
	}
	dp[0][0][3] = map[0][0];

	printf("%d\n", go(0, 0, 3));
}