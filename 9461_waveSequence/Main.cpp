#include <cstdio>
#pragma warning(disable:4996)

using namespace std;

long long int arr[101];

int main() {
	int N;
	scanf("%d", &N);
	arr[1] = 1;
	arr[2] = 1;
	arr[3] = 1;
	arr[4] = 2;
	arr[5] = 2;

	for (int i = 6; i <= 100; i++) {
		arr[i] = arr[i-1] + arr[i-5];
	}
	while (N--) {
		int n;
		scanf("%d", &n);
		printf("%lld\n", arr[n]);
	}
}