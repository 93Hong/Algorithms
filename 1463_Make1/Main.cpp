#include <cstdio>
#pragma warning(disable: 4996)

using namespace std;
int d[1000001];

int mkOne(int n) {
	if (n == 1)
		return 0;
	if (d[n] != 0)
		return d[n];
	d[n] = mkOne(n - 1) + 1;
	if (n % 2 == 0) {
		int tmp = mkOne(n / 2) + 1;
		if (d[n] > tmp)
			d[n] = tmp;
	}
	if (n % 3 == 0) {
		int tmp = mkOne(n / 3) + 1;
		if (d[n] > tmp)
			d[n] = tmp;
	}
	return d[n];
}

int main() {
	int N;
	scanf("%d", &N);

	printf("%d\n", mkOne(N));
}