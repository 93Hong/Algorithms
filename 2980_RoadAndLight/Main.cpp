#include <cstdio>
#include <queue>
#pragma warning(disable:4996)

using namespace std;
pair<int, int> arr[1001];

int main() {
	int N, L, D, R, G, ans = 0;
	scanf("%d %d", &N, &L);

	while (N--) {
		scanf("%d %d %d", &D, &R, &G);
		arr[D].first = R;
		arr[D].second = G;
	}

	for (int i = 0; i <= L; i++) {
		ans++;

		if (arr[i].first != 0) {
			int term = arr[i].first + arr[i].second;
			int tmp = ans % term;

			if (tmp < arr[i].first) {
				ans = ans + arr[i].first - tmp;
			}
		}
	}

	printf("%d\n", ans);
}