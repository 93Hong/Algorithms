#include<cstdio>
#pragma warning (disable:4996)

using namespace std;

int main() {
	int N, a, b, cnt = 1;
	scanf("%d", &N); scanf("%d", &a); scanf("%d", &b);

	if (a > b) {
		int tmp = b;
		b = a;
		a = tmp;
	}

	while (1) {
		if (a == 1 && b == 2)
			break;
		if (a % 2)
			a = a / 2 + 1;
		else
			a = a / 2;
		if (b % 2)
			b = b / 2 + 1;
		else
			b = b / 2;
		if (a == b)
			break;
		cnt++;
	}

	printf("%d\n", cnt);
}