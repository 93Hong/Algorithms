#include <cstdio>
#include <queue>
#pragma warning(disable:4996)

using namespace std;

int check[10001], d[10001], w[10001];
char how[10001];

int D(int from) {
	return (2 * from) % 10000;
}

int S(int from) {
	if (from - 1 == -1)
		return 9999;
	return from - 1;
}

int L(int from) {
	return (from % 1000) * 10 + from / 1000;
}

int R(int from) {
	return from / 10 + (from % 10) * 1000;
}

queue<int> solve(int from, int now, char pre, queue<int> q) {
	if (!check[now]) {
		check[now] = true;
		q.push(now);
		d[now] = d[from] + 1;
		w[now] = from;
		how[now] = pre;
	}
	return q;
}

int main() {
	int T;
	
	scanf("%d", &T);

	while (T--) {
		for (int i = 0; i < 10001; i++) {
			check[i] = 0;
			d[i] = 0;
			w[i] = 0;
			how[i] = 0;
		}

		queue<int> q;
		int from, to;
		scanf("%d %d", &from, &to);

		q.push(from);

		while(!q.empty()) {
			from = q.front();
			q.pop();
			check[from] = true;

			if (from == to)
				break;

			q = solve(from, D(from), 'D', q);
			q = solve(from, S(from), 'S', q);
			q = solve(from, L(from), 'L', q);
			q = solve(from, R(from), 'R', q);
		}

		int tmp = to;
		for (int i = 0; i < d[to]; i++) {
			printf("%c", how[tmp]);
			tmp = w[tmp];
		}
		printf("\n");
	}
}