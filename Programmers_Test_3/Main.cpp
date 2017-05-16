#include <string>
#include <vector>
using namespace std;

int db[5][20001];
int minn[20001];

int solution(vector<string> strs, string t) {
	int answer = 0, maxSize = 0;

	for (int i = 0; i < strs.size(); i++)
		if (maxSize < strs.at(i).length())
			maxSize = strs.at(i).length();

	for (int i = 0; i < t.length(); i++) {
		int minInt = 22222;
		for (int j = 0; j < maxSize; j++) {
			if (j > i)
				break;
			string tmp = t.substr(i - j, j + 1);

			for (int k = 0; k < strs.size(); k++) {
				if (tmp.compare(strs.at(k)) == 0) {
					int tm = minn[i - 1 - j] + 1;
					db[j][i] = tm;
					if (i == j)
						tm = 1;
					if (minInt > tm)
						minInt = tm;
				}
			}
		}
		minn[i] = minInt;
	}

	answer = minn[t.length() - 1];
	if (answer == 0)
		answer = -1;

	return answer;
}

int main() {
	vector<string> strs;
	strs.push_back("ba");
	strs.push_back("na");
	strs.push_back("n");
	strs.push_back("a");
	string t = "banana";

	printf("%d\n", solution(strs, t));
}
