#include <cstdio>
#include <string>
#pragma warning(disable:4996)

using namespace std;

int main() {
	string S = "SMS messages aaaaa dddddd dd d sdddd s";
	int K = 12;

	int cursor = 0, ans = 0, indexOfSpace = 0, msgLength = 0, lastSplitIndex = 0;

	while (cursor <= S.length()) {
		if (K < msgLength) {
			bool tooLongWord = lastSplitIndex == indexOfSpace + 1;
			if (indexOfSpace == 0 || tooLongWord) {
				return -1;
			}
			cursor = indexOfSpace + 1;
			lastSplitIndex = cursor;
			msgLength = -1;
			ans++;
		}
		if (S[cursor] == ' ') {
			indexOfSpace = cursor;
		}

		cursor++;
		msgLength++;
	}
	if (ans == 0 && S.length() > K) {
		return -1;
	}
	else if (msgLength == 0) {
		return ans;
	}
	else {
		return ans + 1;
	}
}