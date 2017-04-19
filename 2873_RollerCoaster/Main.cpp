#include <cstdio>
#pragma warning(disable: 4996)

using namespace std;

int map[1001][1001];

int main() {
	int R, C;
	scanf("%d", &R); scanf("%d", &C);

	for (int i = 0; i < R; i++)
		for (int j = 0; j < C; j++)
			scanf("%d", &map[i][j]);

	if (R % 2 == 0 && C % 2 == 0) {
		int minX, minY, min = 2000;
		for (int i = 0; i < R; i++)
			for (int j = i % 2 == 0 ? 1 : 0; j < C; j += 2) {
				printf("%d %d\n", i, j);
				if (map[i][j] < min) {
					minX = i;
					minY = j;
					min = map[i][j];
				}
			}
		printf("%d %d %d\n", minX, minY, min);
	}


}