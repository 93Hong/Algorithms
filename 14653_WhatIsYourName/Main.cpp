#include <cstdio>
#include <algorithm>
#include <vector>
#pragma warning(disable:4996)

using namespace std;

bool ans[26] = { false };

int main() {
	int N, K, Q;
	vector<pair<int, char>> data;
	int n, index = 0;
	char c;

	scanf("%d", &N); scanf("%d", &K); scanf("%d", &Q);
	for (int i = 0; i < K; i++) {
		scanf("%d", &n);
		getchar();
		c = getchar();
		data.push_back(make_pair(n, c));
	}
	index = data[Q-1].first;

	bool flag = false;

	for (int i = 0; i < K; i++) {
		if (data[i].first == index) {
			flag = true;
		}
		if (flag) {
			ans[data[i].second - 65] = true;
		}
	}
	ans[0] = true;
	if (index == 0)
		printf("-1");
	else {
		for (int i = 0; i < N; i++) {
			if (ans[i] != 1)
				printf("%c ", (i + 65));
		}
	}
}