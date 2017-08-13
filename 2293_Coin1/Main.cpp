#include <cstdio>
#pragma warning(disable:4996)

using namespace std;

int d[10001], coin[101], d2[10001];

int main() {
	int n, k;
	scanf("%d", &n); scanf("%d", &k);

	for (int i = 1; i <= n; i++)
		scanf("%d", &coin[i]);

	d[0] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= k; j++) {
			if (j - coin[i] >= 0) {
				d[j] += d[j - coin[i]];
			}
		}
	}
	printf("\n\n");

	for (int i = 0; i <= k; i++)
		printf("%d\n", d[i]);

	d2[0] = 1;
	for (int j = 0; j <= k; j++) {
		for (int i = 1; i <= n; i++) {
			if (j - coin[i] >= 0) {
				d2[j] += d2[j - coin[i]];
			}
		}
	}
	printf("\n\n");

	for (int i = 0; i <= k; i++)
		printf("%d\n", d2[i]);
}