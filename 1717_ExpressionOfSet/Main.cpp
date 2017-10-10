#include <cstdio>
#pragma warning(disable:4996)

using namespace std;

int p[1000001];

int find(int x) {
	if (x == p[x])
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
	int n, m;
	scanf("%d %d", &n, &m);

	for (int i = 0; i < n; i++)
		p[i] = i;

	for (int i = 0; i < m; i++) {
		int check;
		int x, y;
		scanf("%d %d %d", &check, &x, &y);

		if (check == 0) {
			Union(x, y);
		}
		else {
			if (find(y) == find(x))
				printf("YES\n");
			else
				printf("NO\n");
		}
	}
}