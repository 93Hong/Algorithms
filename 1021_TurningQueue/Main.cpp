#include <cstdio>
#include <algorithm>
#pragma warning(disable:4996)

using namespace std;
int arr[51];

int main() {
	int N, M;
	scanf("%d %d", &N, &M);

	for (int i = 0; i < M; i++) {
		int num;
		scanf("%d", &num);
		arr[i] = num;
	}
	printf("\nasn\n");

	int cur = 0;
	int l = 0, r = 0;
	for (int i = 0; i < M; i++) {
		int tmp = arr[i] + cur;
		while (tmp != 1) {
			if (tmp > N / 2) {
				cur++;
				r++;
				tmp++;
				if (tmp > M)
					tmp = 1;
			}
			else {
				cur--;
				l++;
				tmp--;
				if (tmp == 0)
					tmp = M;
			}
		}
		cur--;
		N--;
	}

	printf("%d\n", l+r);
}