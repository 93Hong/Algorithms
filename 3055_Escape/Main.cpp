#include <cstdio>
#include <queue>
#pragma warning(disable:4996)

using namespace std;

char map[51][51];
int R, C;

bool isInRange(int i, int j) {
	return (i >= R || i < 0 || j >= C || j < 0);
}

int main() {
	scanf("%d", &R); scanf("%d", &C);
	
	for (int i = 0; i < R; i++)
		for (int j = 0; j < C; j++)
			scanf("%c", &map[i][j]);

	queue<pair<int, int>> 
}