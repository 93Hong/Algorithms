#include <cstdio>
#pragma warning(disable: 4996)

using namespace std;

int graph[1001][1001] = { 0 };
int N, M, V;

int queue[1001];
bool check[1001];

void BFS() {

}

void DFS() {
	int index = 0, front = 0, end = 0, v = V;
	queue[index] = v;
	check[v] = true;

	while (front <= end) {
		for (int i = 0; i < N; i++) {
			if (graph[v][i] && !check[i]) {
				queue[end++] = v;
				check[i] = true;
			}
		}
		printf("%d ", queue[front++]);
		if (front == end)
			break;
		v = queue[front];
	}
	while (front < end) {
		printf("%d ", queue[front++]);
	}
}

int main() {
	scanf("%d", &N); scanf("%d", &M); scanf("%d", &V);

	while (M--) {
		int a, b;
		scanf("%d", &a); scanf("%d", &b);
		graph[a-1][b-1] = 1;
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			printf("%d", graph[i][j]);
		}
		printf("\n");
	}

	DFS();
	BFS();
}