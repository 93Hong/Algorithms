#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

/*
* Description :
* Time complexity:
* Space complexity:
*/
int isEnableDrive(const vector<int> &E, const vector<int> &C) {

	int size = E.size();

	for (int start = 0; start < size; start++) {
		int num = size, energy = 0, cur = start;
		bool done = true;
		
		while (num--) {
			energy += E[cur];
			if (energy < C[cur]) {
				done = false;
				break;
			}
			energy -= C[cur];

			cur = (cur + 1) % size;
		}
		if (done) {
			return start;
		}
	}

	return -1;
}

int main(int argc, const char *argv[]) {
	int T = 0, N = 0;

		cin >> T;
		for (int i = 0; i < T; i++) {
			vector<int> E, C;
				cin >> N;

			for (int i = 0; i < N; i++) {
				int energy = 0;
				cin >> energy;
				E.push_back(energy);
			}

			for (int i = 0; i < N; i++) {
				int cost = 0;
				cin >> cost;
				C.push_back(cost);
			}

			cout << isEnableDrive(E, C) << endl;
		}
}
