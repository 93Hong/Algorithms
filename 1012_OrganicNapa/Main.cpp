#include <cstdio>
#include <queue>
#pragma warning(disable:4996)

using namespace std;

int arr[51][51];
int dir[4][2] = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };

int main() {
	int T, M, N, K, x, y;
	scanf("%d", &T);

	while (T--) {
		int ans = 0;
		queue<pair<int, int>> q;
		scanf("%d", &M); scanf("%d", &N); scanf("%d", &K);

		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++)
				arr[i][j] = 0;

		while (K--) {
			scanf("%d", &x); scanf("%d", &y);
			arr[x][y] = 1;
		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (arr[i][j] == 1) {
					q.push({ i, j });
					arr[i][j] = 0;

					while (!q.empty()) {
						x = q.front().first;
						y = q.front().second;
						q.pop();
						arr[x][y] = 0;

						for (int k = 0; k < 4; k++) {
							int dx = x + dir[k][0];
							int dy = y + dir[k][1];

							if (dx >= N || dx < 0 || dy >= M || dy < 0)
								continue;
							if (arr[dx][dy] == 1) {
								q.push({ dx, dy });
							}
						}
					}

					ans++;
				}
			}
		}

		printf("%d\n", ans);
	}
}