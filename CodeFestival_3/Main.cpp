#include <cstdio>
#include <algorithm>
#pragma warning(disable:4996)

int main() {
	int i = 0, n = INT_MAX;

	while (n > 1) {
		n = n / 3;
		i++;
	}
	printf("%d\n", i);
}