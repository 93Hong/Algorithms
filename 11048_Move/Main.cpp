#include <cstdio>
#include <algorithm>
#include <string.h>
#pragma warning(disable:4996)

using namespace std;

int candy[1001][1001];

int main() {
	int N, M;
	scanf("%d", &N);
	scanf("%d", &M);

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			scanf("%d", &candy[i][j]);
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			candy[i][j] = max(candy[i][j - 1], candy[i - 1][j]) + candy[i][j];
		}
	}

	printf("%d\n", candy[N][M]);

	return 0;
}