#include <cstdio>
#include <vector>
#include <queue>
#pragma warning(disable: 4996)

using namespace std;

int map[9][9], d[9][9], cnt;
int M, N, dx[4] = { -1, 0, 0, 1 }, dy[4] = { 0, -1, 1, 0 };
vector<pair<int, int>> v;

void BFS(int x, int y) {
	queue<pair<int, int>> q; q.push({ x, y }); d[x][y] = 1;

	while (!q.empty()) {
		x = q.front().first; y = q.front().second; q.pop();
		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k], ny = y + dy[k];
			if (0 <= nx && nx < N && 0 <= ny && ny < M) {
				if (map[nx][ny] == 0 && d[nx][ny] == 0) {
					cnt++;
					q.push({ nx, ny }); d[nx][ny] = 1;
				}
			}
		}
	}
}

void count() {
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			d[i][j] = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] == 2) {
				BFS(i, j);
			}
		}
	}
}

int main() {
	scanf("%d", &N); scanf("%d", &M);
	int max = 1000, re = 0;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++) {
			scanf("%d", &map[i][j]);
			if (map[i][j] == 0) {
				v.push_back({ i, j });
				re++;
			}
		}

	for (int i = 0; i < v.size() - 2; i++) {
		map[v.at(i).first][v.at(i).second] = 1;
		for (int j = i + 1; j < v.size() - 1; j++) {
			map[v.at(j).first][v.at(j).second] = 1;
			for (int k = j + 1; k < v.size(); k++) {
				cnt = 0;
				map[v.at(k).first][v.at(k).second] = 1;
				count();
				if (max > cnt)
					max = cnt;
				map[v.at(k).first][v.at(k).second] = 0;
			}
			map[v.at(j).first][v.at(j).second] = 0;
		}
		map[v.at(i).first][v.at(i).second] = 0;
	}

	printf("%d\n", re - max - 3);
}