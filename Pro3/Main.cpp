#include <vector>
using namespace std;

vector<int> s;
int d[100001][2];

void solve() {
	solve()
}

int main() {//[14, 6, 5, 11, 3, 9, 2, 10]
	s.push_back(14);
	s.push_back(6);
	s.push_back(5);
	s.push_back(11);
	s.push_back(3);
	s.push_back(9);
	s.push_back(2);
	s.push_back(10);
	
	d[0] = 14;
	d[1] = 6;
	for (int i = 2; i < s.size(); i++) {
		if (d[i - 1] + s.at(i) > d[i - 2] + s.at(i - 1)) {
			d[i] = d[i - 1] + s.at(i);
		}
		else {
			d[i] = d[i - 2] + s.at(i - 1);
		}
	}
	printf("%d\n", d[s.size()-1]);
}