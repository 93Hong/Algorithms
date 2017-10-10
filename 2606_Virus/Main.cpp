#include <cstdio>
#pragma warning(disable:4996)

using namespace std;

int p[101];

int find(int x) {
	if (p[x] == x)
		return x;
	else
		return p[x] = find(p[x]);
}

void Union(int x, int y) {
	x = find(x);
	y = find(y);
	if (x != y)
		p[y] = x;
}

int main() {
	int m, n;
	scanf("%d %d", &m, &n);

	for (int i = 0; i <= m; i++)
		p[i] = i;

	while (n--) {
		int x, y;
		scanf("%d %d", &x, &y);

		Union(x, y);
	}
	int ans = 0;
	for (int i = 0; i <= m; i++) {
		if (find(i) == find(1))
			ans++;
	}
	printf("%d\n", ans - 1);
}