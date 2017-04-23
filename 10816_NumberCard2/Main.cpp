#include <cstdio>
#include <algorithm>
#pragma warning(disable: 4996)

using namespace std;

int	card[500005], card2[500005], re[500005];

bool cmp(int x, int y) {
	return x < y;
}

int binary(int left, int right, int ans) {
	int mid = (left + right) / 2;
	if (left > right)
		return 0;
	if (card[mid] == ans)
		return re[mid];
	else if (card[mid] > ans)
		binary(left, mid - 1, ans);
	else
		binary(mid + 1, right, ans);
}

int main() {
	int N, M;
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		scanf("%d", &card[i]);
	scanf("%d", &M);
	for (int i = 0; i < M; i++)
		scanf("%d", &card2[i]);

	sort(card, card + N, cmp);

	int index = -1, cnt = 1;
	for (int i = 0; i < N + 1; i++)
		if (card[i] == card[i + 1]) {
			if (index == -1)
				index = i;
			cnt++;
		}
		else if (index != -1) {
			for (int j = 0; j < cnt; j++)
				re[j + index] = cnt;
			index = -1;
			cnt = 1;
		}
		else
			re[i] = 1;

	for (int i = 0; i < M; i++)
		printf("%d ", binary(0, N - 1, card2[i]));
}