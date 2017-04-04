#include <cstdio>
#pragma warning(disable: 4996)

using namespace std;

int mat[7][7];

int main() {
	int dir[4][2] = { {0, -1}, {-1, 0 }, {0, 1}, {1, 0} };

	int n = 3, x, y;
	int start = (2 * n + 1)*(2 * n + 1);
	x = n*2; y = n*2;

	for (int i = 0; i < n * 2 + 1; i++) {
		for (int j = 0; j < n * 2 + 1; j++) {
			printf("%3d", mat[i][j]);
		}
		printf("\n");
	}

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 2 * n; j++) {
			if (mat[x][y] == 0) {
				mat[x][y] = start;
			}
			x += dir[i][0];
			y += dir[i][1];
			start--;
		}
		
	}

	for (int i = 0; i < n*2+1; i++) {
		for (int j = 0; j < n*2+1; j++) {
			printf("%3d", mat[i][j]);
		}
		printf("\n");
	}
}