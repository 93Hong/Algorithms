#include <cstdio>
#include <iostream>
#include <set>
#include <string>
#pragma warning (disable : 4996)

using namespace std;

set<string> s;

int main() {
	s.insert("aa");
	s.insert("bc");
	s.insert("ab");
	s.insert("ba");
	s.insert("ac");

	set<string>::reverse_iterator i;

	for (i = s.rbegin(); i != s.rend(); i++)
		cout << *i << endl;
}