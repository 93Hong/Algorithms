#include <cstdio>
#include <algorithm>
#pragma warning(disable:4996)
#define INF 1100000000

using namespace std;

int arr[11], oper[4], N;
int maxv = -INF, minv = INF;

int cal(int a, int b, int o) {
	if (o == 0)
		return a + b;
	else if (o == 1)
		return a - b;
	else if (o == 2)
		return a * b;
	return a / b;
}

void solve(int index, int value) {
	if (index == N - 1) {
		if (value < minv)
			minv = value;
		if (value > maxv)
			maxv = value;
	}
	else {
		for (int i = 0; i < 4; i++) {
			if (oper[i] > 0) {
				int value2 = cal(value, arr[index + 1], i);
				oper[i]--;
				solve(index + 1, value2);
				oper[i]++;
			}
		}
	}
}

int main() {
	int tmp;
	scanf("%d", &N);

	for (int i = 0; i < N; i++)
		scanf("%d", &arr[i]);
	scanf("%d %d %d %d", &oper[0], &oper[1], &oper[2], &oper[3]);

	solve(0, arr[0]);

	printf("%d\n%d\n", maxv, minv);

	return 0;
}
