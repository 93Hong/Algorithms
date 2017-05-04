#include <cstdio>
#pragma warning(disable: 4996)

using namespace std;

int GCD(int a, int b) {
	while (b != 0) {
		int r = a%b;
		a = b;
		b = r;
	}
	return a;
}

int LCM(int a, int b, int g) {
	return g*(a / g)*(b / g);
}

int main() {
	int T;
	scanf("%d", &T);

	while (T--) {
		int a, b;
		scanf("%d", &a); scanf("%d", &b);

		printf("%d\n", LCM(a, b, GCD(a, b)));
	}
}