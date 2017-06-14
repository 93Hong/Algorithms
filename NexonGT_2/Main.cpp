#include <cstdio>
#include <vector>
#pragma warning(disable :  4996)

using namespace std;


int up_dp[500][500];
int down_dp[500][500];
int n, m;

int up_go(vector<vector <int>> v, int row, int col) {
	if (row == -1)return 0;

	if (up_dp[row][col])return up_dp[row][col];

	int ans = -1;
	if (col - 1 >= 0) {
		if (ans < up_go(v, row - 1, col - 1))ans = up_go(v, row - 1, col - 1);
	}
	if (ans < up_go(v, row - 1, col))ans = up_go(v, row - 1, col);
	if (col + 1 < m) {
		if (ans < up_go(v, row - 1, col + 1))ans = up_go(v, row - 1, col + 1);
	}

	return up_dp[row][col] = ans + v[row][col];
}
int down_go(vector<vector <int>> v, int row, int col) {

	if (row == n) return 0;

	if (down_dp[row][col])return down_dp[row][col];

	int ans = -1;
	if (col - 1 >= 0) {
		if (ans < down_go(v, row + 1, col - 1))ans = down_go(v, row + 1, col - 1);
	}
	if (ans < down_go(v, row + 1, col))ans = down_go(v, row + 1, col);
	if (col + 1 < m) {
		if (ans < down_go(v, row + 1, col + 1))ans = down_go(v, row + 1, col + 1);
	}

	return down_dp[row][col] = ans + v[row][col];
}

int maxPathSum(vector<vector <int>> board, int p, int q) {
	if (down_go(board, 0, p) > up_go(board, n - 1, q)) {
		return down_go(board, 0, p);
	}
	else {
		return up_go(board, n - 1, q);
	}
}