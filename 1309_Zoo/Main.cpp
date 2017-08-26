#include <cstdio>
#pragma warning(disable:4996)

using namespace std;

long long int dp[100001];

int main() {
	int n;
	scanf("%d", &n);

	dp[0] = 3;
	dp[1] = 7;

	for (int i = 2; i < n; i++) {
		dp[i] = ((dp[i - 1] * 2)%9901 + (dp[i - 2])%9901)%9901;
	}
	printf("%d\n", dp[n - 1]);
}