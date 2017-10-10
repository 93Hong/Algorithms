#include <cstdio>
#include <algorithm>
#pragma warning(disable:4996)

using namespace std;

int map[26][26], N, arr[100000], cur = 0;
int dirx[4] = { 0, 0, 1, -1 };
int diry[4] = { 1, -1, 0, 0 };

int bfs(int x, int y, int cnt) {
	for (int i = 0; i < 4; i++) {
		int dx = x + dirx[i], dy = y + diry[i];
		if (dx < 0 || dx >= N || dy < 0 || dy >= N)
			continue;
		if (map[dx][dy] == 1) {
			map[dx][dy] = 0;
			cnt = bfs(dx, dy, cnt + 1);
		}
	}

	return cnt;
}

int main() {
	scanf("%d", &N);

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			scanf("%1d", &map[i][j]);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j] == 1) {
				map[i][j] = 0;
				arr[cur++] = bfs(i, j, 1);
			}
		}
	}

	printf("%d\n", cur);
	sort(arr, arr + cur);
	for (int i = 0; i < cur; i++) {
		printf("%d\n", arr[i]);
	}
}