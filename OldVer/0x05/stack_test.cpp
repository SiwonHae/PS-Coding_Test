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

void test() {
	push(5); push(4); push(3);
	cout << top() << '\n'; // 3
	pop(); pop();
	cout << top() << '\n'; // 5
	push(10); push(12);
	cout << top() << '\n'; // 12
	pop();
	cout << top() << '\n'; // 10
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	test();
	
	return 0;
}