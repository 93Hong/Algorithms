#include <cstdio>
#include <queue>
#pragma warning(disable: 4996)

using namespace std;
queue<int> q;

int main() {
	int M, N, cnt = 1;
	scanf("%d", &N); scanf("%d", &M);

	for (int i = 1; i < N + 1; i++)
		q.push(i);

	printf("<");
	while (q.size() != 1) {
		if (M == cnt) {
			printf("%d, ", q.front());
			q.pop();
			cnt = 1;
		}
		else {
			cnt++;
			q.push(q.front());
			q.pop();
		}
	}
	printf("%d", q.front());
	printf(">");
}