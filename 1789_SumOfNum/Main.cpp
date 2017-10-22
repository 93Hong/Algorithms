#include <cstdio>
#pragma warning(disable:4996)

using namespace std;

int main() {
	long S;
	scanf("%lld", &S);

	long i;

	for (i = 1; i < S; i++) {
		if (i * (i + 1) / 2 > S)
			break;
	}
	printf("%lld\n", i - 1);
}