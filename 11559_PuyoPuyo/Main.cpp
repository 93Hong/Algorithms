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
	char c = map[y][x];

	while (!q.empty()) {
		int yy = q.front().first;
		int xx = q.front().second;
		
		q.pop();
		for (int i = 0; i < 4; i++) {
			int dy = yy + dir[i][0];
			int dx = xx + dir[i][1];

			if (dy < 0 || dy >= 12 || dx < 0 || dx >= 6)
				continue;

			if (checked[dy][dx] == 0 && map[dy][dx] == c) {

				q.push(make_pair(dy, dx));
				checked[dy][dx] = 1;
				cnt++;
			}
		}
	}

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

	while (flag) {
		bool ok = false;
		for (int i = 11; i >= 0; i--) {
			for (int j = 0; j < 6; j++) {
				if (map[i][j] != '.' && checked[i][j] == 0) {
					if (solve(i, j))
						ok = true;
				}
			}
		}

		if (ok) {
			for (int i = 0; i < 12; i++) {
				for (int j = 0; j < 6; j++) {
					if (map[i][j] == ',') {
						for (int k = 11; k > 0; k--) {
							map[k][j] = map[k - 1][j];
						}
						map[0][j] = '.';
					}
				}
			}
		}
		else {
			break;
		}

		ans++;
		memset(checked, 0, sizeof(checked));
	}

	printf("%d\n", ans);
}