#include <algorithm>
#include <cstdio>
#include <memory>
#pragma warning(disable:4996)

using namespace std;

int map[101][101], map2[101][101], check[101][101];
int dir[4][2] = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };
int N;

void dfs(int x, int y) {
	for (int i = 0; i < 4; i++) {
		int xx = x + dir[i][0];
		int yy = y + dir[i][1];

		if (xx < 0 || xx >= N || yy < 0 || yy >= N)
			continue;
		if (map2[xx][yy] == 0 && check[xx][yy] == 0) {
			check[xx][yy] = 1;
			dfs(xx, yy);
		}
	}
}

int main() {
	int num, maxV = 0, minV = 110, ans = 0;
	scanf("%d", &N);
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &num);
			map[i][j] = num;
			if (num > maxV)
				maxV = num;
			if (num < minV)
				minV = num;
		}
	}

	for (int h = minV; h < maxV; h++) {
		
		//	memset(check, 0, sizeof(check));
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				check[i][j] = 0;
				map2[i][j] = 0;
			}
		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (map[i][j] <= h)
					map2[i][j] = 1;
			}
		}

		int place = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (map2[i][j] == 0 && check[i][j] == 0) {
					check[i][j] = 1;
					dfs(i, j);
					place++;
				}
			}
		}

		if (ans < place)
			ans = place;
	}

	printf("%d\n", max(ans, 1));
}