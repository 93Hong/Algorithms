#include <cstdio>
#include <algorithm>
#pragma warning(disable: 4996)

using namespace std;

int card[500001], match[500001], cur = 0, ans[500001];

typedef struct Card {
	int x;
	int y;
	int z;
} card2;

card2 c[500001];

bool cmp(int x, int y) {
	return x < y;
}

bool cmp2(card2 x, card2 y) {
	return x.x < y.x;
}

bool cmp3(card2 x, card2 y) {
	return x.y < y.y;
}

void binary(int left, int right, int m) {
	int mid = (left + right) / 2;
	if (left > right)
		return;
	if (c[mid].x == m)
		match[cur++] = m;
	else if (c[mid].x > m)
		binary(left, mid - 1, m);
	else
		binary(mid + 1, right, m);
}

int main() {
	int N, M;
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		scanf("%d", &card[i]);
	scanf("%d", &M);
	for (int i = 0; i < M; i++) {
		scanf("%d", &c[i].x);
		c[i].y = i;
	}

	sort(card, card + N, cmp);
	sort(c, c + M, cmp2);

	for (int i = 0; i < N; i++)
		binary(0, M, card[i]);

	cur = 0;
	for (int i = 0; i < M; i++) {
		if (c[i].x == match[cur]) {
			cur++;
			c[i].z = 1;
		}
		else
			c[i].z = 0;
	}

	sort(c, c + M, cmp3);

	for (int i = 0; i < M; i++)
		printf("%d ", c[i].z);
}