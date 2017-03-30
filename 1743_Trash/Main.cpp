
#include <cstdio>
#include <cstring>
#pragma warning(disable: 4996)

using namespace std;

int main() {
	int M=0, N, K, x, y;
	scanf("%d", &M); scanf("%d", &N); scanf("%d", &K);

	int map[101][101], tmp[100], re[100], max = 0;
	memset(map, 0, sizeof(map));
	memset(tmp, 0, sizeof(tmp));
	memset(re, 0, sizeof(re));

	for (int i = 0; i < K; i++) {
		scanf("%d", &x); scanf("%d", &y);
		map[x-1][y-1] = 1;
	}

	int cur = 0, cnt = 0, val=0;
	bool flag = true;
	
	for (int a = 0; a < M; a++) {
		for (int i = 0; i < N + 1; i++) {
			if ((map[a][i] == 0 && !flag)) {
				if (max < cnt)
					max = cnt;
				for (int j = 0; j < cnt; j++) {
					map[a][j + cur] = val;
				}
				flag = true;
				cur = 0;
				cnt = 0;
				val = 0;
			}
			else if (map[a][i] != 0) {
				cnt++;
				val += map[a][i];
				if (flag) {
					cur = i;
					flag = false;
				}
			}
		}

		for (int j = 0; j < N; j++) {
			printf("%d", map[a][j]);
		}
		printf("\n");

		for (int j = 0; j < N; j++) {
			if (map[a+1][j]) {
				map[a+1][j] += map[a][j];
				if (max < map[a+1][j])
					max = map[a+1][j];
			}
		}
		for (int j = 0; j < N; j++) {
			printf("%d", map[a+1][j]);
		}
		printf("\n");
	}

	printf("%d\n", max);
}