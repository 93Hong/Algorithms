#include <cstdio>
#include <algorithm>
#pragma warning(disable:4996)

using namespace std;

char map[51][51];

int main() {
	int N, M;
	scanf("%d %d", &N, &M);
	char c;
	for (int i = 0; i < N; i++) {
		scanf("%c", &c);
		for (int j = 0; j < M; j++) {
			scanf("%1c", &map[i][j]);
		}
	}

	int ans = 64;

	for (int i = 0; i < N - 7; i++) {
		for (int j = 0; j < M - 7; j++) {

			int minA = 0;
			for (int a = 0; a < 8; a++) {
				for (int b = 0; b < 8; b++) {
					
					if ((i + a + j + b) % 2 == 0) {
						if (map[i + a][j + b] != 'W')
							minA++;
					}
					else {
						if (map[i + a][j + b] != 'B')
							minA++;
					}

				}
			}

			int minB = 0;
			for (int a = 0; a < 8; a++) {
				for (int b = 0; b < 8; b++) {

					if ((i + a + j + b) % 2 == 0) {
						if (map[i + a][j + b] != 'B')
							minB++;
					}
					else {
						if (map[i + a][j + b] != 'W')
							minB++;
					}

				}
			}

			ans = min(ans, min(minA, minB));
			if (ans == 0)
				break;

		}
	}

	printf("%d\n", ans);
}