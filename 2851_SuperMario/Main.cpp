#include <cstdio>
#pragma warning(disable:4996)

using namespace std;

int main() {
	int n = 10, sum = 0, prev, num;
	bool flag = false;

	while (n--) {
		scanf("%d", &num);
		sum += num;
		if (sum == 100) {
			printf("100\n");
			return 0;
		}
		if (sum > 100) {
			flag = true;
			break;
		}
	}

	if (flag) {
		if (sum - 100 <= 100 - (sum - num)) {
			printf("%d\n", sum);
		}
		else {
			printf("%d\n", sum - num);
		}
	}
	else {
		printf("%d\n", sum);
	}
}