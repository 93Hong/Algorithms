#include <cstdio>
#include <algorithm>
#pragma warning(disable: 4996);

using namespace std;

int main() {
	int M, N;
	scanf("%d", &N); scanf("%d", &M);

	if (N == 1) {
		printf("%d\n", 1);
	}
	else if (N == 2) {
		printf("%d\n", min(4, (M + 1) / 2));
	}
	else {
		if (M < 7)
			printf("%d\n", min(4, M));
		else
			printf("%d\n", M - 2);
	}
}