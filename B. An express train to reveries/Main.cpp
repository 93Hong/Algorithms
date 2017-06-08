#include <cstdio>
#pragma warning(disable:4996)

using namespace std;

int a[2001], b[2001], c[2001] = {};
bool check[2001] = { false };

int main() {
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	for (int i = 0; i < n; i++)
		scanf("%d", &b[i]);

	for (int i = 0; i < n; i++) {
		if (a[i] == b[i]) {
			check[a[i] - 1] = true;
			c[i] = a[i];
		}
	}

	int k = 0;
	for (int i = 0; i < n; i++) {
		if (c[i] == 0) {
			for (int j = k; j < n; j++) {
				if (check[j] == false) {
					k = j;
					check[j] = true;
					break;
				}
			}
			c[i] = k + 1;
		}
	}

	for (int i = 0; i < n; i++)
		printf("%d ", c[i]);
}