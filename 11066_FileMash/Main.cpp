#include <cstdio>
#include <cstring>
#pragma warning(disable: 4996)

using namespace std;

int arr[501], s[501];
int n;
int d[501][501];


int go(int x, int y) {
	if (x == y)
		return 0;

	if (d[x][y])
		return d[x][y];

	for (int i = x; i <= y-1; i++) {
		int temp = go(x, i) + go(i + 1, y) + s[y] - s[x-1];
		
		if (d[x][y] == 0 || d[x][y] > temp) {
			d[x][y] = temp;
		}
	}
	return d[x][y];
}

int main() {
	int T;
	scanf("%d", &T);

	while (T--) {
		scanf("%d", &n);
		memset(d, 0, sizeof(d));
		memset(s, 0, sizeof(s));
		
		for (int i = 1; i <= n; i++) {
			scanf("%d", &arr[i]);
			s[i] = s[i-1] + arr[i];
		}

		printf("%d\n", go(1, n));
	}
}