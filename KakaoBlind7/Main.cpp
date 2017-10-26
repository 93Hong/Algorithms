#include <cstdio>
#include <functional>
#include <vector>
#include <algorithm>
#include <string>

#define INF 100000000

#pragma warning(disable:4996)

using namespace std;

vector<string> v;

int main() {
	v.push_back("2016 - 09-15 20:59 : 57.421 0.351s");
	v.push_back("2016 - 09-15 20:59 : 58.233 1.181s");
	v.push_back("2016 - 09-15 20:59 : 58.299 0.8s");
	v.push_back("2016 - 09-15 20:59 : 58.688 1.041s");
	v.push_back("2016 - 09-15 20:59 : 59.591 1.412s");
	v.push_back("2016 - 09-15 20:60 : 60.464 1.466s");
	v.push_back("2016 - 09-15 20:60 : 60.741 1.581s");
	v.push_back("2016 - 09-15 20:60 : 60.748 2.31s");
	v.push_back("2016 - 09-15 20:60 : 60.966 0.381s");
	v.push_back("2016 - 09-15 20:60 : 62.066 2.62s");

	vector<pair<int, int>> v2;

	for (int i = 0; i < v.size(); i++) {
		int num = 0;
		for (int j = 18; j < 28; j++) {
			if (isdigit(v[i][j])) {
				num *= 10;
				num += v[i][j] - '0';
			}
		}
		int num2 = 0;
		for (int j = 28; j < 33; j++) {
			if (isdigit(v[i][j])) {
				num2 *= 10;
				num2 += v[i][j] - '0';
			}
			else if (v[i][j] != '.'){
				num2 *= 10;
			}
		}
		num2 -= 1;
		v2.push_back(make_pair(num - num2, num));
	}

	

	for (int i = 0; i < v2.size(); i++)
		printf("%d %d\n", v2[i].first, v2[i].second);

	int maxV = 0, window = 999;
	for (int i = 0; i < v2.size(); i++) {
		int cnt = 0;
		for (int j = i + 1; j < v2.size(); j++) {
			if (i == j)
				continue;
			if (v2[i].second + window >= v2[j].first) {
				//printf("%d %d\n", v2[i].second + window, v2[j].first);
				cnt++;
			}
		}
		if (maxV < cnt)
			maxV = cnt;
	}

	sort(v2.begin(), v2.end(), [](auto &left, auto &right) {
		return left.second < right.second;
	});

	int maxV2 = 0;
	for (int i = v2.size() - 1; i >= 0; i--) {
		int cnt = 0;
		for (int j = i; j >= 0; j--) {
			if (i == j)
				continue;
			if (v2[i].first - window >= v2[j].second)
				cnt++;
		}
		if (maxV2 < cnt) {
			printf("%d %d\n", i, cnt);
			maxV2 = cnt;
		}
	}

	printf("%d\n", max(maxV, maxV2));
}