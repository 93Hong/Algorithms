#include <cstdio>
#pragma warning(disable:4996)

using namespace std;

int board[1002];

int main() {
	int N, M;
	scanf("%d %d", &N, &M);

	for (int i = 1; i <= N; i++) {
		scanf("%d", &board[i]);
	}

	int cur = 1, cnt = 0;;
	while (M--) {
		cnt++;
		int num;
		scanf("%d", &num);

		cur += num;
		if (cur >= N) {
			break;
		}

		cur += board[cur];
		if (cur < 0)
			cur = 0;
		if (cur >= N)
			break;
	}

	printf("%d\n", cnt);
}