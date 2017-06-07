#include <cstdio>
#pragma warning (disable :4996)

using namespace std;

int s[21];
bool check[21];

int main() {
	int N, M, ans2[21];
	long long ans = 0, k;
	scanf("%d", &N); scanf("%d", &M);

	long long fac[21];
	fac[0] = 1; fac[1] = 1;
	for (int i = 1; i <= 20; i++)
		fac[i] = fac[i - 1] * i;

	if (M == 1) {
		scanf("%lld", &k);
		for (int i = 0; i < N; i++)
			for (int j = 1; j <= N; j++) {
				if (check[j] == true)
					continue;
				if (k > fac[N - i - 1])
					k -= fac[N - i - 1];
				else {
					check[j] = true;
					ans2[i] = j;
					break;
				}
			}
		for (int i = 0; i < N - 1; i++)
			printf("%d ", ans2[i]);
		printf("%d\n", ans2[N - 1]);
	}
	else {
		for (int i = 0; i < N; i++)
			scanf("%d", &s[i]);
		for (int i = 0; i < N; i++) {
			for (int j = 1; j < s[i]; j++)
				if (check[j] == false)
					ans += fac[N - i - 1];
			check[s[i]] = true;
		}
		printf("%lld\n", ans + 1);
	}
	return 0;
}