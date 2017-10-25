#include <cstdio>
#include <functional>
#include <vector>
#include <algorithm>
#pragma warning(disable:4996)

using namespace std;

int arr[51], arr2[51];

int main() {
	int n;
	scanf("%d", &n);

	for (int i = 0; i<n; i++)
		scanf("%d", &arr[i]);

	for (int i = 0; i<n; i++)
		scanf("%d", &arr2[i]);

	sort(arr, arr + n);
	sort(arr2, arr2 + n, greater<int>());

	int sum = 0;

	for (int i = 0; i<n; i++) {
		sum += arr[i] * arr2[i];
	}

	printf("%d\n", sum);
}
