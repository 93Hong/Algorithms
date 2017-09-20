#include <cstdio>
#include <vector>
#include <map>
#pragma warning(disable:4996)

using namespace std;

int main() {
	map<string, int> m;
	
	m.insert(pair<string, int>("aaa", 3));
	m.insert(pair<string, int>("aab", 1));
	m.insert(pair<string, int>("aac", 5));
	m.insert(pair<string, int>("aac", 5));
	m.insert(pair<string, int>("aac", 5));
	m.insert(pair<string, int>("bac", 5));

	vector<pair<string, int>> vec(m.begin(), m.end());

	for (int i = 0; i < vec.size(); i++)
		printf("%s %d\n", vec[i].first, vec[i].second);
}	