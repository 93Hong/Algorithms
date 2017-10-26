#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#pragma warning(disable:4996)

using namespace std;

int nextBus(int bus, int t) {
	bus += t;
	if (bus % 100 >= 60) {
		bus += 100;
		bus -= 60;
	}
	return bus;
}

// 10, 60, 45 / 00:01 ~ 23:59
string solution(int n, int t, int m, vector<string> timetable) {
	int answer = 0;
	sort(timetable.begin(), timetable.end());
	queue<int> q;

	int bus = 900;

	for (int i = 0; i < timetable.size(); i++) {
		q.push(stoi(timetable[i].substr(0, 2)) * 100 + stoi(timetable[i].substr(3, 2)));
	}
	
	int last;
	int size = timetable.size();

	for (int i = 0; i < n; i++) {
		int cnt = 0;
		for (int j = 0; j < m; j++) {
			if (!q.empty() && q.front() < bus) {
				last = q.front();
				q.pop();
				cnt++;
				printf("%d\n", last);
			}
			if (i == n - 1 && j == m - 1)
				if (cnt == m) {
					printf("f");
					answer = last;
					if (answer % 100 == 0)
						answer = answer -100 + 59;
					else
						answer = answer - 1;
				}
				else {
					printf("s");
					answer = bus;
					if (q.front() == answer) {
						answer = q.front();
						if (answer % 100 == 0) {
							answer = answer - 100 + 59;
						}
						else
							answer = answer - 1;
					}
				}
		}
		printf("\n\n");
		bus = nextBus(bus, t);
	}

	string f, s;
	if (answer / 100 < 10)
		f = "0" + to_string(answer / 100);
	else if (answer / 100 == 0) {
		f = "00";
	}
	else
		f = to_string(answer / 100);
	f += ":";

	if (answer % 100 < 10)
		s = "0" + to_string(answer % 100);
	else if (answer % 100 == 0) {
		s = "00";
	}
	else
		s = to_string(answer % 100);

	f += s;

	return f;
}

int main() {
	vector<string> timetable;
	timetable.push_back("23:59");

	printf("%s\n", solution(10, 60, 1, timetable).c_str());
}


#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>
#include <string>
#pragma warning(disable:4996)

using namespace std;

int main() {
	int n, t, m;
	scanf("%d %d %d", &n, &t, &m);

	vector<string> v;
	v.push_back("23:59");
	v.push_back("23:59");
	v.push_back("23:59");
	v.push_back("23:59");
	v.push_back("23:59");
	v.push_back("23:59");
	v.push_back("23:59");
	v.push_back("23:59");
	v.push_back("23:59");
	v.push_back("23:59");
	v.push_back("23:59");
	v.push_back("23:59");
	v.push_back("23:59");
	v.push_back("23:59");
	v.push_back("23:59");
	v.push_back("23:59");
	sort(v.begin(), v.end());

	queue<int> q;

	for (int i = 0; i < v.size(); i++) {
		q.push(stoi(v[i].substr(0, 2)) * 100 + stoi(v[i].substr(3, 4)));
	}

	int time = 900, ans = 900;

	for (int i = 0; i < n; i++) {
		int num = 0, last = 0;
		for (int j = 0; j < m; j++) {
			if (!q.empty() && q.front() <= time) {
				last = q.front();
				q.pop();
				num++;
			}
		}
		if (i == n - 1) {
			if (num == m) {
				ans = last - 1;
			}
			else {
				ans = time;
			}
		}

		time += t;
		if (time % 100 >= 60) {
			time += 100;
			time -= 60;
		}
	}
	printf("%d\n", ans);
}