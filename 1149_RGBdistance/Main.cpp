#include <cstdio>
#pragma warning(disable: 4996)

using namespace std;

int main() {
	int T;
	scanf("%d", &T);

	while (T--) {

		int N, M, K;
		scanf("%d", &N); scanf("%d", &M); scanf("%d", &K);

		int home[100001], cnt = 0;
		bool check[100001];
		long int sum = 0;

		for (int i = 0; i < N; i++)
			scanf("%d", &home[i]);

		if (M == N) {
			for (int i = 0; i < N; i++)
				sum += home[i];
			if (sum < K)
				cnt++;
		}
		else {
			for (int i = 0; i < M; i++) {
				sum += home[i];
			}
			if (sum < K)
				cnt++;

			for (int i = 0; i < N - 1; i++) {
				sum -= home[i];
				sum += home[(i + M) % N];
				if (sum < K)
					cnt++;
			}
		}
		printf("%d\n", cnt);
	}
}