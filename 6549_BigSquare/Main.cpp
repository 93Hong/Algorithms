#include <cstdio>
#include <stack>
#include <algorithm>
#pragma warning(disable:4996)

using namespace std;

long long h[100001];

int main() {
	int n;

	while (1) {
		scanf("%d", &n);
		if (n == 0)
			break;
		stack<long long> st;
		for (int i = 0; i < n; i++)
			scanf("%lld", &h[i]);
		long long ans = 0;

		for (int i = 0; i < n; i++) {
			while (!st.empty() && h[st.top()] > h[i]) {
				long long height = h[st.top()];
				st.pop();
				long long width = i;
				if (!st.empty())
					width = i - st.top() - 1;
				long long v = height * width;
				ans = max(ans, v);
			}
			st.push(i);
		}

		while (!st.empty()) {
			long long height = h[st.top()];
			st.pop();
			long long width = n;
			if (!st.empty())
				width = n - st.top() - 1;
			long long v = height * width;
			ans = max(ans, v);
		}

		printf("%lld\n", ans);
	}
}