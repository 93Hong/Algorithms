#include <cstdio>
#include <vector>
#include <algorithm>
#pragma warning(disable: 4996)

using namespace std;

int main() {
	int N, fun;
	scanf("%d", &N);
	vector<pair<int, int>> vec;
	for (int i = 0; i < N; i++) {
		scanf("%d", &fun);
		vec.push_back({ fun, i });
	}
	sort(vec.begin(), vec.end(), [](pair<int, int>& first, pair<int, int>& second)->bool { return first.first < second.first; });

	for (int i = 0; i < N; i++) {
		printf("%d ", vec[i].first);
	}
	for (int i = 0; i < N; i++) {
		printf("%d ", vec[i].second);
	}
}