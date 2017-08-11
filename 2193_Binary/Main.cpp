#include <cstdio>

using namespace std;

long long int arr[91];

int main() {
	int n;
	scanf("%d", &n);

	arr[1] = 1;
	arr[2] = 1;

	for (int i = 3; i<n + 1; i++) {
		arr[i] = arr[i - 1] + arr[i - 2];
	}

	printf("%lld\n", arr[n]);
}