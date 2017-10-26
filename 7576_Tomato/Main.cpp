#include <cstdio>
#include <algorithm>
#include <queue>
#pragma warning(disable:4996)

using namespace std;

int map[1001][1001], check[1001][1001];

queue<pair<int, int>> q;
int M, N;
int cnt = -1;
int dir[4][2] = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };

void solve() {
	while (!q.empty()) {
		int size = q.size();
		for (int i = 0; i < size; i++) {
			int x = q.front().first;
			int y = q.front().second;
			q.pop();

			for (int i = 0; i < 4; i++) {
				int dx = x + dir[i][0];
				int dy = y + dir[i][1];

				if (dx < 0 || dx >= N || dy < 0 || dy >= M)
					continue;
				if (map[dx][dy] == -1 || map[dx][dy] == 1 || check[dx][dy] != 0)
					continue;
				map[dx][dy] = 1;
				check[dx][dy] = 1;
				q.push(make_pair(dx, dy));
			}
		}
		cnt++;
	}
}

int main() {
	scanf("%d %d", &M, &N);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &map[i][j]);
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] == 1 && check[i][j] == 0) {
				q.push(make_pair(i, j));
				check[i][j] = 1;
			}
		}
	}

	solve();
	bool flag = false;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] == 0) {
				flag = true;
				break;
			}
		}
	}
	if (flag)
		printf("-1\n");
	else
		printf("%d\n", max(cnt, 0));
}