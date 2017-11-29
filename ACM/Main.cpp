#include <cstdio>
#include <vector>
#include <memory.h>
#pragma warning (disable:4996)

using namespace std;

int t, n, k, x, y, w;
int time[1001];
int total[1001];
vector<int> v[1001];

void Reset();
void InputValue();
int DFS(int);
void Answer();

void Reset() {
	memset(time, 0, sizeof(time));
	memset(total, 0, sizeof(time));

	for (int i = 1; i <= 1000; i++)
		v[i].clear();
}

void InputValue() {
	scanf("%d %d", &n, &k);

	for (int i = 1; i <= n; i++) {
		scanf("%d", &time[i]);
	}

	for (int i = 0; i < k; i++) {
		scanf("%d %d", &x, &y);
		v[y].push_back(x);
	}

	scanf("%d", &w);
}

int DFS(int idx) {
	int cost = 0;

	if (v[idx].empty()) {
		return total[idx] = time[idx];
	}

	for (int i = 0; i < v[idx].size(); i++) {
		int temp;

		if (total[v[idx][i]] != 0) temp = total[v[idx][i]];

		else  temp = DFS(v[idx][i]);

		if (cost < temp) cost = temp;
	}

	return total[idx] = time[idx] + cost;
}

void Answer() {
	printf("%d\n", total[w]);
}

int main() {
	scanf("%d", &t);

	while (t--) {
		Reset();
		InputValue();
		DFS(w);
		Answer();
	}
}
