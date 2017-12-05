#include <cstdio>
#include <unordered_map>
#pragma warning (disable:4996)

using namespace std;
#define scan(a) scanf("%d",&a)

int t, w, n, ans;
int weights[256];
int numbers[256];
//dfs
int temp[256];
unordered_map<int, int> m;
pair<unordered_map<int, int>::iterator, bool> iter;

void dfs(int *arr, int idx, int weight, int number) {
	if (weight == w) {
		if (ans == 0) {
			ans = number;
			for (int i = 0; i < n; i++) {
				temp[i] = arr[i];
			}
		}
		else if (ans > number) {
			ans = number;
			for (int i = 0; i < n; i++) {
				temp[i] = arr[i];
			}
		}
		return;
	}

	for (int i = idx; i < n; i++) {
		int t = 0;
		for (int j = 1; j <= numbers[i]; j++) {
			t += weights[i];
			++arr[i];

			iter = m.insert(make_pair(t + weight, number + j));
			if (iter.second) {
				dfs(arr, i + 1, weight + t, number + j);
			}
			else {
				if (m[t + weight] > number + j) {
					m[t + weight] = number + j;
					dfs(arr, i + 1, weight + t, number + j);
				}
			}

			iter = m.insert(make_pair(t - weight, number + j));
			if (iter.second) {
				dfs(arr, i + 1, weight - t, number + j);
			}
			else {
				if (m[t - weight] > number + j) {
					m[t - weight] = number + j;
					dfs(arr, i + 1, weight - t, number + j);
				}
			}
		}
		arr[i] = 0;
	}
}


void sol(int tc) {
	int *arr = new int[n];
	dfs(arr, 0, 0, 0);

	printf("#%d\n", tc);
	if (ans == 0)
		printf("FAIL\n");
	else {
		for (int i = 0; i < n; i++) {
			printf("%d %d\n", weights[i], temp[i]);
		}
	}
	m.clear();
	delete[] arr;
}

int main() {
	scan(t);

	for (int tc = 1; tc <= t; tc++) {
		scan(w);
		scan(n);
		ans = 0;
		for (int i = 0; i < n; i++) {
			scanf("%d%d", weights + i, numbers + i);
		}
		sol(tc);
	}

	return 0;
}