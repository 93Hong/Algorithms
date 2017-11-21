#include <cstdio>
#include <vector>
#pragma warning(disable:4996)

using namespace std;

class Tree {
public:
	int N;
	vector<char> parent;
	vector<char> lc, rc;

	Tree() : N(0) {}
	Tree(int n) : N(n) {
		parent.resize(N, -1);
		lc.resize(N, -1);
		rc.resize(N, -1);
	}

	void setChildren(char p, char l, char r) {
		if (l != -1) parent[p] = l;
		if (r != -1) parent[p] = r;
		lc[p] = l;
		rc[p] = r;
	}
};

int main() {
	int N;
	scanf("%d", &N);

	while (N--) {

	}
}