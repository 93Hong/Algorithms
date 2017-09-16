#include <string>
#include <vector>
#pragma warning(disable:4996)

using namespace std;
vector<string> st;

int check[31][31];
int dir[4][2] = { {0, 0}, {0, 1}, {1, 0}, {1, 1} };

int solution(int m, int n, vector<string> board) {
	int answer = 0;
	bool flag = true;

	while (flag) {
		flag = false;

		for (int i = 0; i < m - 1; i++)
			for (int j = 0; j < n - 1; j++) {
				if (board[i][j] == -1)
					continue;
				if (board[i][j] == board[i + 1][j] && board[i][j] == board[i][j + 1] && board[i][j] == board[i + 1][j + 1]) {
					for (int k = 0; k < 4; k++)
						if (check[i + dir[k][0]][j + dir[k][1]] == 0) {
							check[i + dir[k][0]][j + dir[k][1]] = 1;
							answer++;
						}
					flag = true;
				}
			}

		for (int j = 0; j < n; j++)
			for (int i = m - 1; i >= 0; i--)
				if (check[i][j] == 1)
					board[i][j] = -1;
				else {
					int k = i + 1;

					while (k <= m - 1 && board[k][j] == -1)
						k++;
					if (k == i + 1)
						continue;

					board[k - 1][j] = board[i][j];
					board[i][j] = -1;
				}
		memset(check, 0, sizeof(check));
	}

	return answer;
}

int main() {
	st.push_back("TTTANT");
	st.push_back("RRFACC");
	st.push_back("RRRFCC");
	st.push_back("TRRRAA");
	st.push_back("TTMMMF");
	st.push_back("TMMTTJ");

	printf("%d\n", solution(6, 6, st));
}