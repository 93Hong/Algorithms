#include <cstdio>
#include <queue>
#pragma warning(disable:4996)

using namespace std;

int main() {
	int N;
	scanf("%d", &N);

	queue<int> q;

	for (int i = 1; i <= N; i++)
		q.push(i);

	while (q.size() > 1) {
		q.pop();
		int n = q.front();
		q.pop();
		q.push(n);
	}

	printf("%d\n", q.front());
}