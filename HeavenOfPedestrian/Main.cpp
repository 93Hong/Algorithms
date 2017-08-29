#include <cstdio>
#include <cstring>
#pragma warning(disable:4996)

using namespace std;

int MOD = 20170805;
int m, n, map[501][501], dp[501][501][3];
int dx[2] = { 0, 1 }, dy[2] = { 1, 0 };

int go(int x, int y, int dir) {
	if (x < 0 || x >= m || y < 0 || y >= n)
		return 0;
	if (x == m - 1 && y == n - 1)
		return 1;
	if (dp[x][y][dir])
		return dp[x][y][dir];

	if (map[x][y] == 2) {
		int xx = x + dx[dir];
		int yy = y + dy[dir];

		dp[x][y][dir] += go(xx, yy, dir);
		dp[x][y][dir] %= MOD;
	}
	else if (map[x][y] == 0) {
		for (int i = 0; i < 2; i++) {
			int xx = x + dx[i];
			int yy = y + dy[i];

			dp[x][y][dir] += go(xx, yy, i);
			dp[x][y][dir] %= MOD;
		}
	}

	return dp[x][y][dir]%MOD;
}

int main() {
	scanf("%d", &m); scanf("%d", &n);

	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			scanf("%d", &map[i][j]);

	printf("%d\n", go(0, 0, 0));
}