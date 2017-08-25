#include <cstdio>
#include <cstring>

#pragma warning(disable:4996)

using namespace std;

int n, ans = 0;
int map[501][501], dp[501][501];
int dx[] = { 0, 0, 1, -1 }, dy[] = { 1, -1, 0, 0 };

int go(int x, int y) {
	if (dp[x][y] > 1)
		return dp[x][y];

	if (dp[x][y] == -1)
		dp[x][y] = 1;

	for (int i = 0; i < 4; i++) {
		if (x + dx[i] < 0 || x + dx[i] >= n || y + dy[i] < 0 || y + dy[i] >= n)
			continue;
		
		if (map[x][y] < map[x + dx[i]][y + dy[i]]) {
			int tmp = 1;
			tmp += go(x + dx[i], y + dy[i]);
			if (tmp > dp[x][y])
				dp[x][y] = tmp;
		}
	}

	return dp[x][y];
}

int main() {
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			scanf("%d", &map[i][j]);

	memset(dp, -1, sizeof(dp));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			go(i, j);
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (ans < dp[i][j])
				ans = dp[i][j];
		}
	}

	printf("%d\n", ans);
}