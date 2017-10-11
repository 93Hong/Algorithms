#include <cstdio>
#include <queue>
#pragma warning(disable:4996)

using namespace std;

char map[51][51];
int check[51][51], fcheck[51][51];
int R, C;
queue<pair<int, int>> man, flood;

int dirx[4] = { 0, 0, 1, -1 };
int diry[4] = { 1, -1, 0, 0 };

bool outOfRange(int i, int j) {
	return (i >= R || i < 0 || j >= C || j < 0);
}

void solve() {
	int cnt = 0;

	while (!man.empty() || !flood.empty()) {
		cnt++;

		while (!flood.empty()) {
			int x = flood.front().first;
			int y = flood.front().second;

			if (fcheck[x][y] != cnt)
			{
				break;
			}
			flood.pop();
			for (int i = 0; i < 4; i++) {
				int dx = x + dirx[i];
				int dy = y + diry[i];

				if (outOfRange(dx, dy))
					continue;
				if (map[dx][dy] != 'D' && map[dx][dy] != 'X' && fcheck[dx][dy] == 0) {
					flood.push(make_pair(dx, dy));
					map[dx][dy] = '*';
					fcheck[dx][dy] = fcheck[x][y] + 1;
				}
			}
		}

		while (!man.empty()) {
			int x = man.front().first;
			int y = man.front().second;
			if (map[x][y] == 'D') {
				return;
			}
			if (check[x][y] != cnt)
			{
				break;
			}
			man.pop();

			for (int i = 0; i < 4; i++) {
				int dx = x + dirx[i];
				int dy = y + diry[i];

				if (outOfRange(dx, dy))
					continue;
				if (map[dx][dy] != '*' && map[dx][dy] != 'X' && check[dx][dy] == 0) {
					man.push(make_pair(dx, dy));
					check[dx][dy] = check[x][y] + 1;
					map[dx][dy] = 'S';
				}
			}
		}

	}
}

int main() {
	scanf("%d", &R); scanf("%d", &C);

	int x, y;

	for (int i = 0; i < R; i++) {
		char c;

		scanf("%c", &c);
		for (int j = 0; j < C; j++) {
			scanf("%c", &c);
			if (c == 'S') {
				man.push(make_pair(i, j));
				check[i][j] = 1;
			}
			else if (c == '*') {
				flood.push(make_pair(i, j));
				fcheck[i][j] = 1;
			}
			else if (c == 'D') {
				x = i;
				y = j;
			}
			map[i][j] = c;
		}
	}

	solve();

	if (check[x][y] == 0)
		printf("KAKTUS\n");
	else
		printf("%d\n", check[x][y] - 1);
}