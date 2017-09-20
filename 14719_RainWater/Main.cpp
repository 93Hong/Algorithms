#include <cstdio>
#include <queue>
#include <algorithm>
#pragma warning(disable:4996)

using namespace std;

queue<int> q;

int main() {
	int H, W, tmp, ans = 0;
	scanf("%d %d", &H, &W);

	for (int i = 0; i < W; i++) {
		scanf("%d", &tmp);
		if (q.empty()) {
			if (tmp > 0)
				q.push(tmp);
		}
		else {
			if (q.front() > tmp) {
				q.push(tmp);
			}
			else {
				int sum = 0, cnt = 0, left = q.front();
				if (i == W - 1 && q.front() > tmp) {

				}
				else {
					while (!q.empty()) {
						sum += q.front();
						q.pop();
						cnt++;
					}
					ans += (left * (cnt - 1) - (sum - left));
				}
			}
		}
	}

	printf("%d\n", ans);
}