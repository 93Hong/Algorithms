#include <cstdio>
#include <queue>
#include <vector>
#pragma warning(disable:4996)

using namespace std;

vector<int> T;
queue<int> q;
vector<int> graph[100001];
int d[100001];

int main() {
	
	int a, b;

	T.push_back(9);
	T.push_back(1);
	T.push_back(4);
	T.push_back(9);
	T.push_back(0);
	T.push_back(4);
	T.push_back(8);
	T.push_back(9);
	T.push_back(0);
	T.push_back(1);

	int capital, level = 0;

	for (int i = 0; i < T.size(); i++) {
		if (i == T[i]) {
			capital = i;
			continue;
		}
		graph[i].push_back(T[i]);
		graph[T[i]].push_back(i);
	}

	vector<int> ans(T.size() - 1, 0);
	for (int i = 0; i < T.size(); i++) {
		d[i] = 0;
	}

	q.push(capital);
	d[capital] = 1;

	
	while (!q.empty() && level != T.size() - 1) {
		
		int size = q.size();
		for (int j = 0; j < size; j++) {
			a = q.front();
			q.pop();
			int cnt = 0;
			for (int i = 0; i < graph[a].size(); i++) {
				b = graph[a][i];
				
				if (d[b] == 0) {
					d[b] = 1;
					q.push(b);
					cnt++;
				}
			}
		}
		ans[level] = q.size();
		level++;
	}

	for (int i = 0; i < T.size() - 1; i++) {
		printf("%d ", ans[i]);
	}
}