#include <cstdio>
#include <cmath>
#pragma warning(disable: 4996)

using namespace std;

int main() {
	long long int A, B, tmp;
	scanf("%lld", &A); scanf("%lld", &B);

	if (A < B) {
		tmp = A;
		A = B;
		B = tmp;
	}
	else if (A == B) {
		for (int i = 0; i < A; i++)
			printf("1");
		printf("\n");
		return 0;
	}

	if (A%B == 0) {
		for (int i = 0; i < B; i++)
			printf("1");
		printf("\n");
		return 0;
	}
	else
		printf("1\n");
}