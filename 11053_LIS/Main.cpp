#include <cstdio>
#pragma warning(disable: 4996)

using namespace std;

int num[1001];
int dp[1001];

int main() {
	int N;
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%d", &num[i]);
		dp[i] = 1;
	}

	int max = 0;

	for (int i = 1; i < N; i++) {
		for (int j = 0; j < i; j++) {
			if (dp[i] < dp[j] + 1 && num[i] > num[j]) {
				dp[i] = dp[j] + 1;
			}
		}
	}

	for (int i = 0; i < N; i++)
		if (max < dp[i])
			max = dp[i];

	printf("%d\n", max);
}