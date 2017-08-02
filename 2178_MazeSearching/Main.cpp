#include <cstdio>
#include <queue>
#pragma warning(disable:4996)

using namespace std;

int maze[101][101], check[101][101];
int d[4][2] = { {0, 1}, {-1, 0}, {0, -1}, {1, 0} };
queue<pair<int, int>> q;
int ans = 20000;

int main() {
	int N, M;
	scanf("%d", &N); scanf("%d", &M);
	q.push({0, 0});
	check[0][0] = 1;
	
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			scanf("%1d", &maze[i][j]);

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		
		if (x == M - 1 && y == N - 1) {
			break;
		}

		for (int i = 0; i < 4; i++) {
			int dx = x + d[i][1], dy = y + d[i][0];
			if (dx > N - 1 || dx < 0 || dy > M - 1 || dy < 0)
				continue;
			if (maze[dx][dy] == 0 || check[dx][dy] != 0)
				continue;
			
			q.push({dx, dy});
			check[dx][dy] = check[x][y] + 1;
		}
	}

	printf("%d\n", check[N-1][M-1]);
}