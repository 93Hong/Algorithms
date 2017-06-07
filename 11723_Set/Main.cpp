#include <cstdio>
#include <cstring>
#pragma warning (disable : 4996)

using namespace std;

int S = 0;
char s[8];

void add(int x) {
	if (!(S & (1 << x)))
		S = S | (1 << x);
}

void remove(int x) {
	if (S & (1 << x))
		S = S & ~(1 << x);
}

void check(int x) {
	if (S & (1 << x))
		printf("1\n");
	else
		printf("0\n");
}

void toggle(int x) {
	if (S & (1 << x))
		remove(x);
	else
		add(x);
}

void all() {
	for (int i = 1; i < 21; i++) {
		S = S | (1 << i);
	}
}

void empty() {
	S = 0;
}

int main() {
	int M, n;



	scanf("%d", &M);

	while (M--) {
		scanf("%s", s);

		if (s[0] == 'a')
			if (s[1] == 'l')
				all();
			else {
				scanf("%d", &n);
				add(n);
			}
		else if (s[0] == 'r') {
			scanf("%d", &n);
			remove(n);
		}
		else if (s[0] == 'c') {
			scanf("%d", &n);
			check(n);
		}
		else if (s[0] == 't') {
			scanf("%d", &n);
			toggle(n);
		}
		else
			empty();
	}
}