#include <cstdio>
#include <cstring>
#pragma warning(disable: 4996)

using namespace std;

int main() {
	int N, num1, num2, num3, re = 0;

	bool arr[1000000] = { false };

	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%d", &num1); scanf("%d", &num2); scanf("%d", &num3);
		if (!arr[num1] && !arr[num2] && !arr[num3])
			re++;
		arr[num1] = true;
		arr[num2] = true;
		arr[num3] = true;
	}

	printf("%d\n", re);
}