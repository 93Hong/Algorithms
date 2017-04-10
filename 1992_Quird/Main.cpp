#include <cstdio>
#pragma warning(disable: 4996)

using namespace std;

int map[65][65], cur = 0;
char re[1000000];

int solve(int x, int y, int n) {
	if (n == 1) {
		re[cur++] = map[x][y] + 48;
		return map[x][y];
	}

	int init = map[x][y], m = n / 2;
	bool check = true;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (init != map[x + i][y + j]) {
				check = false;
				break;
			}
		}
	}

	if (!check) {
		re[cur++] = '(';
		solve(x, y, m);
		solve(x, y + m, m);
		solve(x + m, y, m);
		solve(x + m, y + m, m);
		re[cur++] = ')';
	}
	else {
		re[cur++] = init + 48;
		return map[x][y];
	}
}

int main() {
	int N, num;
	scanf("%d", &N);

	if (N == 1) {
		scanf("%d", &num);
		printf("%d", num);
		return 1;
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%1d", &map[i][j]);
		}
	}

	solve(0, 0, N);

	for (int i = 0; i < cur; i++) {
		printf("%c", re[i]);
	}
	return 1;
}