#include <cstdio>
#include <algorithm>
#include <queue>
#pragma warning(disable: 4996)

using namespace std;
int sorting[101];
int N, M, V;


bool cmp(int a, int b) { //내림차순 정렬에 사용
	return a > b;
}

int main() {
	scanf("%d", &N);

	int num, index;

	while (N--) {
		int cnt = 1;
		scanf("%d", &M); scanf("%d", &V);
		queue<pair<int, int>> q;
		for (int i = 0; i < M; i++) {
			scanf("%d", &num);
			q.push({ num, i });
			sorting[i] = num;
		}
		sort(sorting, sorting + M, cmp);
		int j = 0;
		for (;;) {
			if (q.front().first == sorting[j] && q.front().second == V) {
				printf("%d\n", cnt);
				break;
			}
			else if (q.front().first == sorting[j]) {
				q.pop();
				cnt++;
				j++;
			}
			else {
				q.push(q.front());
				q.pop();
			}
		}
		//while (!q.empty()) q.pop();
	}
}