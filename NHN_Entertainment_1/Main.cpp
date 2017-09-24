#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <iterator>
#include <vector>
#include <deque>
#pragma warning(disable : 4996)

using namespace std;

int arr[7];
deque<int> q;

int main() {

	int c{ 3 };
	int d(5);

	string s;
	getline(cin, s);
	istringstream iss(s);


	vector<string> vec { istream_iterator<string>{iss},
		istream_iterator<string>{} };

	int cnt = 0, cur = 0;

	while (1) {
		int tmp = stoi(vec[cur]);
		
		if (arr[tmp] == 0) {
			arr[tmp] = 1;
			cnt++;
			q.push_back(tmp);
		}
		if (cnt == 3 || cur == vec.size() - 1)
			break;
		cur++;
	}

	if (cnt != 3) {
		printf("0\n");
	}
	else {
		int size = 3;

		for (int i = cur + 1; i < vec.size(); i++) {
			int tmp = stoi(vec[i]);
			if (arr[tmp] == 0) {
				arr[tmp] = 1;
				q.push_back(tmp);
				size++;
			}
			else {
				for (int j = 0; j < q.size(); j++) {
					if (q.at(0) != tmp) {
						int a = q.front();
						q.pop_front();
						q.push_back(a);
					}
				}
				int a = q.front();
				q.pop_front();
				q.push_back(a);
			}
			if (size > 3) {
				printf("%d\n", q.front());
				arr[q.front()] = 0;
				size--;
				q.pop_back();
			}
		}
	}
}