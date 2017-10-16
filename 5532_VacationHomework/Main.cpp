#include <cstdio>
#include <algorithm>
#pragma warning(disable:4996)

using namespace std;

int main() {
	int L, A, B, C, D, ans = 0;
	scanf("%d", &L);
	scanf("%d", &A);
	scanf("%d", &B);
	scanf("%d", &C);
	scanf("%d", &D);

	int n1, n2;
	n1 = A / C;
	n2 = B / D;
	if (A%C != 0)
		n1 = A / C + 1;
	if (B%D != 0)
		n2 = B / D + 1;

	printf("%d\n", L - max(n1, n2));
}