#include <cstdio>
#pragma warning(disable: 4996)

using namespace std;

int bt[6][6] = { 0 };
int at[6][6] = { 0 };
int n = 6, k = 2, ax = 1, ay = 2, bx = 0, by = 5;
int dir[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };

void fill(int x, int y) {
	if (x < 0 | y < 0 | x >= n | y >= n)
		return;

}

int main() {
	int board[6][6] = { {0, 0, 1, 0, 0, 0}, {0, 2, 0, 0, 0, 1}, {0, 0, 2, 1, 0, 0}, {0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 1, 0}, {0, 1, 0, 0, 0, 0} };


	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (board[i][j] == 1) {
				at[i][j] = 1;
				for (int q = 0; q < 4; q++) {
					for (int w = 1; w <= k; w++) {
						int x = i + dir[q][0] * w;
						int y = j + dir[q][1] * w;
						
						if (x < 0 | y < 0 | x >= n | y >= n)
							continue;
						if (board[x][y] == 2)
							break;
						at[x][y] = 1;
					}
					
				}
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%d", at[i][j]);
		}
		printf("\n");
	}
}