#include <cstdio>
#include <vector>
#include <map>
#pragma warning(disable:4996)

using namespace std;

int main() {
	map<string, int> m;
	
	m.insert({ "aaa", 3 });
	m.insert({ "aad", 5 });
	m.insert({ "aac", 2 });
	m.insert({ "aab", 1 });

	m.insert({ "aaa", 4 });


	printf("%d\n", m.find("aaa")->second);
	printf("%d\n", m.find("aac")->second);

	vector<pair<string, int>> vec(m.begin(), m.end());

	for (int i = 0; i < vec.size(); i++)
		printf("%s %d\n", vec[i].first, vec[i].second);


}