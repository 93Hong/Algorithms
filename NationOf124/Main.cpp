#include<iostream>
#include<vector>
#include <deque>
#include <string>

using namespace std;

char ch[4] = { '4', '1', '2' };

string change124(int no)
{
	string answer = "";

	while (no > 0) {
		//answer += tostring(ch[no % 3]);
		printf("%c %d\n", ch[no % 3], no);
		no /= 3;
	}

	return answer;
}

int main() {
	deque<string> q;
	
	q.push_back("1");
	q.push_back("2");
	q.push_back("4");
	q.push_back("3");
	q.push_back("5");

	int size = q.size();

	string str = "6";

	if (find(q.begin(), q.end(), str) != q.end()) {
		for (int i = 0; i < size; i++) {
			if (q[i].compare(str) == 0) {
				for (int j = 0; j < size; j++) {
					if (i == j) {
						q.pop_front();
						continue;
					}
					string a = q.front();
					q.pop_front();
					q.push_back(a);
				}
				break;
			}
		}
		q.push_back(str);
	}
	else {
		q.pop_front();
		q.push_back(str);
	}
	for (int i = 0; i < 5; i++) {
		string c = q.front();
		printf("%s ", c.c_str());
		q.pop_front();
		q.push_back(c);
	}
	printf("\n");
	

}
