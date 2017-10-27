#include <cstdio>
#include <vector>
#include <string>
#pragma warning(disable:4996)

using namespace std;

int main() {
	vector<string> v;

	v.push_back("2016 - 09-15 20:59 : 57.421 0.351s");
	v.push_back("2016 - 09-15 20:59 : 58.233 1.181s");
	v.push_back("2016 - 09-15 20:59 : 58.299 0.8s");
	v.push_back("2016 - 09-15 20:59 : 58.688 1.041s");
	v.push_back("2016 - 09-15 20:59 : 59.591 1.412s");
	v.push_back("2016 - 09-15 21:00 : 0.464 1.466s");
	v.push_back("2016 - 09-15 21:00 : 0.741 1.581s");
	v.push_back("2016 - 09-15 21:00 : 0.748 2.31s");
	v.push_back("2016 - 09-15 21:00 : 0.966 0.381s");
	v.push_back("2016 - 09-15 21:00 : 2.066 2.62s");

	for (int i = 0; i < v.size(); i++) {
		v[i] = v[i].substr(13, v[i].length());
	}

	for (int i = 0; i < v.size(); i++)
		printf("%s\n", v[i].c_str());

	int h, m = 0;
	float s = 0, ss = 0;

	for (int i = 0; i < v.size(); i++) {
		int secs = 0, num = 0;
		if (sscanf(v[i].c_str(), "%d:%d : %f %fs", &h, &m, &s, &ss) >= 2) {
			secs = h * 3600000 + m * 60000 + (int)(s * 1000);
			num = (int)(ss * 1000);
		}
		printf("%d : %d %d %f %f\n", secs, h, m, s, ss);
	}
}