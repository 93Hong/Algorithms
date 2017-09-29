#include <vector>
#include <cstdio>
#include <queue>

using namespace std;
int dp[51][51], check[51][51];
int dirx[4] = { 0, 0, 1, -1 };
int diry[4] = { 1, -1, 0, 0 };
int M, N;

queue<pair<int, int>> q;

int solve(int x, int y) {
	if (x < 0 || x >= N || y < 0 || y >= M)
		return 0;
	if (dp[x][y])
		return dp[x][y];

	for (int i = 0; i < 4; i++) {
		
	}
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, int s, vector<vector<int>> time_map) {
	int move_distance = 0;
	int sum_of_talk_time = 0;



	q.push({ 0, 0 });
	
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int dx = x + dirx[i];
			int dy = y + diry[i];

			if (dx >= n || dx < 0 || dy >= m || dy < 0)
				continue;

			
		}
	}

	vector<int> answer(2);
	answer[0] = move_distance;
	answer[1] = sum_of_talk_time;

	return answer;
}

int main() {
	vector<vector<int>> time_map;
	time_map.push_back({ 0, 1, 1, -1, 2, 4 });
	time_map.push_back({ -1, 7, 2, 1, 5, 7 });
	time_map.push_back({ -1, 1, -1, 1, 6, 3 });
	time_map.push_back({ -1, 1, -1, -1, 7, 0 });

	solution(4, 6, 25, time_map);
}