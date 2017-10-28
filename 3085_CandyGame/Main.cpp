#include <cstdio>
#pragma warning(disable:4996)

using namespace std;

char map[51][51];
int dir[2][2] = { {0, 1}, {1, 0} };

int main() {
	int N;
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%1c", &map[i][j]);
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < 2; k++) {
				int ii = i + dir[k][0];
				int jj = j + dir[k][1];

				if (ii < 0 || ii >= N || jj < 0 || jj >= N)
					continue;
				if (map[i][j] != map[ii][jj]) {
					char c = map[i][j];
					map[i][j] = map[ii][jj];
					map[ii][jj] = c;
				}
				else
					continue;

				for (int a = 0; a < N; a++) {
					for (int b = 0; b < N; b++) {

					}
				}

				char c = map[i][j];
				map[i][j] = map[ii][jj];
				map[ii][jj] = c;
			}

		}
	}
}