#include <cstdio>
#pragma warning(disable: 4996)

using namespace std;

int main() {
	int E, S, M, e = 1, s = 1, m = 1;
	scanf("%d", &E); scanf("%d", &S); scanf("%d", &M);

	int year = 1;

	while (1) {
		if (e == E && s == S && m == M) {
			printf("%d\n", year);
			break;
		}
		e++; s++; m++;
		if (e == 16)
			e = 1;
		if (s == 29)
			s = 1;
		if (m == 20)
			m = 1;
		year++;
	}
	return 0;
}