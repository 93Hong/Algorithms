#include <cstdio>
#include <algorithm>

using namespace std;


int D[1001][3], home[1001][3];

int main() {
	int N;
	scanf("%d", &N);

	for (int i = 0; i<N; i++) {
		for (int j = 0; j<3; j++) {
			scanf("%d", &home[i][j]);
		}
	}

	D[0][0] = home[0][0];
	D[0][1] = home[0][1];
	D[0][2] = home[0][2];

	for (int i = 1; i<N; i++) {
		D[i][0] = min(D[i - 1][1], D[i - 1][2]) + home[i][0];
		D[i][1] = min(D[i - 1][0], D[i - 1][2]) + home[i][1];
		D[i][2] = min(D[i - 1][0], D[i - 1][1]) + home[i][2];
	}

	printf("%d\n", min(min(D[N - 1][0], D[N - 1][1]), D[N - 1][2]));

}