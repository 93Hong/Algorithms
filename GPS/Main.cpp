#include <vector>
#include <queue>

using namespace std;
int dp[201][201];

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int n, int m, vector<vector<int>> edge_list, int k, vector<int> gps_log) {
	int answer = 0; queue<int> q;

	int start = gps_log[0], end = gps_log[k - 1];

	q.push(start);
	
	while (!q.empty()) {
		int v = q.front();
		q.pop();

		for (int i = 0; i < edge_list[v].size(); i++) {
			q.push();
		}
	}

	return answer;
}

int main() {

	vector<vector<int>> edge_list;
	edge_list.push_back({ 1, 2 });
	edge_list.push_back({ 1, 3 });
	edge_list.push_back({ 2, 3 });
	edge_list.push_back({ 2, 4 });
	edge_list.push_back({ 3, 4 });
	edge_list.push_back({ 3, 5 });
	edge_list.push_back({ 4, 6 });
	edge_list.push_back({ 5, 6 });
	edge_list.push_back({ 5, 7 });
	edge_list.push_back({ 6, 7 });

	vector<int> gps_log;
	gps_log.push_back(1);
	gps_log.push_back(2);
	gps_log.push_back(3);
	gps_log.push_back(3);
	gps_log.push_back(6);
	gps_log.push_back(7);

	solution(7, 10, edge_list, 6, gps_log);
}