#include <cstdio>
#pragma warning(disable:4996)
using namespace std;

int main() {
	int M; scanf("%d", &M);
	int arr[4] = {0, 1, 0, 0 };
	while (M--) {
		int a, b;
		scanf("%d %d", &a, &b);

		int tmp = arr[a];
		arr[a] = arr[b];
		arr[b] = tmp;
	}

	for (int i = 1; i < 4; i++)
		if (arr[i] == 1)
			printf("%d\n", i);
}