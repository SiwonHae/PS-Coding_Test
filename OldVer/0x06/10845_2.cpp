#include <bits/stdc++.h>
using namespace std;

const int MX = 1000005;
int dat[MX];
int head = 0, tail = 0;

void push(int x) {
	dat[tail++] = x;
}

void pop() {
	head++;
}

int front() {
	return dat[head];
}

int back() {
	return dat[tail - 1];
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int N;
	cin >> N;
	
	while (N--) {
		string command;
		cin >> command;
		
		if (command == "push") {
			int init;
			cin >> init;
			push(init);
		} else if (command == "pop") {
			if (tail == head) {
				cout << "-1" << '\n';
			} else {
				cout << front() << '\n';
				pop();
			}
		} else if (command == "size") {
			cout << tail - head << '\n';
		} else if (command == "empty") {
			if (tail == head) {
				cout << '1' << '\n';
			} else {
				cout << '0' << '\n';
			}
		} else if (command == "front") {
			if (tail == head) {
				cout << "-1" << '\n';
			} else {
				cout << front() << '\n';
			}
		} else {
			if (tail == head) {
				cout << "-1" << '\n';
			} else {
				cout << back() << '\n';
			}
		}
	}
	
	return 0;
}