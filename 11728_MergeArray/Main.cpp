#include <cstdio>
#pragma warning(disable: 4996)

using namespace std;

int a1[1000001], a2[1000002], re[2000002];

int main() {
	int N, M, K;
	scanf("%d", &N); scanf("%d", &M);
	K = N + M;

	for (int i = 0; i < N; i++)
		scanf("%d", &a1[i]);
	for (int i = 0; i < M; i++)
		scanf("%d", &a2[i]);

	int i = 0, j = 0, cur = 0;

	while (M > 0 && N > 0)
		if (a1[i] > a2[j]) {
			re[cur++] = a2[j++];
			M--;
		}
		else {
			re[cur++] = a1[i++];
			N--;
		}
	while (N--)	re[cur++] = a1[i++];
	while (M--) re[cur++] = a2[j++];

	for (int k = 0; k < K; k++)
		printf("%d ", re[k]);
}