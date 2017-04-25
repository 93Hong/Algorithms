#include <cstdio>
#include <algorithm>
#pragma warning(disable: 4996)

using namespace std;

int map[51][51], cnt = 1, N, M;
void solve(int x, int y, int dir) {
	if (map[x][y] == 1)
		return;
	if ((map[x - 1][y] == 1 || map[x - 1][y] == 2)
		&& (map[x + 1][y] == 1 || map[x + 1][y] == 2)
		&& (map[x][y - 1] == 1 || map[x][y - 1] == 2)
		&& (map[x][y + 1] == 1 || map[x][y + 1] == 2)) {
		int back = (dir + 2) % 4;

		if (back == 0 && map[x - 1][y] == 1)
			return;
		else if (back == 1 && map[x][y + 1] == 1)
			return;
		else if (back == 2 && map[x + 1][y] == 1)
			return;
		else if (back == 3 && map[x][y - 1] == 1)
			return;

		if (back == 0)
			solve(x - 1, y, dir);
		else if (back == 1)
			solve(x, y + 1, dir);
		else if (back == 2)
			solve(x + 1, y, dir);
		else if (back == 3)
			solve(x, y - 1, dir);
	}
	else {
		int left = dir - 1;
		if (left == -1)
			left = 3;

		if (left == 0) {
			if (map[x - 1][y] == 0) {
				cnt++;
				map[x - 1][y] = 2;
				solve(x - 1, y, left);
			}
			else
				solve(x, y, left);
		}
		else if (left == 1) {
			if (map[x][y + 1] == 0) {
				cnt++;
				map[x][y + 1] = 2;
				solve(x, y + 1, left);
			}
			else
				solve(x, y, left);
		}
		else if (left == 2) {
			if (map[x + 1][y] == 0) {
				cnt++;
				map[x + 1][y] = 2;
				solve(x + 1, y, left);
			}
			else
				solve(x, y, left);
		}
		else if (left == 3) {
			if (map[x][y - 1] == 0) {
				cnt++;
				map[x][y - 1] = 2;
				solve(x, y - 1, left);
			}
			else
				solve(x, y, left);
		}
	}
}

int main() {
	scanf("%d", &N); scanf("%d", &M);
	int r, c, d;
	scanf("%d", &r); scanf("%d", &c); scanf("%d", &d);

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			scanf("%d", &map[i][j]);
	map[r][c] = 2;
	solve(r, c, d);
	printf("%d\n", cnt);
}