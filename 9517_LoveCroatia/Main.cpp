#include<stdio.h>

int k, n, s;

int main() {
	for (scanf("%d%d", &k, &n); n--;) {
		int t; char c;
		scanf("%d %c", &t, &c);
		if (s + t > 210)break;
		if (c == 'T')k = k % 8 + 1;
		s += t;
	}
	printf("%d", k);
	return 0;
}