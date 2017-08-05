#include <cstdio>
#include <queue>
#pragma warning(disable:4996)

using namespace std;

int arr[101][101];
int dir[4][2] = { { 0, 1 },{ 0, -1 },{ 1, 0 },{ -1, 0 } };

int main() {
	int M, N, K, x, y;

	int ans = 0;
	queue<pair<int, int>> q;
	M = 6; N = 4;
	vector<vector<int>> picture;
	picture.push_back({ 1, 1, 1, 0 });
	picture.push_back({ 1, 2, 2, 0 });
	picture.push_back({ 1, 0, 0, 1 });
	picture.push_back({ 0, 0, 0, 1 });
	picture.push_back({ 0, 0, 0, 3 });
	picture.push_back({ 0, 0, 0, 3 });

	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			printf("%d", picture[i][j]);
		}
		printf("\n");
	}

	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			if (picture[i][j] != 0) {
				int check = picture[i][j];
				int tmp = 0;
				q.push({ i, j });
				picture[i][j] = 0;

				while (!q.empty()) {
					x = q.front().first;
					y = q.front().second;
					tmp++;
					q.pop();

					for (int k = 0; k < 4; k++) {
						int dx = x + dir[k][0];
						int dy = y + dir[k][1];

						if (dx >= M || dx < 0 || dy >= N || dy < 0)
							continue;
						if (picture[dx][dy] == check) {
							q.push({ dx, dy });
							picture[dx][dy] = 0;
						}
					}
				}

				ans++;
				printf("%d\n", tmp);
			}
		}
	}

	printf("%d\n", ans);
}