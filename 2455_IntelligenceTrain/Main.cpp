#include <cstdio>
#pragma warning(disable:4996)

using namespace std;

int main() {

	int n = 4, ans = 0;
	while (n--) {
		int x, y;

		scanf("%d", &x); scanf("%d", &y);

		if (x < y) {
			ans += y - x;
		}
	}

	printf("%d\n", ans);

	return 1;
}