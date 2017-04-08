#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#pragma warning(disable: 4996)
using namespace std;

vector<pair<long int, long int>> v1, v2;

int main() {
	int N, cur, re = 0;
	long int max;
	scanf("%d", &N);
	long int a, b;
	for (int i = 0; i < N; i++) {
		scanf("%d", &cur);
		scanf("%ld", &a); scanf("%ld", &b);
		v1.push_back({ a, b });
		v2.push_back({ a, b });
	}
	sort(v1.begin(), v1.end(), [](pair<long int, long int>& first, pair<long int, long int>& second)->bool { return first.first < second.first; });
	sort(v2.begin(), v2.end(), [](pair<long int, long int>& first, pair<long int, long int>& second)->bool { return first.second < second.second; });

	cur = 0;
	for (int i = 0; i < N; i++) {
		if (v2[cur].second <= v1[i].first) {
			re++;
			cur++;
		}
	}

	printf("%d\n", N - re);
}