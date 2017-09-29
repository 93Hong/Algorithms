#include<iostream>
#include<vector>

using namespace std;

char ch[4] = { '0', '1', '2', '4' };

string change124(int no)
{
	string answer = "";

	while (no != 0) {
		//answer += tostring(ch[no % 3]);
		printf("%c\n", ch[no % 3]);
		no /= 3;
	}

	return answer;
}

int main()
{
	int testNo = 10;
	string testAnswer = change124(testNo);

	printf("%s\n", testAnswer);
}
