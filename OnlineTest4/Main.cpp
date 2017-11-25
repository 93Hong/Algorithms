#include <iostream>

using namespace std;

struct Node {
	int table[256] = { 0 };
	int total = 0;
};

/*
* Description :
* Time complexity : O(N*W)
* Space complexity : O(
*/
bool selectWeight(const int data[][2], int result[], int N, int W) {
	// TODO implement your codes to here.

	Node node[257];
	for (int i = 0; i < N; i++) { // 추 종류 갯수
		for (int j = 1; j <= W; j++) { // 재려는 무게
			if (data[i][0] > j)continue; // 무게추 : 개수

			if (data[i][0] == j) {
				node[j].table[i] = 1;
				node[j].total = 1;
			}
			else {
				if (node[j - data[i][0]].total != 0) {
					if (node[j].total == 0) {
						if (node[j - data[i][0]].table[i] < data[i][1]) {
							node[j] = node[j - data[i][0]];
							node[j].table[i]++;
							node[j].total++;
						}
					}
					else {
						if (node[j].total > node[j - data[i][0]].total + 1) {
							if (node[j - data[i][0]].table[i] < data[i][1]) {
								node[j] = node[j - data[i][0]];
								node[j].table[i]++;
								node[j].total++;
							}
						}
					}
				}
			}
		}
	}

	if (node[W].total > 0) {
		for (int i = 0; i < N; i++) {
			result[i] = node[W].table[i];
		}
		//delete[] node;
		return true;
	}
	return false;
}

int main(int argc, const char *argv[]) {
	int TC, W, N;
	cin >> TC;

	for (int tc = 1; tc <= TC; ++tc) {
		cin >> W;
		cin >> N;

		int data[N][2];
		int result[N];

		for (int i = 0; i < N; ++i) {
			cin >> data[i][0] >> data[i][1];
			result[i] = 0;
		}

		cout << "#" << tc << endl;
		if (!selectWeight(data, result, N, W)) {
			cout << "FAIL" << endl;
		}
		else {
			for (int i = 0; i < N; ++i) {
				cout << data[i][0] << " " << result[i] << endl;
			}
		}
	}
	return 0;
}