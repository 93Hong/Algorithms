#include <cstdio>
#include <queue>
#include <cstring>
#pragma warning(disable: 4996)

using namespace std;

char map[12][6];
bool check[12][6];
int dir[4][2] = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };
queue<pair<int, int>> qq;

void solve(int x, int y) {
	char c = map[x][y];
	queue<pair<int, int>> q, q2;
	q.push(make_pair(x, y));
	q2.push(make_pair(x, y));
	int cnt = 1;

	while (!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		check[x][y] = 1;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int xx = x + dir[i][0];
			int yy = y + dir[i][1];

			if (xx < 0 || xx > 12 || yy < 0 || yy > 6)
				continue;

			if (check[xx][yy] == 0 && map[xx][yy] == c) {
				q.push(make_pair(xx, yy));
				q2.push(make_pair(xx, yy));
				check[xx][yy] = 1;
				cnt++;
			}
		}
	}

	if (cnt >= 4) {
		while (!q2.empty()) {
			qq.push(q2.front());
			q2.pop();
		}
	}
}

int main() {
	char c;
	int ans = 0;
	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 6; j++) {
			scanf("%1c", &map[i][j]);
		}
		scanf("%c", &c);
	}


	while (1) {
		memset(check, 0, sizeof(check));

		for (int i = 0; i < 12; i++) {
			for (int j = 0; j < 6; j++) {
				if (map[i][j] != '.' && map[i][j] != 'x' && check[i][j] == 0) {
					solve(i, j);
				}
			}
		}

		if (qq.empty())
			break;
		
		while (!qq.empty()) {
			map[qq.front().first][qq.front().second] = 'x';
			qq.pop();
		}

		for (int i = 0; i < 12; i++) {
			for (int j = 0; j < 6; j++) {
				if (map[i][j] == 'x') {
					for (int k = i; k > 0; k--) {
						map[k][j] = map[k - 1][j];
					}
					map[0][j] = '.';
				}
			}
		}

		ans++;

	}

	printf("%d\n", ans);
}