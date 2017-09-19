#include <cstdio>
#include <queue>
#pragma warning(disable : 4996)

using namespace std;

int dirX[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
int dirY[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
bool map[251][251];
queue<pair<int, int>> q;
int n, m, ans = 0;

void solve() {
	while (!q.empty()) {
		int x = q.front().first, y = q.front().second;
		q.pop();

		for (int i = 0; i < 8; i++) {
			int dx = x + dirX[i], dy = y + dirY[i];
			if (dx < 0 || dx >= n || dy < 0 || dy >= m)
				continue;
			if (map[dx][dy]) {
				q.push({ dx, dy });
				map[dx][dy] = 0;
			}
		}
	}

	return;
}

int main() {
	scanf("%d", &n); scanf("%d", &m);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &map[i][j]);
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j]) {
				q.push({i, j});
				map[i][j] = 0;
				solve();
				ans++;
			}
		}
	}

	printf("%d\n", ans);

	return 0;
}