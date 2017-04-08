#include <cstdio>
#pragma warning(disable: 4996)
using namespace std;

int main() {
	int M, N, tmp, min, sum = 0;
	scanf("%d", &M); scanf("%d", &N);

	for (int i = 1; i < 101; i++) {
		tmp = i*i;
		if (tmp >= M && tmp <= N) {
			if (sum == 0)
				min = tmp;
			sum += tmp;
		}
	}
	if (sum == 0)
		printf("-1\n");
	else {
		printf("%d\n", sum);
		printf("%d\n", min);
	}
}