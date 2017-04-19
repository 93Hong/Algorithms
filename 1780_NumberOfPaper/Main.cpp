#include <cstdio>
#pragma warning(disable: 4996)

using namespace std;

int map[2300][2300];
int re[3];

void solve(int x, int y, int n) {
	int cur = map[x][y];
	bool flag = false;

	if (n == 1) {
		re[cur + 1]++;
		return;
	}

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (cur != map[x+i][y+j]) {
				flag = true;
				break;
			}

	if (!flag) {
		re[cur + 1]++;
		return;
	}

	int m = n / 3;

	solve(x, y, m);
	solve(x + m, y, m);
	solve(x + 2 * m, y, m);
	solve(x, y + m, m);
	solve(x + m, y + m, m);
	solve(x + 2 * m, y + m, m);
	solve(x, y + 2 * m, m);
	solve(x + m, y + 2 * m, m);
	solve(x + 2 * m, y + 2 * m, m);

	return;
}

int main() {
	int N;
	scanf("%d", &N);

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			scanf("%d", &map[i][j]);

	solve(0, 0, N);

	printf("%d\n%d\n%d\n", re[0], re[1], re[2]);
}