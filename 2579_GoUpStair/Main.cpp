#include <cstdio>
#include <algorithm>
#pragma warning(disable: 4996)

using namespace std;
int stair[10002], dp[10002];

int main() {
	int N;
	scanf("%d", &N);
	for (int i = 1; i < N + 1; i++) {
		scanf("%d", &stair[i]);
	}
	
	dp[1] = stair[1];
	dp[2] = stair[2] + stair[1];

	for (int i = 3; i < N + 1; i++) {
		if (dp[i] < dp[i - 3] + stair[i - 1] + stair[i])
			dp[i] = dp[i - 3] + stair[i - 1] + stair[i];
		if (dp[i] < dp[i - 2] + stair[i])
			dp[i] = dp[i - 2] + stair[i];
	}

	printf("%d\n", dp[N]);
}