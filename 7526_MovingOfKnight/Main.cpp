#include <cstdio>
#include <cstring>
#include <queue>
#pragma warning(disable:4996)

using namespace std;
int map[301][301];
int night[8][2] = { { 1, -2 },{ 1, 2 },{ 2, -1 },{ 2, 1 },{ -1, 2 },{ -1, -2 },{ -2, 1 },{ -2, -1 } };

int solve(int m, int x, int y, int dx, int dy) {
	memset(map, 0, sizeof(map));
	queue<pair<pair<int, int>, int>> q;

	q.push(make_pair(make_pair(x, y), 0));

	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int dis = q.front().second;
		map[x][y] = 1;

		if (x == dx && y == dy)
			break;
		q.pop();

		for (int i = 0; i < 8; i++) {
			int xx = x + night[i][0];
			int yy = y + night[i][1];
			
			if (xx < 0 || xx >= m || yy < 0 || yy >= m)
				continue;

			if (map[xx][yy] == 0) {
				q.push(make_pair(make_pair(xx, yy), dis + 1));
				map[xx][yy] = 1;
			}
		}
	}

	return q.front().second;
}

int main() {
	int n, m;

	scanf("%d", &n);

	while (n--) {
		int x, y, dx, dy;
		scanf("%d", &m);
		scanf("%d %d", &x, &y);
		scanf("%d %d", &dx, &dy);

		printf("%d\n", solve(m, x, y, dx, dy));
	}
}