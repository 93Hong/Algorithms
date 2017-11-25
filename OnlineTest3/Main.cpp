#include <iostream>
#include <string>
#include <regex>

using namespace std;

/*
* Description :
* Time complexity :
* Space complexity :
*/
bool match(string &pat, string &s) {
	// TODO implement your codes to here.

	for (int i = pat.length(); i >= 0; i--) {
		if (pat[i] == '?')
			pat[i] = '.';
		else if (pat[i] == '*') {
			char repeatChar = pat[i + 1];
			pat[i] = repeatChar;
			pat[i + 1] = '*';
		}
	}

	regex e(pat);
	return regex_match(s, e);
}

int main(int argc, const char *argv[]) {
	int TC;
	string pattern, target_string;
	cin >> TC;
	for (int t = 0; t < TC; t++) {
		cin >> pattern >> target_string;
		cout << (match(pattern, target_string) ? 'O' : 'X') << endl;
	}
	return 0;
}
