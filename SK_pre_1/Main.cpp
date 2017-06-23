#include <cstdio>
#pragma warning(disable: 4996)

using namespace std;

int table[100] = { 0 };

int main() {
	int board[5][5] = { {6, 15, 17, 14, 23}, {5, 12, 16, 13, 25}, {21, 4, 2, 1, 22}, {10, 20, 3, 18, 8}, {11, 9, 19, 24, 7} };
	int nums[] = {15, 7, 2, 25, 9, 16, 12, 18, 5, 4, 10, 13, 20};

	//int board[4][4] = { { 11, 13, 15, 16 },{ 12, 1, 4, 3 },{ 10, 2, 7, 8 },{ 5, 14, 6, 9 } };
	//int nums[] = { 14, 3, 2, 4, 13, 1, 16, 11, 5, 15 };

	for (int i = 0; i < sizeof(nums) / 4; i++)
		table[nums[i]] = 1;

	int ans = 0, n = 5;

	for (int i = 0; i < n; i++) {
		int cnt = 0;
		for (int j = 0; j < n; j++) {
			if (table[board[i][j]] == 1)
				cnt++;
		}
		if (cnt == n)
			ans++;
		cnt = 0;
	}

	for (int i = 0; i < n; i++) {
		int cnt = 0;
		for (int j = 0; j < n; j++) {
			if (table[board[j][i]] == 1)
				cnt++;
		}
		if (cnt == n)
			ans++;
		cnt = 0;
	}

	int cnt = 0;
	for (int i = 0; i < n; i++) {
		if (table[board[i][i]] == 1)
			cnt++;
	}
	if (cnt == n)
		ans++;

	cnt = 0;
	for (int i = 0; i < n; i++) {
		if (table[board[i][n - i - 1]] == 1)
			cnt++;
	}
	if (cnt == n)
		ans++;

	printf("%d\n", ans);
}