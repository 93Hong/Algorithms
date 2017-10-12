#include <cstdio>
#include <iostream>
#include <string>
#pragma warning(disable:4996)

using namespace std;

int main() {
	string s1, s2;
	cin >> s1;
	cin >> s2;

	int n;
	scanf("%d", &n);

	while (n--) {
		string tmp;
		cin >> tmp;
		int x = 0, y = 0;

		if (tmp.size() == 1) {

			if (tmp.compare("R") == 0)
				x++;
			else if (tmp.compare("L") == 0)
				x--;
			else if (tmp.compare("B") == 0)
				y--;
			else
				y++;

		}
		else {

			if (tmp[0] == 'R' && tmp[1] == 'T') {
				x++;
				y++;
			}
			else if (tmp[0] == 'R' && tmp[1] == 'B') {
				x++;
				y--;
			}
			else if (tmp[0] == 'L' && tmp[1] == 'T') {
				x--;
				y++;
			}
			else {
				x--;
				y--;
			}

		}

		string ss1, ss2;
		ss1 += (s1[0] + x);
		ss1 += (s1[1] + y);

		if (ss1.compare(s2) == 0) {
			ss2 += (s2[0] + x);
			ss2 += (s2[1] + y);
		}
		else
			ss2 = s2;

		if ((ss1[0] >= 'A' && ss1[0] <= 'H' && ss1[1] >= '1' && ss1[1] <= '8')
			&& ss2[0] >= 'A' && ss2[0] <= 'H' && ss2[1] >= '1' && ss2[1] <= '8') {
			s1 = ss1;
			s2 = ss2;
		}
	}

	cout << s1 << endl;
	cout << s2 << endl;
}