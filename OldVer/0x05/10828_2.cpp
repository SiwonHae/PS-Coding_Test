#include <bits/stdc++.h>
using namespace std;

const int MX = 1000005;
int dat[MX];
int pos = 0;

void push(int x) { // 스택에 x 추가
	dat[pos++] = x;
}

void pop() { // 스택의 꼭대기에 위치한 원소 제거
	pos--;
}

int top() { // 스택의 꼭대기에 위치한 원소의 값을 확인
	return dat[pos - 1];
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int N;
	cin >> N;
	stack<int> S;
	
	for (int i = 0; i < N; i++) {
		string command;
		cin >> command;
		
		if (command == "push") {
			int init;
			cin >> init;
			push(init);
		} else if (command == "pop") {
			if (pos == 0) {
				cout << "-1" << '\n';
			} else {
				cout << top() << '\n';
				pop();
			}
		} else if (command == "size") {
			cout << pos << '\n';
		} else if (command == "empty") {
			if (pos == 0) {
				cout << '1' << '\n';
			} else {
				cout << '0' << '\n';
			}
		} else {
			if (pos == 0) {
				cout << "-1" << '\n';
			} else {
				cout << top() << '\n';
			}
		}
	}
	
	return 0;
}