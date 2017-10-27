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

	int ans = 0;
	long long tmp = 0;
	for (int i = 0; i < N; i++) {
		tmp = 0;
		for (int j = i; j < N; j++) {
			tmp += arr[j];
			if (M < tmp)
				break;
			if (M == tmp) {
				ans++;
				break;
			}
		}
	}

	printf("%d\n", ans);
}