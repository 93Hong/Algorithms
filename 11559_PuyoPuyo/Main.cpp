#include <cstdio>
#include <queue>
#pragma warning(disable:4996)

using namespace std;

char map[12][6];
int checked[12][6];
int dir[4][2] = { {0, 1}, {1, 0}, {-1, 0}, {0, -1} };

bool solve(int y, int x) {
	queue<pair<int, int>> q;
	int cnt = 1;
	q.push(make_pair(y, x));
	checked[y][x] = 1;

	while (!q.empty()) {
		int dy = q.front().first;
		int dx = q.front().second;

		for (int i = 0; i < 4; i++) {
			dy += dir[i][0];
			dx += dir[i][1];

			if (dy < 0 || dy >= 12 || dx < 0 || dx >= 6)
				continue;

			if (checked[dy][dx] != 0)
				continue;

			q.push(make_pair(dy, dx));
			checked[dy][dx] = 1;
			cnt++;
		}
	}

	printf("%d\n", cnt);

	if (cnt >= 4) {
		for (int i = 11; i >= 0; i--) {
			for (int j = 0; j < 6; j++) {
				if (checked[i][j] == 1)
					map[i][j] = ',';
			}
		}
		return true;
	}
	return false;
}

int main() {
	char c;
	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 6; j++) {
			scanf("%1c", &map[i][j]);
		}
		scanf("%c", &c);
	}

	bool flag = true;
	int ans = 0;

//	while (flag) {
		bool ok = false;
		for (int i = 11; i >= 0; i--) {
			for (int j = 0; j < 6; j++) {
				if (map[i][j] != '.' && checked[i][j] == 0) {
					if (solve(i, j))
						ok = true;
				}
			}
		}

		for (int i = 0; i < 12; i++) {
			for (int j = 0; j < 6; j++) {
				printf("%c", map[i][j]);
			}printf("\n");
		}

		if (ok) {
			for (int i = 10; i >= 0; i--) {
				for (int j = 0; j < 6; j++) {
					if (map[i][j] == ',') {
						for (int k = i; k < 10; k++) {
							map[k][j] = map[k + 1][j];
						}
					}
				}
			}
		}

		ans++;
//	}

		for (int i = 0; i < 12; i++) {
			for (int j = 0; j < 6; j++) {
				printf("%c", map[i][j]);
			}printf("\n");
		}

	printf("%d\n", ans);
}