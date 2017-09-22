#include <cstdio>
#pragma warning(disable:4996)

using namespace std;

int main() {
	int T, arr[16];
	scanf("%d", &T);

	while (T--) {
		for (int i = 0; i < 16; i++)
			scanf("%1d", &arr[i]);

		for (int i = 14; i >= 0; i -= 2) {
			arr[i] *= 2;
			if (arr[i] > 9) {
				int tmp = arr[i] % 10 + arr[i] / 10;
				arr[i] = tmp;
			}
		}

		int sum = 0;
		for (int i = 0; i < 16; i++)
			sum += arr[i];
		if (sum % 10)
			printf("F\n");
		else
			printf("T\n");
	}
}