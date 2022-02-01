#include <bits/stdc++.h>
using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int N;
	cin >> N;
	
	deque<int> DQ;
	
	while (N--) {
		string command;
		cin >> command;
		
		if (command == "push_front") {
			int init;
			cin >> init;
			DQ.push_front(init);
		} else if (command == "push_back") {
			int init;
			cin >> init;
			DQ.push_back(init);
		} else if (command == "pop_front") {
			if (DQ.empty()) {
				cout << "-1" << '\n';
			} else {
				cout << DQ.front() << '\n';
				DQ.pop_front();
			}
		} else if (command == "pop_back") {
			if (DQ.empty()) {
				cout << "-1" << '\n';
			} else {
				cout << DQ.back() << '\n';
				DQ.pop_back();
			}
		} else if (command == "size") {
			cout << DQ.size() << '\n';
		} else if (command == "empty") {
			if (DQ.empty()) {
				cout << '1' << '\n';
			} else {
				cout << '0' << '\n';
			}
		} else if (command == "front") {
			if (DQ.empty()) {
				cout << "-1" << '\n';
			} else {
				cout << DQ.front() << '\n';
			}
		} else if (command == "back") {
			if (DQ.empty()) {
				cout << "-1" << '\n';
			} else {
				cout << DQ.back() << '\n';
			}
		}
	}
	
	return 0;
}