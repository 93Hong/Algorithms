#include <cstdio>
#include <stack>
#include <algorithm>
#pragma warning(disable:4996)

using namespace std;

int arr[100001];
stack<pair<int, int>> st;

int main() {
	int n;
	long long ans = 0;

	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}

	for (int i = 0; i < n; i++) {
		int p = i;
		while (!st.empty() && st.top().first > arr[i]) {
				ans = max(ans, (long long)(st.top().first * (i - st.top().second)));
				p = st.top().second;
				st.pop();
		}
		st.push(make_pair(arr[i], p));
	}
	while (!st.empty()) {
		ans = max(ans, (long long)(st.top().first * (n - st.top().second)));
		st.pop();
	}

	printf("%lld\n", ans);
}