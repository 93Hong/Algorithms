#include <cstdio>
#include <vector>
#pragma warning(disable:4996)

using namespace std;

struct nation {
	int g, s, b;
	int rating;
	nation(int g, int s, int b, int rating) : g(g), s(s), b(b), rating(rating) {}

	bool operator < (const nation& other) {
		if (g < other.g) return true;
		if (g > other.g) return false;
		if (s < other.s) return true;
		if (s > other.s) return false;
		if (b < other.b) return true;
		return false;
	}

};

int main() {
	int N, K, target;
	scanf("%d %d", &N, &K);

	int n, g, s, b;
	vector<nation> v;
	
	for (int i = 0; i < N; i++) {
		scanf("%d %d %d %d", &n, &g, &s, &b);
		if (K == n)
			target = i;
		nation nat(g, s, b, n);
		v.push_back(nat);
	}
	int ans = 1;
	for (int i = 0; i < v.size(); i++) {
		if (i == target)
			continue;
		if (v[target] < v[i]) {
			ans++;
		}
	}

	printf("%d\n", ans);
}