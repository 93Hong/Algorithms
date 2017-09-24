#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <iterator>
#include <vector>
#include <queue>
#pragma warning(disable : 4996)

using namespace std;

int main() {
	
	string s;
	getline(cin, s);

	istringstream iss(s);
	vector<string> vec { istream_iterator<string>{iss},
		istream_iterator<string>{} };

	int cnt = stoi(vec[2]);

	if (vec[0].compare("encrypt") == 0) {
		for (int i = 0; i < vec[3].length(); i++) {
			if (vec[3][i] + (vec[1][i] - 'a') > 'z') {
				vec[3][i] = vec[3][i] + (vec[1][i] - 'a') - 26;
			}
			else {
				vec[3][i] = vec[3][i] + (vec[1][i] - 'a');
			}
		}
		string str = vec[3];
		for (int i = 0; i < vec[3].length(); i++) {
			vec[3][i] = str[(i + cnt) % vec[3].length()];
		}
	}
	else {
		string str = vec[3];
		for (int i = 0; i < vec[3].length(); i++) {
			vec[3][i] = str[(i - cnt) % vec[3].length()];
		}
		for (int i = 0; i < vec[3].length(); i++) {
			if (vec[3][i] - (vec[1][i] - 'a') < 'a') {
				vec[3][i] = vec[3][i] - (vec[1][i] - 'a') + 26;
			}
			else {
				vec[3][i] = vec[3][i] - (vec[1][i] - 'a');
			}
		}
	}

	cout << vec[3];

}