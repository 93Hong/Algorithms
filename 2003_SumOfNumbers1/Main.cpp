#include <cstdio>
#pragma warning(disable:4996)

using namespace std;

int arr[10001];

int main() {
	int N;
	long long M;
	scanf("%d %lld", &N, &M);

	for (int i = 0; i < N; i++)
		scanf("%d", &arr[i]);

	int ans = 0, l = 0, r = 0;
	long long tmp = 0;

	while (1) {
		if (tmp >= M)
			tmp -= arr[l++];
		else if (r == N)
			break;
		else
			tmp += arr[r++];

		if (tmp == M)
			ans++;
	}

	printf("%d\n", ans);
}