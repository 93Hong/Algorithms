#include <cstdio>
#include <stack>
#include <algorithm>
#pragma warning(disable:4996)

using namespace std;

int arr[1001];
stack<int> st;

int main() {
	int N, ans = 0;
	scanf("%d", &N);

	for (int i = 0; i < N; i++)
		scanf("%d", &arr[i]);
	for (int i = 0; i < N; i++) {
		int tmp;
		scanf("%d", &tmp);
		arr[i] -= tmp;
	}

	for (int i = 0; i < N; i++) {
		if (!st.empty())
			if ((st.top() < 0) == (arr[i] < 0))
				if (abs(st.top()) < abs(arr[i])) {
					st.pop();
					st.push(arr[i]);
				}
			else
				st.push(arr[i]);
		else
			st.push(arr[i]);
	}

	while (!st.empty()) {
		ans += abs(st.top());
		st.pop();
	}

	printf("%d\n", ans);
}