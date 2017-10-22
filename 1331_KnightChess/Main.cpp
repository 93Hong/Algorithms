#include <cstdio>
#include <string>
#include <iostream>
#include <set>
#pragma warning(disable:4996)

using namespace std;

int night[8][2] = { {1, -2},  {1, 2}, {2, -1}, {2, 1}, {-1, 2}, {-1, -2}, {-2, 1}, {-2, -1} };
set<string> se;


int main() {
	string s;
	cin >> s;
	string start = s;
	se.insert(s);
	bool ok = true;
	for (int i = 1; i < 36; i++) {
		string s2;
		cin >> s2;
		se.insert(s2);
		
		bool flag = false;

		for (int j = 0; j < 8; j++) {
			if (s[0] + night[j][0] == s2[0] && s[1] + night[j][1] == s2[1]) {
				flag = true;
				break;
			}
		}

		if (flag == false) {
			ok = false;
			break;
		}

		s = s2;
	}

	bool ok2 = false;

	for (int j = 0; j < 8; j++) {
		if (s[0] + night[j][0] == start[0] && s[1] + night[j][1] == start[1]) {
			ok2 = true;
			break;
		}
	}

	if (ok && ok2 && se.size() == 36)
		printf("Valid\n");
	else
		printf("Invalid\n");
}