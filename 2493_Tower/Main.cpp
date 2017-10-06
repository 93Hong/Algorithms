#include <cstdio>
#include <stack>
#pragma warning(disable:4996)

using namespace std;

stack<pair<int, int>> st;
int ans[500001], list[500001];

int main() {
	int N;
	scanf("%d", &N);

	for (int i = 0; i < N; i++)
		scanf("%d", &list[i]);

	for (int i = N - 1; i >= 0; i--) {
		while (!st.empty() && st.top().first < list[i]) {
			ans[st.top().second] = i + 1;
			st.pop();
		}
		st.push(make_pair(list[i], N - i - 1));
	}

	for (int i = N - 1; i >= 0; i--)
		printf("%d ", ans[i]);
}