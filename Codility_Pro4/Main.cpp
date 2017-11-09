#include <cstdio>
#include <string>
#include <unordered_set>
#include <vector>
#pragma warning(disable:4996)

using namespace std;

int main() {
	string S = "abbabba";
	string front, end;
	unordered_set<string> stringSet;
	vector<int> v;
	int ans = 0, stringSize = S.length();
	char lastChar = S[stringSize - 1], firstChar = S[0];

	for (int i = 0; i < stringSize - 1; i++) {
		char c = S[i];
		front += c;
		if (firstChar == S[stringSize - 1 - i] && c == lastChar) {
			v.push_back(i);
			stringSet.insert(front);
		}
	}

	int j = 0;
	for (int i = stringSize - 1; i > 0; i--) {
		end = S[i] + end;
		if (j == v.size())
			break;
		if (v[j] == stringSize - 1 - i) {
			j++;
			if (stringSet.find(end) != stringSet.end())
				ans = end.length();
		}
	}
	
	return ans;
}