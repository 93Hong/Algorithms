#include <cstdio>
#include <vector>
#pragma warning(disable:4996)

using namespace std;

int map[2][2] = { {1, 2}, {3, 4} }, map2[2][2];


vector<vector<int>> solution(
	vector<vector<int>> maxtrix)
{
	vector<vector<int>> answer;


}
int main() {
	int n = 2, arr[2], r = 2;

	r = (r % 4);

	while (r--) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				arr[j] = map[i][j];
			}

			int k = n - i - 1;
			for (int j = 0; j < n; j++) {
				map2[j][k] = arr[j];
			}
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				map[i][j] = map2[i][j];
			}
		}
	}
}