#include <cstdio>
#include <algorithm>
#pragma warning(disable:4996)

using namespace std;

int main() {
	long N;
	scanf("%ld", &N);
	int ans = 0;

	for (long i = 2, a = 1; i < 2000000 && a < N; i++, a = (i*i - i) / 2) if ((N - a) % i == 0) ans++;

	printf("%d\n", ans);
}