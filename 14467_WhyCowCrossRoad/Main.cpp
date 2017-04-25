#include <cstdio>
#include <cstring>
#pragma warning(disable: 4996)

using namespace std;

int arr[11];

int main() {
	int N;
	scanf("%d", &N);

	memset(arr, -1, sizeof(arr));
	
	int a, b, cnt = 0;
	while (N--) {
		scanf("%d", &a); scanf("%d", &b);
		if (arr[a] == -1) {
			arr[a] = b;
		}
		else if (arr[a] != b) {
			arr[a] = b;
			cnt++;
		}
	}

	printf("%d\n", cnt);
}