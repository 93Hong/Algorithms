#include <cstdio>
#include <queue>
#pragma warning(disable: 4996)

using namespace std;

int bt[6][6] = { 0 };
int at[6][6] = { 0 };
int n = 6, k = 2, ax = 1, ay = 2, bx = 0, by = 5;
int dir[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
bool check[6][6];
int board[6][6] = { { 0, 0, 1, 0, 0, 0 },{ 0, 2, 0, 0, 0, 1 },{ 0, 0, 2, 1, 0, 0 },{ 0, 0, 0, 0, 0, 0 },{ 0, 0, 0, 0, 1, 0 },{ 0, 1, 0, 0, 0, 0 } };
int dist[6][6] = { 0 };

void BFS(int sx, int sy) {
	queue<pair<int, int>> q;
	q.push(make_pair(sx, sy));
	check[sx][sy] = true;
	dist[sx][sy] = 0;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int k = 0; k < 4; k++) {
			int nx = x + dir[k][0];
			int ny = y + dir[k][1];

			if (0 <= nx && nx < n && 0 <= ny && ny < n) {
				if (check[nx][ny] == false && board[nx][ny] != 2) {
					q.push(make_pair(nx, ny));
					dist[nx][ny] = dist[x][y] + 1;
					check[nx][ny] = true;
				}
			}
		}
	}
}

int main() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (board[i][j] == 1) {
				at[i][j] = 1;
				for (int q = 0; q < 4; q++) {
					for (int w = 1; w <= k; w++) {
						int x = i + dir[q][0] * w;
						int y = j + dir[q][1] * w;

						if (x < 0 | y < 0 | x >= n | y >= n)
							continue;
						if (board[x][y] == 2)
							break;
						at[x][y] = 1;
					}
				}
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%d", at[i][j]);
		}
		printf("\n");
	}	
	
	printf("\n");
	printf("\n");

	BFS(ax, ay);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%d", dist[i][j]);
		}
		printf("\n");
	}

	memset(dist, 0, sizeof(dist));
	memset(check, 0, sizeof(check));

	printf("\n");
	printf("\n");

	BFS(bx, by);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%d", dist[i][j]);
		}
		printf("\n");
	}
}