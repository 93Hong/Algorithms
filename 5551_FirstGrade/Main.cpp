#include <cstdio>
#pragma warning(disable:4996)

using namespace std;

long long dp[101][21];
int arr[101];

int main() {
	int N, mk;
	scanf("%d", &N);

	for (int i = 0; i < N - 1; i++) {
		scanf("%d", &arr[i]);
	}
	scanf("%d", &mk);

	dp[0][arr[0]] = 1;
	for (int i = 1; i < N - 1; i++) {
		for (int j = 0; j < 21; j++) {
			if (dp[i - 1][j] > 0) {
				if (j + arr[i] < 21)
					dp[i][j + arr[i]] += (long long)dp[i - 1][j];
				if (j - arr[i] >= 0)
					dp[i][j - arr[i]] += (long long)dp[i - 1][j];
			}
		}
	}
	printf("%lld\n", dp[N-2][mk]);
}