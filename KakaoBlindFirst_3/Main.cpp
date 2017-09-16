#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<string> vec;

int maxSize;
int curSize = 1;

bool checkCache(string &str, int length) {
	int cacheSize;

	for (int i = 0; i < curSize; i++) {
		cacheSize = vec[i].length();

		if (cacheSize == length) {
			for (int j = 0; j < cacheSize; j++) {
				if (vec[i][j] > 'a' + 1)
					vec[i][j] -= 32;

				if (str[j] > 'a' + 1)
					str[j] -= 32;
				
				if (vec[i][j] == str[j]) {
					if (j == cacheSize - 1) {
						string s = vec[i];
						vec.erase(vec.begin() + i);
						vec.push_back(s);
						return true;
					}
					continue;
				}
				else break;
			}
		}
	}

	return false;
}

int solution(int cacheSize, vector<string> cities) {
	int answer = 0;
	vec.push_back(cities[0]);
	maxSize = cacheSize;

	if (cacheSize == 0)
		return cities.size() * 5;

	for (int i = 1; i < cities.size(); i++)
		if (checkCache(cities[i], cities[i].length()))
			answer += 1;
		else {
			answer += 5;
			if (curSize < maxSize) {
				vec.push_back(cities[i]);
				curSize++;
			}
			else {
				vec.erase(vec.begin());
				vec.push_back(cities[i]);
			}
		}

	return answer + 5;
}


#include <string>
#include <vector>
#include <iostream>
using namespace std;
vector<string> cache;
int maxVectorSize;
int nowCacheSize = 1;
bool checkCache(string &str, int len) {
	int Clen;
	for (int i = 0; i < nowCacheSize; i++) {
		Clen = cache[i].length();

		if (Clen == len) {
			for (int j = 0; j < Clen; j++) {
				if (cache[i][j] >96) cache[i][j] -= 32;
				if (str[j] >96) str[j] -= 32;
				if (cache[i][j] == str[j]) {
					if (j == Clen - 1) { // hit;
						string s = cache[i];
						cache.erase(cache.begin() + i);
						cache.push_back(s);
						return true;
					}
					continue;
				}
				else break;
			}
		}
	}

	return false;
}

int solution(int cacheSize, vector<string> cities) {
	int answer = 5;
	maxVectorSize = cacheSize;
	int len = cities.size();
	cache.push_back(cities[0]);

	if (cacheSize == 0) {
		return cities.size() * 5;
	}
	for (int i = 1; i < len; i++) {
		if (checkCache(cities[i], cities[i].length())) {
			answer += 1;
		}
		else {
			answer += 5;
			if (nowCacheSize < maxVectorSize) {
				cache.push_back(cities[i]);
				nowCacheSize++;
			}
			else {

				cache.erase(cache.begin());
				cache.push_back(cities[i]);
			}
		}
	}

	return answer;
}