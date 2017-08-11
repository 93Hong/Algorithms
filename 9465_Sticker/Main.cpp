#include <cstdio>
#include <algorithm>

using namespace std;

int D[100001][2], s[100001][2];

int main() {
	int T, n;
	scanf("%d", &T);

	while (T--) {
		scanf("%d", &n);
		for (int i = 0; i<n; i++) {
			scanf("%d", &s[i][0]);
			D[i][0] = 0;
		}
		for (int i = 0; i<n; i++)
			scanf("%d", &s[i][1]);

		D[0][0] = s[0][0];
		D[0][1] = s[0][1];

		for (int i = 1; i<n; i++) {
			D[i][0] = max(D[i - 1][0], D[i - 1][1] + s[i][0]);
			D[i][1] = max(D[i - 1][1], D[i - 1][0] + s[i][1]);
		}

		printf("%d\n", max(D[n - 1][0], D[n - 1][1]));
	}
}