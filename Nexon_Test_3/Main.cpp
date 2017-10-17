#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#pragma warning(disable:4996)

using namespace std;

vector<string> v;
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
	long long n, m = 5;
	string s = "1111101";

	n = stoll("1111111111111111");

	while (n > m) {
		long long num = m;
		string s1;
		while (num > 0) {
			s1 += (num % 2) + '0';
			num /= 2;
		}
		reverse(s1.begin(), s1.end());
		v.push_back(s1);
		m *= 5;
	}

	reverse(v.begin(), v.end());

	for (int i = 0; i < v.size(); i++)
		cout << v[i] << endl;

	printf("%d\n", solution(v, s));
}