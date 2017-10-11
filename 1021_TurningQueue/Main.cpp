#include <cstdio>
#include <algorithm>
#include <deque>
#pragma warning(disable:4996)

using namespace std;

int main() {
	int N = 10, M, ans = 0, cur = 0, size;
	//scanf("%d %d", &N, &M);
	//size = M;

	deque<int> v;

	for (int i = 1; i <= N; i++)
		v.push_back(i);

	for (int i = 0; i < N; i++)
		printf("%d ", v[i]);
	printf("\n");
	int cnt = 0;
	for (int i = 0; cnt < N; i--) {
		printf("%d ", v[i]);
		if (i == 0)
			i = N;
		cnt++;
	}

	while (M--) {
		int tmp;
		scanf("%d", &tmp);

		if (v[cur] == tmp) {
			v[cur] = 0;
			cur++;
			continue;
		}

		int right = 0, left = 0;
		for (int i = cur; right < size; i = (i + 1) % size) {
			if (v[i] == 0) {
				continue;
			}
			if (v[i] == tmp)
				break;
			right++;
		}
		for (int i = cur; left < size; i = (i - 1) % size) {
			if (v[i] == 0) {
				continue;
			}
			if (v[i] == tmp) {
				v[i] = 0;
				cur = (i + 1) % size;
				break;
			}
			left++;
		}

		ans += min(left, right);
		size--;
	}

	printf("%d\n", ans);
}