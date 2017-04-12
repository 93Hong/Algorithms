#include <cstdio>
#include <vector>
#include <algorithm>
#pragma warning(disable: 4996)

using namespace std;

int main() {
	int n, first, second;
	scanf("%d", &n);
	vector<pair<int, int>> vec;

	for (int i = 0; i < n; i++) {
		scanf("%d", &first); scanf("%d", &second);
		vec.push_back({ second, first });
	}
	sort(vec.begin(), vec.end());

	int re = 1, cur = 0;

	for (int i = 1; i < n; i++) {
		if (vec[cur].first <= vec[i].second) {
			re++;
			cur = i;
		}
		//printf("%d\n", vec[i].first);
	}
	printf("%d\n", re);
}