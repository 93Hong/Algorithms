#include <cstdio>
#include <string>
#include <vector>
#pragma warning(disable:4996)

using namespace std;

int ans[101];

int main() {
	int n = 5, m = 5;
	vector<string> s;
	s.push_back("ab");
	s.push_back("aab");
	s.push_back("abb");
	s.push_back("abab");
	s.push_back("abaaaba");
	int cur = 0;
	
	while (n--) {
		
		for (int i = 0; i < s[cur].length() - 1; i++) {
			if (s[cur][i] == s[cur][i + 1]) {
				s[cur][i + 1] = '.';
				ans[cur]++;
			}
		}
		cur++;
	}

	for (int i = 0; i < m; i++)
		printf("%d\n", ans[i]);
}