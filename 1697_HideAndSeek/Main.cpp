#include <cstdio>
#include <queue>
#pragma warning(disable:4996)
using namespace std;

int arr[300000];

int main() {
	int N, K;
	scanf("%d", &N); scanf("%d", &K);
	
	queue<int> q;
	q.push(N);

	while (!q.empty()) {
		int x = q.front();
		q.pop();

		if (x == K)
			break;
		
		if (x < K) {
			if (arr[x + 1] == 0) {
				q.push(x + 1);
				arr[x + 1] = arr[x] + 1;
			}
			if (arr[x * 2] == 0) {
				q.push(x * 2);
				arr[x * 2] = arr[x] + 1;
			}
		}
		if (x - 1 >= 0) {
			if (arr[x - 1] == 0) {
				q.push(x - 1);
				arr[x - 1] = arr[x] + 1;
			}
		}
	}
	printf("%d\n", arr[K]);
}