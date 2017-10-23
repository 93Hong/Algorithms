#include <cstdio>
#include <queue>
#pragma warning(disable:4996)

using namespace std;

int night[8][2] = { { 1, -2 },{ 1, 2 },{ 2, -1 },{ 2, 1 },{ -1, 2 },{ -1, -2 },{ -2, 1 },{ -2, -1 } };
int map[401][401];

int r, c;
void solve(int x, int y, int dx, int dy) {
	queue < pair<pair<int, int>, int>> q;
	q.push(make_pair(make_pair(x, y), 0));
	int dis, m = 0;
	bool finish = false;
	long long num = 0;

	while (!q.empty()) {
		x = q.front().first.first;
		y = q.front().first.second;
		map[x][y] = 1;
		dis = q.front().second;

		if (x == dx && y == dy) {
			if (m == 0) {
				m = dis;
				num++;
			}
			else if (dis == m) {
				num++;
			}
			else if (dis > m)
				break;
		}
		q.pop();

		for (int i = 0; i < 8; i++) {
			int xx = x + night[i][0];
			int yy = y + night[i][1];

			if (xx < 1 || xx > r || yy < 1 || yy > c)
				continue;

			if (map[xx][yy] == 0 || (xx == dx && yy == dy)) {
				map[xx][yy]++;
				q.push(make_pair(make_pair(xx, yy), dis + 1));
			}
		}
	}

	if (m != 0) {
		printf("%d %lld\n", m, num%1000000009);
	}
	else
		printf("None\n");
}

int main() {
	scanf("%d %d", &r, &c);

	solve(1, 1, r, c);
}