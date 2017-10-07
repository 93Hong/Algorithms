#include <cstdio>
#include <stack>
#pragma warning(disable:4996)

using namespace std;

stack<int> s[6];

int main() {
	int N, P;
	scanf("%d %d", &N, &P);

	int ans = 0;

	for (int i = 0; i < N; i++) {
		int a, b;
		bool flag = false;
		scanf("%d %d", &a, &b);

		if (s[a - 1].empty()) {
			s[a - 1].push(b);
			ans++;
			continue;
		}

		if (s[a - 1].top() > b) {
			while (!s[a - 1].empty() && s[a - 1].top() > b) {
				s[a - 1].pop();
				ans++;
			}
			if (!s[a - 1].empty() && s[a - 1].top() == b) {
				continue;
			}
			s[a - 1].push(b);
			ans++;
		}
		else if (s[a - 1].top() == b)
			continue;
		else {
			s[a - 1].push(b);
			ans++;
		}
	}

	printf("%d\n", ans);
}