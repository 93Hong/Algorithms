#include <iostream>
#include <string>
#include <stack>
using namespace std;
/////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////
////// BEGIN OF EDIT AREA.
/////////////////////////////////////////////////////////////////////////

stack<int> s1, s2;

//Please use `stack` class only
class Queue {
public:
	/*
	* Description:
	* Time complexity:
	* Space complexity:
	*/
	void enqueue(int v) {
		s1.push(v);
		// TODO implement your codes to here.
	}

	/*
	* Description:
	* Time complexity:
	* Space complexity:
	*/
	int dequeue() {
		// TODO implement your codes to here.
		if (s2.empty()) {
			while (!s1.empty()) {
				s2.push(s1.top());
				s1.pop();
			}
		}

		int ret = s2.top();
		s2.pop();
		return ret;
	}
};

/////////////////////////////////////////////////////////////////////////
////// END OF EDIT AREA.
/////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////
int main(int argc, const char *argv[]) {
	Queue queue;
	string command;
	int count, value;
	cin >> count;
	for (int i = 0; i < count; ++i) {
		cin >> command;
		if (command == "ENQUEUE") {
			cin >> value;
			queue.enqueue(value);
		}
		else if (command == "DEQUEUE") {
			cout << queue.dequeue() << endl;
		}
	}
}
