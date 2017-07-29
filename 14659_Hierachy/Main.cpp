#include <cstdio>
#pragma warning(disable : 4996)

using namespace std;

int main() {
	int N, cur, tmp, cnt = 0, ans = 0;

	scanf("%d", &N);
	scanf("%d", &cur);
	for (int i = 0; i < N - 1; i++) {
		scanf("%d", &tmp);
		if (cur > tmp) {
			cnt++;
		}
		else {
			if (ans < cnt)
				ans = cnt;
			cur = tmp;
			cnt = 0;
		}
	}
	if (ans < cnt)
		ans = cnt;

	printf("%d\n", ans);
}