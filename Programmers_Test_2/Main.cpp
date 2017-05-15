#include<string>
#include<stack>
using namespace std;

stack<char> st;

int solution(string s) {
	int answer = 0;

	for (int i = 0; i < s.length(); i++) {
		if (st.empty())
			st.push(s.at(i));
		else
			if (st.top() == s.at(i))
				st.pop();
			else
				st.push(s.at(i));
	}

	if (st.empty())
		answer = 1;

	return answer;
}