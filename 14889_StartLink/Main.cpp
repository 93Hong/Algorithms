#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
#define INF 10000
#pragma warning(disable:4996)

using namespace std;

int arr[21][21], ans = INF;
vector<int> v;

void solve() {

}

int main() {
	int N;
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &arr[i][j]);
		}
	}

	for (int i = 0; i < N; i++)
		v.push_back(i);

	do {
		int a = 0, b = 0;

		for (int i = 0; i<)

	} while (next_permutation(v.begin(), v.end()));

	printf("%d\n", ans);
}