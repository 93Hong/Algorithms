#include <cstdio>
#include <string>
#include <queue>
#pragma warning(disable:4996)

using namespace std;
bool prime[10001], checked[10001];
int d[10001];

int change(int from, int i, int j) {
	if (i == 0 && j == 0)
		return -1;
	string s = to_string(from);
	s[i] = j + '0';
	return stoi(s);
}

int main() {
	int T;

	for (int i = 2; i <= 10000; i++) {
		if (prime[i] == false) {
			for (int j = i*i; j <= 10000; j += i)
				prime[j] = true;
		}
	}

	for (int i = 0; i <= 10000; i++)
		prime[i] = !prime[i];

	scanf("%d", &T);
	
	while (T--) {
		queue<int> q;
		int from, to;
		scanf("%d %d", &from, &to);

		for (int i = 0; i < 10000; i++) {
			checked[i] = false;
			d[i] = 0;
		}

		q.push(from);
		checked[from] = true;

		while (!q.empty()) {
			from = q.front();
			q.pop();

			for (int i = 0; i < 4; i++) {
				for (int j = 0; j <= 9; j++) {
					int now = change(from, i, j);
					if (now != -1) {
						if (prime[now] && checked[now] == false) {
							checked[now] = true;
							d[now] = d[from] + 1;
							q.push(now);
						}
					}
				}
			}
		}

		printf("%d\n", d[to]);
	}
}