#include <cstdio>
#pragma warning(disable: 4996)

using namespace std;
long int d[1002];

int main() {
	int n;
	scanf("%d", &n);

	d[1] = 1;
	d[2] = 2;
	for (int i = 3; i < n + 1; i++) {
		d[i] = d[i - 1] + d[i - 2];
		d[i] = d[i] % 10007;
	}

	printf("%ld\n", d[n]);
}