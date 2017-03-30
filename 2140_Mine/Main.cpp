#include <cstdio>
#include <cstring>
#pragma warning(disable: 4996)

using namespace std;

int main() {
	int N, mine = 0;
	scanf("%d", &N);

	if (N < 3) {
		printf("0\n");
		return 0;
	}

	char **map2 = new char*[N];
	for (int i = 0; i < N; ++i)
		map2[i] = new char[N];

	int **map = new int*[N];
	for (int i = 0; i < N; ++i)
		map[i] = new int[N];

	for (int i = 0; i < N; i++)
		scanf("%s", map2[i]);

	printf("\n");

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map2[i][j] != '#') {
				map[i][j] = (int)map2[i][j] - '0';
			}
			else
				map[i][j] = 0;
			printf("%d", map[i][j]);
		}
		printf("\n");
	}

	int k[4][2] = { {0, 1}, {1, 0}, {0, 1}, {1, 0} };
	int i, j;

	for (int b = 0; b < 4; b++) {
		if (b == 0) {
			i = k[b][0]; j = k[b][1];
		}
		else if (b == 1) {
			i = k[b][0]; j = N - 1;
		}
		else if (b == 2) {
			i = N - 1; j = k[b][1];
		}
		else if (b == 3) {
			i = k[b][0]; j = k[b][1];
		}
		
		for (int a = 0; a < N - 2; a++) {
			printf("%d", map[i][j]);
			if (map[i][j] == 1) {
				if (map[i - k[b][0]][j - k[b][1]] == 0)
					mine++;
			}
			else if (map[i][j] == 2) {
				if (map[i - k[b][0]][j - k[b][1]] != 3)
					mine++;
			}
			else if (map[i][j] == 3) {
				mine++;
			}
			i += k[b][0];
			j += k[b][1];
		}
		printf("\n");
	}
	printf("%d", mine);
}