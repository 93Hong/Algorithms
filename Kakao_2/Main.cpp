#include <cstdio>
#include <algorithm>
#include <vector>
#pragma warning (disable : 4996)

using namespace std;
vector<int> nums;
pair<int, int> re[1000001];

bool comp(pair<int, int> &A, pair<int, int> &B) {
	if (A.second == B.second)
		return A.first < B.first;
	return A.second < B.second;
}

int main() {
	nums.push_back(31);
	nums.push_back(15);
	nums.push_back(7);
	nums.push_back(3);
	nums.push_back(2);

	for (int i = 0; i < nums.size(); i++) {
		int cnt = 0;
		re[i].first = nums[i];
		while (nums[i] != 0) {
			if (nums[i] & 1)
				cnt++;
			nums[i] >>= 1;
		}
		
		re[i].second = cnt;
	}
	
	sort(re, re+nums.size(), comp);

	for (int i = 0; i < nums.size(); i++) {
		printf("%d ", re[i].first);
	}

	return 0;
}