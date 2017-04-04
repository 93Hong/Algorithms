#include <cstdio>
#include <queue>
#pragma warning(disable: 4996)

using namespace std;
int map[101][101];
bool check[101][101];
queue<pair<int, int>> q;

int main() {
	int M = 0, N, K, x, y;
	scanf("%d", &N); scanf("%d", &M); scanf("%d", &K);

	int dir[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };

	for (int i = 0; i < K; i++) {
		scanf("%d", &x); scanf("%d", &y);
		map[x - 1][y - 1] = 1;
	}

	int cnt = 0, max = 0;
	int i, j;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] == 1 && !check[i][j]) {
				q.push({ i, j });
				check[i][j] = true;
				while (!q.empty()) {
					for (int k = 0; k < 4; k++) {
						int x = q.front().first + dir[k][0], y = q.front().second + dir[k][1];
						if (map[x][y] == 1 && !check[x][y]) {
							q.push({ x, y });
							check[x][y] = true;
						}
					}
					q.pop();
					cnt++;
				}
			}
			if (max < cnt)
				max = cnt;
			cnt = 0;
		}
	}
	printf("%d\n", max);
}
