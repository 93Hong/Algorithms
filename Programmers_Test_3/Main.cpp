#include <string>
#include <vector>
using namespace std;

int minn = 30000;
vector<string> st;

void solve(string s1, int cnt) {
	if (cnt >= minn)
		return;
	if (s1.length() == 0) {
		if (minn > cnt)
			minn = cnt;
		return;
	}

	for (int i = 0; i < st.size(); i++) {
		if (s1.find(st.at(i)) == 0) {
			string s2 = s1.substr(st.at(i).length());
			solve(s2, cnt + 1);
		}
	}
}

int solution(vector<string> strs, string t) {
	int answer = 0;
	st = strs;
	solve(t, 0);

	if (minn == 30000)
		answer = -1;
	else
		answer = minn;

	return answer;
}