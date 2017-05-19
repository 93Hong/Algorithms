#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int dp[20001];
vector<string> strs;
string t;

void solve(int start) {
	if (start > t.length() - 1)
		return;
	for (int i = 0; i < strs.size(); i++) {
		bool flag = true;
		if (t.length() < start + strs.at(i).length())
			continue;
		for (int j = 0; j < strs.at(i).length(); j++) {
			if (t[start + j] != strs.at(i).at(j)) {
				flag = false;
				break;
			}
		}
		int len = strs.at(i).length();
		if (flag) {
			if (dp[start] == 0)
				dp[start + len] = 1;
			else if (dp[start + len] == 0)
				dp[start + len] =  dp[start] + 1;
			else
				dp[start + len] = min(dp[start + len], dp[start] + 1);
			solve(start + len);
		}
	}
}

int solution(vector<string> strs, string t) {
	int answer = 0;

	solve(0);

	answer = dp[t.length()];
	if (answer == 0)
		answer = -1;
	
	for (int i = 0; i < t.length() + 1; i++)
		printf("%d ", dp[i]);
	printf("\n");
	return answer;
}

int main() {
	//["app","ap","p","l","e","ple","pp"]	"apple
	strs.push_back("a");
	strs.push_back("p");
	strs.push_back("app");
	strs.push_back("l");
	strs.push_back("le");
	strs.push_back("e");
	strs.push_back("ee");
	t = "apple";

	printf("%d\n", solution(strs, t));
}
