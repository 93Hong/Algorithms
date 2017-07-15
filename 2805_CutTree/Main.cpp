#include <cstdio>
#include <algorithm>
#pragma warning(disable: 4996)

using namespace std;

int tree[1000001];

int main() {
	int N, M, maxHight = 0;
	scanf("%d", &N);
	scanf("%d", &M);

	for (int i = 0; i < N; i++) {
		scanf("%d", &tree[i]);
		if (tree[i] > maxHight)
			maxHight = tree[i];
	}
	int left = 0, right = maxHight, ans = 0;

	while (left <= right) {
		int mid = (left + right) / 2;
		long tmp = 0;
		//printf("%d %d %d\n", left, mid, right);
		for (int i = 0; i < N; i++) {
			if (mid < tree[i]) {
				tmp += (tree[i] - mid);
			}
		}
		if (tmp >= M) {
			ans = max(ans, mid);
			left = mid + 1;
		}
		else {
			right = mid + 1;
		}
	}
	printf("%d\n", ans);
}