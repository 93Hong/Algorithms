#include <cstdio>
#include <stack>
#include <algorithm>
#pragma warning(disable:4996)

using namespace std;

int arr[100001];
stack<pair<int, int>> st;

int main() {
	int N;
	scanf("%d", &N);
	long long ans = 0;

	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
	}

	for (int i = 0; i < N; i++) {
		int tmp = i;
		while (!st.empty() && st.top().first > arr[i]) {
			ans = max(ans, (long long)(st.top().first * (i - st.top().second)));
			tmp = st.top().second;
			st.pop();
		}
		st.push(make_pair(arr[i], tmp));
	}

	while (!st.empty()) {
		ans = max(ans, (long long)(st.top().first * (N - st.top().second)));
		st.pop();
	}

	printf("%lld\n", ans);
}