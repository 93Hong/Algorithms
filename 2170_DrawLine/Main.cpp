#include <cstdio>
#include <algorithm>
#include <vector>
#pragma warning(disable:4996)

#define INF 1010000000

using namespace std;

vector<pair<int, int>> v;

int main() {
	int N;
	scanf("%d", &N);

	while (N--) {
		int x, y;
		scanf("%d %d", &x, &y);
		v.push_back(make_pair(x, y));
	}

	sort(v.begin(), v.end());

	int result = 0, r = -INF, l = -INF;
	for (int i = 0; i < v.size(); i++) {
		if (r < v[i].first) {
			result += r - l;
			r = v[i].second;
			l = v[i].first;
		}
		else {
			r = max(r, v[i].second);
		}
	}
	result += r - l;

	printf("%d\n", result);
}