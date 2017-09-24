#include <cstdio>
#include <queue>
#include <vector>
#include <string>
#include <iostream>
#include <cstdio>
#include <sstream>
#include <algorithm>
#include <iterator>
#pragma warning(disable : 4996)

using namespace std;

int n, map[100][100];
vector<int> v;
queue<pair<int, int>> q;
int dir[4][4] = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };

int main() {
	
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int tmp;
			cin >> tmp;
			map[i][j] = tmp;
		}
	}

	int ans = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j] != 0) {
				int check = map[i][j];
				int tmp = 0;
				q.push({ i, j });
				map[i][j] = 0;

				while (!q.empty()) {
					int x = q.front().first;
					int y = q.front().second;
					tmp++;
					q.pop();

					for (int k = 0; k < 4; k++) {
						int dx = x + dir[k][0];
						int dy = y + dir[k][1];

						if (dx >= n || dx < 0 || dy >= n || dy < 0)
							continue;
						if (map[dx][dy] == check) {
							q.push({ dx, dy });
							map[dx][dy] = 0;
						}
					}
				}

				ans++;
				v.push_back(tmp);
			}
		}
	}

	if (ans == 0) {
		printf("0\n");
	}
	else {
		sort(v.begin(), v.end());
		printf("%d\n", ans);
		for (int i = 0; i < v.size(); i++) {
			if (i != v.size() - 1)
				printf("%d ", v[i]);
			else
				printf("%d", v[i]);
		}
		printf("\n");
	}
}