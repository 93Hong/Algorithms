#include <cstdio>
#include <vector>
#include <iostream>
#include <string>
#include <sstream>
#include <iterator>
#pragma warning(disable:4996)

using namespace std;

int main() {
	int n = 3, r, c;

	vector<string> st;
	st.push_back("23 3");
	st.push_back("32 7");
	st.push_back("4 1");

	

	long x = 2000000, y = 2000000;
	for (int i = 0; i < st.size(); i++) {
		long pre[2];

		istringstream buf(st[i]);
		istream_iterator<std::string> beg(buf), end;

		vector<std::string> tokens(beg, end); // done!
		int cnt = 0;
		for (auto& s : tokens) {
			pre[cnt] = stol(s);
			cnt++;
		}


		if (x > pre[0])
			x = pre[0];
		if (y > pre[1])
			y = pre[1];
	}
	printf("%ld\n", x*y);
}