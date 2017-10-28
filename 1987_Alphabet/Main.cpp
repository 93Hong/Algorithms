#include <string>
#include <cstdio>
#pragma warning(disable:4996)

using namespace std;

char map[21][21];
int R, C, alpha[27], maxV = -1;
int dir[4][2] = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };

void solve(int x, int y, int cur) {
	if (cur >= maxV)
		maxV = cur;

	for (int i = 0; i < 4; i++) {
		int xx = x + dir[i][0];
		int yy = y + dir[i][1];

		if (xx < 0 || xx >= R || yy < 0 || yy >= C)
			continue;
		if (alpha[map[xx][yy] - 'A'] == 0) {
			alpha[map[xx][yy] - 'A'] = 1;
			solve(xx, yy, cur + 1);
			alpha[map[xx][yy] - 'A'] = 0;
		}
	}
}

int main() {
	scanf("%d %d", &R, &C);
	char c;

	for (int i = 0; i < R; i++) {
		scanf("%c", &c);
		for (int j = 0; j < C; j++) {
			scanf("%1c", &map[i][j]);
		}
	}

	alpha[map[0][0] - 'A'] = 1;
	solve(0, 0, 1);
	printf("%d\n", maxV);
}