#include <cstdio>
#pragma warning(disable:4996)

using namespace std;

int main() {
	int ans = 0, n;
	for (int i = 0; i < 5; i++) {
		scanf("%d", &n);
		if (n < 40)
			n = 40;
		ans += n;
	}
	printf("%d\n", ans / 5);
}