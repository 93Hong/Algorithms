#include <cstdio>
#pragma warning(disable:4996)

using namespace std;

int dirx[4] = { 0, 0, 1, -1 };
int diry[4] = { 1, -1, 0, 0 };

int main() {
	int n, m, map[10][10];

	scanf("%d", &n); scanf("%d", &m);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &map[i][j]);
		}
	}

	int T;
	scanf("%d", &T);

	while (T--) {
		int x, y, xx, yy;
		int dx, dy, dxx, dyy;
		scanf("%d", &x); scanf("%d", &y); scanf("%d", &xx); scanf("%d", &yy);

		for (int i = 0; i < 4; i++) {
			dx = x + dirx[i]; dy = y + diry[i];
			if (dx < 0 || dx >= n || dy < 0 || dy >= m)
				continue;
			if (!map[dx][dy])
				continue;

			for (int j = 0; j < 4; j++) {
				dxx = xx + dirx[i]; dyy = yy + diry[i];
				if (dxx < 0 || dxx >= n || dyy < 0 || dyy >= m)
					continue;
				if (!map[dxx][dyy])
					continue;

				// 1 line
				if (i != j && (dx == dxx || dy == dyy)) {

				}
				// 2 line
				else if () {

				}
			}
		}
	}
}