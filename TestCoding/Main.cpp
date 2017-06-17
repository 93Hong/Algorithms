#include <string>
#include <vector>
using namespace std;

vector<int> solution(vector<int> truck, vector<int> w) {
	vector<int> answer;
	bool ch = false;

	for (int i = 0; i < w.size(); i++) {
		for (int j = 0; j < truck.size(); j++) {
			if (w[i] <= truck[j]) {
				truck[j] -= w[i];
				answer.push_back(j + 1);
				ch = true;
				break;
			}
		}

		if (ch)
			ch = false;

		else
			answer.push_back(-1);
	}

	return answer;
}