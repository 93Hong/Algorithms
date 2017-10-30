#include <cstdio>
#include <cctype>
#include <vector>
#include <queue>
#include <map>
#include <iostream>
#pragma warning(disable:4996)
using namespace std;

int main() {
	map<char, int> m;
	char input;
	while (1) {
		input = cin.get();
		if (!islower(input)) break;
		if (m.count(input)) m[input]++;
		else m[input] = 1;
	}
	if (m.count(input)) m.erase(input);
	if (pos->second == value) {
		coll.erase(pos++);
	}
	for (auto current : m)
		cout << current.first << ": " << current.second << endl;

}

