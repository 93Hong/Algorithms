#include <cstdio>
#pragma warning(disable: 4996)

using namespace std;

int graph[1002][1002];
int N, M, V;

int queue[1002];
bool check[1002];

bool check2[1002];

void BFS() {
	int index = 0, front = 0, end = 0, v = V;
	queue[front] = v;
	check[v] = true;

	while (front <= end) {
		printf("%d ", queue[front]);
		front++;
		for (int i = 1; i < N + 1; i++) {
			if (graph[v][i] && !check[i]) {
				queue[++end] = i;
				check[i] = true;
			}
		}
		v = queue[front];
	}
}

void DFS(int v) {
	check2[v] = true;
	printf("%d ", v);
	for (int i = 1; i < N + 1; i++) {
		if (graph[v][i] && !check2[i]) {
			DFS(i);
		}
	}
}

int main() {

	scanf("%d", &N); scanf("%d", &M); scanf("%d", &V);

	while (M--) {
		int a, b;
		scanf("%d", &a); scanf("%d", &b);
		graph[a][b] = 1;
		graph[b][a] = 1;
	}

	DFS(V);
	printf("\n");
	BFS();
}