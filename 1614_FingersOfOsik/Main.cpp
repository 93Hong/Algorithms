#include <cstdio>
#pragma warning(disable:4996)

using namespace std;

int main() {
	long long ans = 0;
	long long finger, count;

	scanf("%lld", &finger);
	scanf("%lld", &count);

	if (finger == 1 && count == 0)
		printf("0\n");
	else {
		if (finger == 1) {
			ans = 8 * (count);
		}
		else if (finger == 2) {
			ans = (count / 2) * 8 + 1 + (count % 2) * 6;
		}
		else if (finger == 3) {
			ans = (count / 2) * 8 + 2 + (count % 2) * 4;
		}
		else if (finger == 4) {
			ans = (count / 2) * 8 + 3 + (count % 2) * 2;
		}
		else {
			ans = 8 * (count) + 4;
		}

		printf("%lld\n", ans);
	}
}