#include <bits/stdc++.h>
using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int N;
	cin >> N;
	
	queue<int> Q;
	
	while (N--) {
		string command;
		cin >> command;
		
		if (command == "push") {
			int init;
			cin >> init;
			Q.push(init);
		} else if (command == "pop") {
			if (Q.empty()) {
				cout << "-1" << '\n';
			} else {
				cout << Q.front() << '\n';
				Q.pop();
			}
		} else if (command == "size") {
			cout << Q.size() << '\n';
		} else if (command == "empty") {
			if (Q.empty()) {
				cout << '1' << '\n';
			} else {
				cout << '0' << '\n';
			}
		} else if (command == "front") {
			if (Q.empty()) {
				cout << "-1" << '\n';
			} else {
				cout << Q.front() << '\n';
			}
		} else {
			if (Q.empty()) {
				cout << "-1" << '\n';
			} else {
				cout << Q.back() << '\n';
			}
		}
	}
	
	return 0;
}