#include <cstdio>
#pragma warning(disable: 4996)

using namespace std;

int arr[500001], tmp[500001];

long long solve(int start, int end) {
	if (start == end) {
		return 0;
	}
	int mid = (start + end) / 2;
	long long ans = solve(start, mid) + solve(mid + 1, end);

	int i = start;
	int j = mid + 1;
	int k = 0;

	while (i <= mid || j <= end) {
		if (i <= mid && (j > end || (arr[i] <= arr[j]))) {
			tmp[k++] = arr[i++];
		}
		else {
			ans += (long long)(mid - i + 1);
			tmp[k++] = arr[j++];
		}
	}

	for (i = start; i <= end; i++) {
		arr[i] = tmp[i - start];
	}

	return ans;
}

int main() {
	int N;
	scanf("%d", &N);

	for (int i = 0; i < N; i++)
		scanf("%d", &arr[i]);
	long long ans = solve(0, N - 1);
	printf("%lld\n", ans);
}