#include <cstdio>
#pragma warning(disable:4996)

using namespace std;

int map[16][16], dp[16][16];
int dx[2] = { 0, 1 }, dy[2] = {1, 0};
int N, M, K;
int s1, s2;

int go(int x, int y, int n, int m) {
	if (x == n - 1 && y == m - 1)
		return 1;
	if (x >= n || y >= m)
		return 0;
	if (dp[x][y])
		return dp[x][y];

	for (int i = 0; i < 2; i++) {
		int xx = x + dx[i], yy = y + dy[i];
		dp[x][y] += go(xx, yy, n, m);
	}
	return dp[x][y];
}

int main() {
	scanf("%d", &N); scanf("%d", &M); scanf("%d", &K);

	if (K == 0) {
		printf("%d\n", go(0, 0, N, M));
	}
	else {
		int m = 1, n = 1;
		while (K > M) {
			K -= M;
			n++;
		}
		m = K;
		s1 = go(0, 0, n, m);
		s2 = go(n - 1, m - 1, N, M);
		printf("%d\n", s1 * s2);
	}
}