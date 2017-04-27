#include <cstdio>
#pragma warning(disable: 4996)

using namespace std;

int main() {
	int A, B, C;
	scanf("%d", &A); scanf("%d", &B); scanf("%d", &C);

	int n = C - A - 1;

	if (n == 1)
		printf("0\n");
	else if (n % 2 == 1)
		printf("%d\n", (n + 1) / 2);
	else
		printf("%d\n", n / 2);
}