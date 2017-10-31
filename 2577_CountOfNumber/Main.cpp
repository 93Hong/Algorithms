#include <cstdio>
#pragma warning(disable:4996)

using namespace std;

int arr[10];

int main() {
	int A, B, C;
	scanf("%d %d %d", &A, &B, &C);

	int n = A * B * C;

	while (n > 0) {
		int a = n % 10;
		arr[a]++;
		n /= 10;
	}

	for (int i = 0; i < 10; i++)
		printf("%d\n", arr[i]);
}