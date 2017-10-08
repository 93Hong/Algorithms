#include <cstdio>
#include <stack>
#pragma warning(disable:4996)

using namespace std;

int arr[500001];

int main() {
	int N;
	long long ans = 0;
	scanf("%d", &N);

	stack<pair<int, int>> st;
	for (int i = 0; i < N; i++)
		scanf("%d", &arr[i]);

	for (int i = 0; i < N; i++) {
		int cnt = 1;
		while (!st.empty()) {
			if (st.top().first <= arr[i]) {
				ans += (long long)st.top().second;
				if (st.top().first == arr[i])
					cnt += st.top().second;
				st.pop();
			}
			else
				break;
		}
		if (!st.empty())
			ans += 1LL;
		st.push(make_pair(arr[i], cnt));
	}

	printf("%lld\n", ans);
}