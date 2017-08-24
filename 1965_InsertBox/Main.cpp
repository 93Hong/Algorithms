#include <cstdio>
#pragma warning(disable:4996)

using namespace std;

int arr[1001], dp[1001];

int main() {
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}

	for (int i = 0; i < n; i++) {
		int max = 0;
		for (int j = 0; j < i; j++) {
			if (arr[i] > arr[j]) {
				if (max < dp[j]) {
					max = dp[j];
				}
			}
		}
		dp[i] = max + 1;
	}

	int ans = 0;
	for (int i = 0; i < n; i++)
		if (ans < dp[i])
			ans = dp[i];

	printf("%d\n", ans);
}