#include <cstdio>
#include <algorithm>
#pragma warning(disable:4996)

using namespace std;

long long arr[100001];

int main() {
	int n, m;
	long long ans = 0, cur = 0;

	scanf("%d %d", &n, &m);

	for (int i = 0; i < n; i++) {
		scanf("%lld", &arr[i]);
	}

	for (int i = 0; i < m; i++) {
		ans += arr[i];
	}
	cur = ans;
	int j = 0;
	for (int i = m; i < n; i++) {
		cur = cur - arr[j++] + arr[i];
		ans = max(ans, cur);
	}

	printf("%lld\n", ans);
}