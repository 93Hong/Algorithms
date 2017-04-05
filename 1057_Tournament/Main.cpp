#include <cstdio>
#pragma warning(disable: 4996)

using namespace std;

int main() {
	int N, a, b, cnt = 1;
	scanf("%d", &N); scanf("%d", &a); scanf("%d", &b);

	while (!(a == 1 && b == 2) && !(a == 2 && b == 1)) {
		if (a % 2)
			a = a / 2 + 1;
		else
			a /= 2;
		if (b % 2)
			b = b / 2 + 1;
		else
			b /= 2;
		cnt++;
	}

	printf("%d\n", cnt);
}