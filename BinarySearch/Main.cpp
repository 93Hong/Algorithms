#include <cstdio>
#pragma warning(disable: 4996)

using namespace std;

int arr[1000], ans;

int binary(int left, int right) {
	int mid = (left + right) / 2;
	if (left > right) // there is not ans in arr
		return 0;
	if (arr[mid] == ans) // there is ans in arr
		return 1;
	else if (arr[mid] > ans)
		binary(left, mid - 1);
	else
		binary(mid + 1, right);
}

int main() {
	int N;
	scanf("%d", &N); scanf("%d", &ans);
	for (int i = 0; i < N; i++)
		scanf("%d", &arr[i]);

	printf("%d\n", binary(0, N - 1));
}