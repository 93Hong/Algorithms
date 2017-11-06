#include <cstdio>
#pragma warning(disable:4996)

using namespace std;

int main() {
	int yut;
	for (int i = 0; i < 3; i++) {
		int n = 0;
		for (int j = 0; j < 4; j++) {
			scanf("%d", &yut);
			n += yut;
		}
		if (n == 0)
			printf("D\n");
		else if (n == 1)
			printf("C\n");
		else if (n == 2)
			printf("B\n");
		else if (n == 3)
			printf("A\n");
		else
			printf("E\n");
	}
}
