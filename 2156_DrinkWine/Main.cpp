#include <cstdio>
#pragma warning(disable: 4996)

int wine[10002];
int memo[10002];


int main() {
	int n;
	scanf("%d", &n);

	for (int i = 1; i <= n; i++)
		scanf("%d", &wine[i]);

	memo[1] = wine[1];
	memo[2] = wine[1] + wine[2];

	for (int i = 3; i <= n; i++) {
		memo[i] = memo[i - 1];
		if (memo[i] < memo[i - 2] + wine[i])
			memo[i] = memo[i - 2] + wine[i];
		if (memo[i] < memo[i - 3] + wine[i] + wine[i - 1])
			memo[i] = memo[i - 3] + wine[i] + wine[i - 1];
	}

	printf("%d\n", memo[n]);
}