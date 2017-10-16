#include <cstdio>
#pragma warning(disable:4996)

using namespace std;

int arr[101];

int main() {
	int A, B, C, n = 3, ans = 0;
	scanf("%d %d %d", &A, &B, &C);

	int maxr = 0;
	while (n--) {
		int a, b;
		scanf("%d %d", &a, &b);
		if (maxr < b)
			maxr = b;
		for (int i = a; i < b; i++) {
			arr[i]++;
		}
	}

	for (int i = 0; i < maxr; i++) {
		if (arr[i] == 1)
			ans += A;
		else if (arr[i] == 2)
			ans += B * 2;
		else if (arr[i] == 3)
			ans += C * 3;
	}

	printf("%d\n", ans);
}