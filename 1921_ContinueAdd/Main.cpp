#include <cstdio>
#pragma warning(disable: 4996)

using namespace std;

int num[100001];

int main() {
	int N;
	bool flag = false;
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%d", &num[i]);
		if (num[i] > 0)
			flag = true;
	}

	int max = -10000000;
	if (!flag) {
		for (int i = 0; i < N; i++) {
			if (max < num[i])
				max = num[i];
		}
	}
	else {
		int sum = 0;
		max = 0;
		for (int i = 0; i < N; i++) {
			sum += num[i];
			if (sum < 0) {
				sum = 0;
			}
			if (max < sum)
				max = sum;
		}
	}

	printf("%d\n", max);
}