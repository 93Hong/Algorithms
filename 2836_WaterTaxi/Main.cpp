#include <cstdio>
#include <algorithm>
#include <vector>
#pragma warning(disable:4996)

#define INF 1001000000

using namespace std;

vector<pair<long long, long long>> v;

int main() {
	long long N, M;
	scanf("%lld %lld", &N, &M);

	while (N--) {
		long long a, b;
		scanf("%lld %lld", &a, &b);
		if (a > b)
			v.push_back(make_pair(b, a));
	}

	sort(v.begin(), v.end());

	long long result = M, r = -INF, l = -INF;
	for (int i = 0; i < v.size(); i++) {
		if (r < v[i].first) {
			result += (r - l)*2;
			r = v[i].second;
			l = v[i].first;
		}
		else {
			r = max(r, v[i].second);
		}
	}
	result += 2 * (r - l);

	printf("%lld\n", result);
}