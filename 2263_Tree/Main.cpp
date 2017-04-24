#include <cstdio>
#pragma warning(disable: 4996)

using namespace std;

int in[100001], pre[100001], post[100001], cur = 0, position[100002];

void tree(int inS, int inE, int postS, int postE) {
	int root = post[postE];
	int rootLoc, length;

	if (inS > inE || postS > postE)
		return;

	rootLoc = position[root];
	length = rootLoc - inS;
	pre[cur++] = in[rootLoc];

	tree(inS, rootLoc - 1, postS, length + postS - 1);
	tree(rootLoc + 1, inE, length + postS, postE - 1);
}

int main() {
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
		scanf("%d", &in[i]);
	for (int i = 0; i < n; i++)
		scanf("%d", &post[i]);
	for (int i = 1; i < n + 1; i++)
		position[in[i]] = i;

	tree(0, n - 1, 0, n - 1);

	for (int i = 0; i < n; i++)
		printf("%d ", pre[i]);
}