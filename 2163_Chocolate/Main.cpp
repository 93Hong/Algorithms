#include <cstdio>
#pragma warning(disable:4996)

using namespace std;

int main() {
	int N, M;
	scanf("%d", &N); scanf("%d", &M);
	int ans = 0;
	if (N > M) {
		ans = (M - 1) + (M * (N - 1));
	}
	else {
		ans = (N - 1) + (N * (M - 1));
	}
	printf("%d\n", ans);
}