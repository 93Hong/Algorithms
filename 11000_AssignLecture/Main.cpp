#include<cstdio>
#include<algorithm>
#pragma warning(disable:4996)

using namespace std;

pair<int, int> p[400000];
int n, r;

int main() {
	scanf("%d", &n);
	for (int i = 0, s, t; i < n; i++) {
		scanf("%d %d", &s, &t);

		p[i] = { s,1 };
		p[i + n] = { t,-1 };
	}

	sort(p, p + 2 * n);

	for (int i = 0, s = 0; i < 2 * n; i++)
		r = max(r, s += p[i].second);

	printf("%d", r);
	return 0;
}
