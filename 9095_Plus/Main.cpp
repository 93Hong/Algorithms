#include <cstdio>
#include <algorithm>
#pragma warning(disable: 4996)

using namespace std;

int d[1002], b[1002];
int N, re = 0;

int main() {
	float num;
	scanf("%d", &N);

	for (int i = 1; i < N + 1; i++) {
		scanf("%d", &b[i]);
	}

	for (int i = 1; i < N + 1; i++) {
		for (int j = 1; j <= i; j++) {
			d[i] = max(d[i], d[i - j] + b[j]);
		}
	}

	printf("%d\n", d[N]);
}