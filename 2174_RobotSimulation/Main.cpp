#include <cstdio>
#include <algorithm>
#pragma warning(disable:4996)

using namespace std;

int idMap[103][103];
char rotation[4] = { 'E', 'S', 'W', 'N' };
char dirMap[103];
pair<int, int> locMap[103];
int dir[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };

int getDir(char dir) {
	if (dir == 'E')
		return 0;
	else if (dir == 'S')
		return 1;
	else if (dir == 'W')
		return 2;
	return 3;
}

int main() {
	int A, B, N, M;
	bool crashWall = false, crashRobot = false;
	scanf("%d %d", &A, &B);
	scanf("%d %d", &N, &M);

	for (int i = 1; i <= N; i++) {
		int y, x;
		char c;
		scanf("%d %d %c", &y, &x, &c);
		dirMap[i] = c;
		locMap[i] = make_pair(B - x + 1, y);
		idMap[B - x + 1][y] = i;
	}

	int idX, idY;
	while (M--) {
		int time;
		char order;
		scanf("%d %c %d", &idX, &order, &time);

		if (order == 'F') {
			char c = dirMap[idX];
			int cur = getDir(c);

			int x = locMap[idX].second, y = locMap[idX].first;
			idMap[y][x] = 0;
			//printf("y x : %d %d\n", y, x);

			for (int i = 0; i < time; i++) {
				
				x += dir[cur][1];
				y += dir[cur][0];

				if (y < 1 || y >= B + 1 || x < 1 || x >= A + 1) {
					crashWall = true;
					break;
				}

				if (idMap[y][x] != 0) {
					crashRobot = true;
					idY = idMap[y][x];
					break;
				}
			}
			idMap[y][x] = idX;
			locMap[idX].second = x;
			locMap[idX].first = y;

		}
		else if (order == 'R') {
			time %= 4;
			int cur = getDir(dirMap[idX]);
			dirMap[idX] = rotation[(cur + time) % 4];
		}
		else if (order == 'L') {
			time %= 4;
			int cur = getDir(dirMap[idX]);

			cur -= time;
			if (cur < 0) cur += 4;
			dirMap[idX] = rotation[(cur) % 4];
		}

		if (crashWall || crashRobot)
			break;
	}

	if (crashWall) {
		printf("Robot %d crashes into the wall\n", idX);
	}
	else if (crashRobot) {
		printf("Robot %d crashes into robot %d\n", idX, idY);
	}
	else {
		printf("OK\n");
	}
}