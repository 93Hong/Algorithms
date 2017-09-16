#include <cstdio>
#include <vector>
#include <string>
#pragma warning(disable:4996);

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
	vector<string> answer;

	for (int i = 0; i < n; i++) {
		string s = "";

		
		for (int j = 0; j < arr1.size(); j++) {
			if ((arr1[i] & 1) || arr2[i] & 1)
				s += '#';
			else
				s += ' ';
			arr1[i] >>= 1;
			arr2[i] >>= 1;
		}

		s.reserve();
		answer.push_back(s);
	}

	for (int i = 0; i < answer.size(); i++)
		printf("%s\n", answer[i].c_str());

	return answer;
}

int main() {
	vector<int> arr1;
	vector<int> arr2;

	arr1.push_back(9);
	arr1.push_back(20);
	arr1.push_back(28);
	arr1.push_back(18);
	arr1.push_back(11);

	arr2.push_back(30);
	arr2.push_back(1);
	arr2.push_back(21);
	arr2.push_back(17);
	arr2.push_back(28);

	solution(5, arr1, arr2);
}