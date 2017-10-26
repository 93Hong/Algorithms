#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int dp[20001];

int solve(vector<string> strs, int index, string t) {
	
	if (index == t.length())
		return 0;
	if (dp[index] != 10000000)
		return dp[index];

	for (int i = 0; i < strs.size(); i++) {
		bool flag = true;
		for (int j = 0; j < strs[i].length(); j++) {
			if (t[index + j] != strs[i][j])
				flag = false;
		}
		if (flag) {
			printf("-- %d\n", index);
			dp[index] = min(solve(strs, index + strs[i].length(), t) + 1, dp[index]);
		}
	}
}

int solution(vector<string> strs, string t) {
	for (int i = 0; i < t.length(); i++)
		dp[i] = 10000000;

	return solve(strs, 0, t);
}

int main() {
	vector<string> strs;
	strs.push_back("ba");
	strs.push_back("na");
	strs.push_back("n");
	strs.push_back("a");
	printf("::%d\n", solution(strs, "banana"));

	for (int i = 0; i < 10; i++)
		printf("%d\n", dp[i]);
}