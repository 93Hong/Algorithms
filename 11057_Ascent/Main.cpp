#include <cstdio>
#pragma warning(disable: 4996)

using namespace std;
int d[1001][1001];

int main() {
	int N;
	scanf("%d", &N);

	for (int i = 0; i < 10; i++)
		d[1][i] = 1;

	for (int i = 2; i <= N; i++) {
		for (int j = 0; j <= 9; j++) {
			for (int k = 0; k <= j; k++) {
				d[i][j] += d[i - 1][k];
				d[i][j] %= 10007;
			}
		}
	}

	long long ans = 0;
	for (int i = 0; i < 10; i++)
		ans += d[N][i];
	ans %= 10007;

	printf("%lld\n", ans);
}