#include <cstdio>
#pragma warning(disable:4996)

using namespace std;

int main() {
	int N;
	scanf("%d", &N);

	int fcnt = 0, tcnt = 0;
	
	if (N % 5 == 0) {
		printf("%d\n", N / 5);
		return 0;
	}
	else {
		for (int i = N / 5; i >= 0; i--) {
			int div = N - 5 * i;

			if (div % 3 == 0) {
				fcnt = i;
				tcnt = div / 3;

				printf("%d\n", fcnt + tcnt);
				break;
			}
		}
	}

	if (fcnt == 0 && tcnt == 0) {
		if (N % 3 == 0)
			printf("%d\n", N / 3);
		else
			printf("-1\n");
	}
}