#include <cstdio>
#include <string>
#include <algorithm>
#include <ctype.h>
#include <map>
#include <vector>
#pragma warning(disable: 4996)

using namespace std;

int solution(string str1, string str2) {
	map<string, int> m, m2;
	vector<string> vec, vec2;
	int answer = 0;

	transform(str1.begin(), str1.end(), str1.begin(), ::tolower);
	transform(str2.begin(), str2.end(), str2.begin(), ::tolower);

	for (int i = 0; i < str1.length() - 1; i++) {
		if (!isalpha(str1[i]) || !isalpha(str1[i+1]))
			continue;
		vec.push_back(str1.substr(i, 2));
	}
	for (int i = 0; i < vec.size(); i++) {
		if (m.find(vec[i]) == m.end())// not found
			m.insert(pair<string, int>(vec[i], 1));
		else// found
			m.find(vec[i])->second++;
		printf("%s ", vec[i].c_str());
	}

	printf("\n\n");

	for (int i = 0; i < str2.length() - 1; i++) {
		if (!isalpha(str2[i]) || !isalpha(str2[i + 1]))
			continue;
		vec2.push_back(str2.substr(i, 2));
	}
	for (int i = 0; i < vec2.size(); i++) {
		if (m2.find(vec2[i]) == m2.end())
			m2.insert(pair<string, int>(vec2[i], 1));
		else
			m2.find(vec2[i])->second++;
		printf("%s ", vec2[i].c_str());
	}
	printf("\n\n");

	for (int i = 0; i < vec.size(); i++) {
		if (m2.find(vec[i]) != m2.end() && m.find(vec[i]) != m.end()) {
			answer += min(m2.find(vec[i])->second, m.find(vec[i])->second);
			m2.find(vec[i])->second = 0; m.find(vec[i])->second = 0;
		}
	}

	for (map<string, int >::const_iterator it = m.begin();
	it != m.end(); ++it) {
		printf("%s %d\n", it->first.c_str(), it->second);
	}
	printf("\n\n");
	for (map<string, int >::const_iterator it = m2.begin();
	it != m2.end(); ++it) {
		printf("%s %d\n", it->first.c_str(), it->second);
	}
	printf("\n\n");
	printf("%d %d\n", answer, (vec.size() + vec2.size() - answer));

	return (double)answer / (double)(vec.size() + vec2.size() - answer) * (double)65536;
}

int main() {
	printf("%d\n", (int)solution("handshake", "shake hands"));

}