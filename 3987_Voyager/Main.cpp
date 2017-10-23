#include <cstdio>
#include <algorithm>
#include <stack>
#include <cstring>
#pragma warning(disable:4996)

using namespace std;

char map[502][502];
bool check[502][502];
int dir[4][2] = { {0, 1}, {0, -1}, { -1, 0 }, {1, 0} }, val[4];
char re[4] = {'R', 'L', 'U', 'D'}; // 2 0 3 1
int	N, M, PR, PC;

int left(int cursor) { // '/'
	if (cursor < 2)
		return cursor + 2;
	return cursor - 2;
}

int right(int cursor) { // '\'
	if (cursor == 0)
		return 3;
	else if (cursor == 1)
		return 2;
	else if (cursor == 2)
		return 1;
	return 0;
}

int solve(int d) {
	stack<pair<int, int>> s;
	s.push(make_pair(PR, PC));
	int cnt = 1;
	bool flag = false;
	
	memset(check, 0, sizeof(check));
	//check[PR][PC] = true;

	while (!s.empty()) {
		
		int x = s.top().first + dir[d][0];
		int y = s.top().second + dir[d][1];
		s.pop();

		if (x <= 0 || x > N || y <= 0 || y > M || map[x][y] == 'C')
			break;
		if (check[x][y]) {
			return -1;
		}

		if (map[x][y] == '\\') {
			d = right(d);
		}
		else if (map[x][y] == '/') {
			d = left(d);
		}
		else
			check[x][y] = true;

		s.push(make_pair(x, y));
		cnt++;
	}

	return cnt;
}

int getMax(int a, int b, int c, int d) {
	int maxV = max(max(a, b), max(c, d));
	if (maxV == c)// 2031
		return 2;
	else if (maxV == a)
		return 0;
	else if (maxV == d)
		return 3;
	return 1;
}

int getVo(int a, int b, int c, int d) {
	if (c == -1)
		return 2;
	else if (a == -1)
		return 0;
	else if (d == -1)
		return 3;
	return 1;
}

int main() {
	char c;
	scanf("%d %d", &N, &M);

	for (int i = 1; i <= N; i++) {
		scanf("%c", &c);
		for (int j = 1; j <= M; j++)
			scanf("%1c", &map[i][j]);
	}
	scanf("%d %d", &PR, &PC);
	//PR--;
	//PC--;

	val[0] = solve(0);
	val[1] = solve(1);
	val[2] = solve(2);
	val[3] = solve(3);

	/*
	printf("%c %d\n", re[0], val[0]);
	printf("%c %d\n", re[1], val[1]);
	printf("%c %d\n", re[2], val[2]);
	printf("%c %d\n", re[3], val[3]);
	*/

	if (val[0] == -1 || val[1] == -1 || val[2] == -1 || val[3] == -1)
		printf("%c\nVoyager\n", re[getVo(val[0], val[1], val[2], val[3])]);
	else {
		int index = getMax(val[0], val[1], val[2], val[3]);
		printf("%c\n%d\n", re[index], val[index]);
	}
}