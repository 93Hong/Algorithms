#include <cstdio>
#pragma warning(disable:4996)

using namespace std;

int dp[5001], arr[5001];

int main() {
	long long int n;
	int div = 1000000;
	char s[32];

	scanf("%lld", &n);
	int len = sprintf(s, "%lld", n);

	for (int i = len - 1; i >= 0; i--) {
		arr[i] = n % 10;
		n /= 10;
	}

	dp[0] = 1;
	dp[1] = 1;
	if (arr[0] * 10 + arr[1] <= 26)
		dp[1]++;

	printf("%d\n", len);
	for (int i = 0; i < len; i++) {
		printf("%d ", arr[i]);
	}

	for (int i = 2; i < len; i++) {
		if (arr[i - 1] * 10 + arr[i] <= 26)
			dp[i] = dp[i - 1] % div + dp[i - 2] % div;
		else
			dp[i] = dp[i - 1] % div;
		dp[i] %= div;
	}

	printf("%d\n", dp[len - 1] % div);
}