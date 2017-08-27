#include <cstdio>
#include <algorithm>
#include <cstring>
#pragma warning(disable: 4996)

using namespace std;

int arr[1001], dp[1001];

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
		dp[i] = 10000000;
	}

	dp[0] = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 1; j <= arr[i]; j++) {
			dp[i + j] = min(dp[i] + 1, dp[i + j]);
		}
	}
	if (dp[n - 1] != 10000000)
		printf("%d\n", dp[n - 1]);
	else
		printf("-1\n");

}