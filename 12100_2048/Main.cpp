#include <cstdio>
#include <stdlib.h>
#include <memory.h>
#pragma warning(disable: 4996)

using namespace std;

int arr[21][21];
int N;
int x[4] = { 0, 1, 0, -1 }, y[4] = {1, 0, -1, 0};

void solve(int cnt, int pre, int ar[21][21]) {
	if (cnt == 5)
		return;

	int** ary = new int*[N];
	for (int i = 0; i < N; ++i)
		ary[i] = new int[N];

	for (int i = 0; i < 4; i++) {
		if (pre == i)
			continue;
		solve(cnt + 1, i);
	}
}

int main() {
	scanf("%d", &N);

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			scanf("%d", &arr[i][j]);

	solve(0, -1, arr);
}