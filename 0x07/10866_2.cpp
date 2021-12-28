#include <bits/stdc++.h>
using namespace std;

const int MX = 1000005;
int dat[2 * MX + 1];
int head = MX, tail = MX;

void push_front(int x) {
	dat[--head] = x;
}

void push_back(int x) {
	dat[tail++] = x;
}

void pop_front() {
	head++;
}

void pop_back() {
	tail--;
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
		
		if (command == "push_front") {
			int init;
			cin >> init;
			push_front(init);
		} else if (command == "push_back") {
			int init;
			cin >> init;
			push_back(init);
		} else if (command == "pop_front") {
			if (tail == head) {
				cout << "-1" << '\n';
			} else {
				cout << front() << '\n';
				pop_front();
			}
		} else if (command == "pop_back") {
			if (tail == head) {
				cout << "-1" << '\n';
			} else {
				cout << back() << '\n';
				pop_back();
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
		} else if (command == "back") {
			if (tail == head) {
				cout << "-1" << '\n';
			} else {
				cout << back() << '\n';
			}
		}
	}
	
	return 0;
}